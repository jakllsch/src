# $NetBSD: Makefile,v 1.6 2018/12/31 11:14:05 mrg Exp $

XMODULEDIR=	${X11USRLIBDIR}/modules

.include "../../../Makefile.serverlib"
.include "../../../Makefile.servermod"

LIB=	vbe

.PATH:	${X11SRCDIR.xorg-server}/hw/xfree86/${LIB}
SRCS=	vbe.c vbeModes.c vbe_module.c

CPPFLAGS+=	-I${X11SRCDIR.xorg-server}/hw/xfree86/${LIB} \
		-I${X11SRCDIR.xorg-server}/hw/xfree86/common \
		-I${X11SRCDIR.xorg-server}/Xext \
		-I${X11SRCDIR.xorg-server}/mi \
		-I${X11SRCDIR.xorg-server}/include \
		-I${DESTDIR}${X11INCDIR}/X11 \
		-I${DESTDIR}${X11INCDIR}/pixman-1 \
		-I${DESTDIR}${X11INCDIR}/xorg \
		-I${X11SRCDIR.xorg-server}/hw/xfree86/ddc \
		-I${X11SRCDIR.xorg-server}/hw/xfree86/i2c \
		-I${X11SRCDIR.xorg-server}/hw/xfree86/parser \
		-I${X11SRCDIR.xorg-server}/hw/xfree86/int10 \
		-I${X11SRCDIR.xorg-server}/../include

# XXX
COPTS.vbe.c=	-Wno-error

.include <bsd.x11.mk>
LIBDIR=	${XMODULEDIR}
.include <bsd.lib.mk>
