/* $NetBSD: fdt_phy.c,v 1.6 2019/10/30 21:37:36 jmcneill Exp $ */

/*-
 * Copyright (c) 2015-2017 Jared McNeill <jmcneill@invisible.ca>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: fdt_phy.c,v 1.6 2019/10/30 21:37:36 jmcneill Exp $");

#include <sys/param.h>
#include <sys/bus.h>
#include <sys/kmem.h>
#include <sys/queue.h>

#include <libfdt.h>
#include <dev/fdt/fdtvar.h>

struct fdtbus_phy_controller {
	device_t pc_dev;
	int pc_phandle;
	const struct fdtbus_phy_controller_func *pc_funcs;

	LIST_ENTRY(fdtbus_phy_controller) pc_next;
};

static LIST_HEAD(, fdtbus_phy_controller) fdtbus_phy_controllers =
    LIST_HEAD_INITIALIZER(fdtbus_phy_controllers);

int
fdtbus_register_phy_controller(device_t dev, int phandle,
    const struct fdtbus_phy_controller_func *funcs)
{
	struct fdtbus_phy_controller *pc;

	pc = kmem_alloc(sizeof(*pc), KM_SLEEP);
	pc->pc_dev = dev;
	pc->pc_phandle = phandle;
	pc->pc_funcs = funcs;

	LIST_INSERT_HEAD(&fdtbus_phy_controllers, pc, pc_next);

	return 0;
}

static struct fdtbus_phy_controller *
fdtbus_get_phy_controller(int phandle)
{
	struct fdtbus_phy_controller *pc;

	LIST_FOREACH(pc, &fdtbus_phy_controllers, pc_next) {
		if (pc->pc_phandle == phandle)
			return pc;
	}

	return NULL;
}

struct fdtbus_phy *
fdtbus_phy_get_index(int phandle, u_int index)
{
	struct fdtbus_phy_controller *pc;
	struct fdtbus_phy *phy = NULL;
	void *phy_priv = NULL;
	uint32_t *phys = NULL;
	uint32_t *p;
	u_int n, phy_cells;
	int len, resid;

	len = OF_getproplen(phandle, "phys");
	if (len <= 0)
		return NULL;

	phys = kmem_alloc(len, KM_SLEEP);
	if (OF_getprop(phandle, "phys", phys, len) != len) {
		kmem_free(phys, len);
		return NULL;
	}

	p = phys;
	for (n = 0, resid = len; resid > 0; n++) {
		if (p[0] == 0) {
			phy_cells = 0;
			goto next;
		}
		const int pc_phandle =
		    fdtbus_get_phandle_from_native(be32toh(p[0]));
		if (of_getprop_uint32(pc_phandle, "#phy-cells", &phy_cells))
			break;
		if (n == index) {
			pc = fdtbus_get_phy_controller(pc_phandle);
			if (pc == NULL)
				goto done;
			phy_priv = pc->pc_funcs->acquire(pc->pc_dev,
			    phy_cells > 0 ? &p[1] : NULL, phy_cells * 4);
			if (phy_priv) {
				phy = kmem_alloc(sizeof(*phy), KM_SLEEP);
				phy->phy_pc = pc;
				phy->phy_priv = phy_priv;
			}
			break;
		}
next:
		resid -= (phy_cells + 1) * 4;
		p += phy_cells + 1;
	}

done:
	if (phys)
		kmem_free(phys, len);

	return phy;
}

struct fdtbus_phy *
fdtbus_phy_get(int phandle, const char *phyname)
{
	u_int index;
	int err;

	err = fdtbus_get_index(phandle, "phy-names", phyname, &index);
	if (err != 0)
		return NULL;

	return fdtbus_phy_get_index(phandle, index);
}

void
fdtbus_phy_put(struct fdtbus_phy *phy)
{
	struct fdtbus_phy_controller *pc = phy->phy_pc;

	pc->pc_funcs->release(pc->pc_dev, phy->phy_priv);
	kmem_free(phy, sizeof(*phy));
}

device_t
fdtbus_phy_device(struct fdtbus_phy *phy)
{
	return phy->phy_pc->pc_dev;
}

int
fdtbus_phy_enable(struct fdtbus_phy *phy, bool enable)
{
	struct fdtbus_phy_controller *pc = phy->phy_pc;

	return pc->pc_funcs->enable(pc->pc_dev, phy->phy_priv, enable);
}
