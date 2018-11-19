#ifndef COMPAT_H
#define COMPAT_H

#if PG_VERSION_NUM > 90415
#include "fe_utils/connect.h"
#else
/*
 * This SQL statement installs an always-secure search path, so malicious
 * users can't take control.  CREATE of an unqualified name will fail, because
 * this selects no creation schema.  This does not demote pg_temp, so it is
 * suitable where we control the entire FE/BE connection but not suitable in
 * SECURITY DEFINER functions.  This is portable to PostgreSQL 7.3, which
 * introduced schemas.  When connected to an older version from code that
 * might work with the old server, skip this.
 */
#define ALWAYS_SECURE_SEARCH_PATH_SQL \
       "SELECT pg_catalog.set_config('search_path', '', false)"
#endif

#if !defined(pg_attribute_printf)

/* GCC and XLC support format attributes */
#if defined(__GNUC__) || defined(__IBMC__)
#define pg_attribute_format_arg(a) __attribute__((format_arg(a)))
#define pg_attribute_printf(f,a) __attribute__((format(PG_PRINTF_ATTRIBUTE, f, a)))
#else
#define pg_attribute_format_arg(a)
#define pg_attribute_printf(f,a)
#endif

#endif

#endif
