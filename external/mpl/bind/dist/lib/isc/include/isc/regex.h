/*	$NetBSD: regex.h,v 1.3 2020/05/24 19:46:26 christos Exp $	*/

/*
 * Copyright (C) Internet Systems Consortium, Inc. ("ISC")
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * See the COPYRIGHT file distributed with this work for additional
 * information regarding copyright ownership.
 */

#ifndef ISC_REGEX_H
#define ISC_REGEX_H 1

/*! \file isc/regex.h */

#include <isc/lang.h>
#include <isc/types.h>

ISC_LANG_BEGINDECLS

int
isc_regex_validate(const char *expression);
/*%<
 * Check a regular expression for syntactic correctness.
 *
 * Returns:
 *\li	 -1 on error.
 *\li	 the number of groups in the expression.
 */

ISC_LANG_ENDDECLS

#endif /* ISC_REGEX_H */
