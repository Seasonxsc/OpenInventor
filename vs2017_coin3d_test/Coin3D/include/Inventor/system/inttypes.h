/* include/Inventor/system/inttypes.h.  Generated by configure.  */
#ifndef COIN_INTTYPES_H
#define COIN_INTTYPES_H

/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) by Kongsberg Oil & Gas Technologies.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Kongsberg Oil & Gas Technologies
 *  about acquiring a Coin Professional Edition License.
 *
 *  See http://www.coin3d.org/ for more information.
 *
 *  Kongsberg Oil & Gas Technologies, Bygdoy Alle 5, 0257 Oslo, NORWAY.
 *  http://www.sim.no/  sales@sim.no  coin-support@coin3d.org
 *
\**************************************************************************/

/*
  This file defines the following types:

    int8_t uint8_t
    int16_t uint16_t
    int32_t uint32_t
    int64_t uint64_t
    intptr_t uintptr_t

  (The 64-bit types are not guaranteed to be present, check for
  HAVE_INT64_T and HAVE_UINT64_T.)
*/

/***************************************************************************/

/* Block of defines set up by the configure script. Protected with the
   #ifndef wrapper in case config.h was already included -- so we
   don't confuse the compiler to think we redefine already #define'd
   constants. */
#ifndef COIN_CONFIGURE_BUILD /* (start wrapper) */

/*
  This file was autogenerated by our configuration process
  specifically for this build configuration:
*/
#define COIN_CONFIGURE_BUILD I686_PC_CYGWIN
#define COIN_CONFIGURE_HOST I686_PC_CYGWIN
#define COIN_CONFIGURE_TARGET I686_PC_CYGWIN
/*
  The bit-type definitions may also be dependent on the compiler,
  compiler version and C library.

  So note that the bit-type definitions below might not match on other
  systems. Be extremely careful if you for whatever reason is
  installing this as a cross-platform header file (i.e.: you
  shouldn't).
*/

/* FIXME: isn't it likely that the HAVE_*_H defines below could crash
   with defines in application code in a project using Autoconf
   configure?  20010711 mortene. */

/* The <inttypes.h> header file. */
/* #undef HAVE_INTTYPES_H */
/* The <stdint.h> header file. */
/* #undef HAVE_STDINT_H */
/* The <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1
/* The <stddef.h> header file. */
#define HAVE_STDDEF_H 1


/* If the system defines any of the types "on it's own", the
   respective #define will be set below. */
/* #undef HAVE_INT8_T */
//#define HAVE_INT8_T 1

/* #undef HAVE_UINT8_T */
/* #undef HAVE_INT16_T */
/* #undef HAVE_UINT16_T */
/* #undef HAVE_INT32_T */
/* #undef HAVE_UINT32_T */
/* #undef HAVE_INT64_T */
/* #undef HAVE_UINT64_T */
#define HAVE_INTPTR_T 1
#define HAVE_UINTPTR_T 1

/* The type which the configure script found to match the given
   bitwidth. */
#define COIN_INT8_T signed char
#define COIN_UINT8_T unsigned char
#define COIN_INT16_T short
#define COIN_UINT16_T unsigned short
#define COIN_INT32_T int
#define COIN_UINT32_T unsigned int
#define COIN_INT64_T long long
#define COIN_UINT64_T unsigned long long
#define COIN_INTPTR_T intptr_t
#define COIN_UINTPTR_T uintptr_t

#endif /* (end wrapper) ! COIN_CONFIGURE_BUILD */


/* The header files should be listed in the same order as they are in
   the SIM_AC_DEFINE_BYTESIZE_TYPES detection macro. This is the same
   order as the one Autoconf (currently upcoming 2.51) is using for its
   standard includes.  20010711 larsa */
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#else
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif /* HAVE_STDINT_H */
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif /* HAVE_SYS_TYPES_H */
#ifdef HAVE_STDDEF_H
#include <stddef.h>
#endif /* HAVE_STDDEF_H */


//#if !defined(HAVE_INT8_T) && defined(COIN_INT8_T)
typedef COIN_INT8_T int8_t;
#define HAVE_INT8_T 1
//#endif /* !HAVE_INT8_T && COIN_INT8_T */

#if !defined(HAVE_UINT8_T) && defined(COIN_UINT8_T)
typedef COIN_UINT8_T uint8_t;
#define HAVE_UINT8_T 1
#endif /* !HAVE_UINT8_T && COIN_UINT8_T */

#if !defined(HAVE_INT16_T) && defined(COIN_INT16_T)
typedef COIN_INT16_T int16_t;
#define HAVE_INT16_T 1
#endif /* !HAVE_INT16_T && COIN_INT16_T */

#if !defined(HAVE_UINT16_T) && defined(COIN_UINT16_T)
typedef COIN_UINT16_T uint16_t;
#define HAVE_UINT16_T 1
#endif /* !HAVE_UINT16_T && COIN_UINT16_T */

#if !defined(HAVE_INT32_T) && defined(COIN_INT32_T)
typedef COIN_INT32_T int32_t;
#define HAVE_INT32_T 1
#endif /* !HAVE_INT32_T && COIN_INT32_T */

#if !defined(HAVE_UINT32_T) && defined(COIN_UINT32_T)
typedef COIN_UINT32_T uint32_t;
#define HAVE_UINT32_T 1
#endif /* !HAVE_UINT32_T && COIN_UINT32_T */

#if !defined(HAVE_INT64_T) && defined(COIN_INT64_T)
typedef COIN_INT64_T int64_t;
#define HAVE_INT64_T 1
#endif /* !HAVE_INT64_T && COIN_INT64_T */

#if !defined(HAVE_UINT64_T) && defined(COIN_UINT64_T)
typedef COIN_UINT64_T uint64_t;
#define HAVE_UINT64_T 1
#endif /* !HAVE_UINT64_T && COIN_UINT64_T */

#if !defined(HAVE_INTPTR_T) && defined(COIN_INTPTR_T)
typedef COIN_INTPTR_T intptr_t;
#define HAVE_INTPTR_T 1
#endif /* !HAVE_INTPTR_T && COIN_INTPTR_T */

#if !defined(HAVE_UINTPTR_T) && defined(COIN_UINTPTR_T)
typedef COIN_UINTPTR_T uintptr_t;
#define HAVE_UINTPTR_T 1
#endif /* !HAVE_UINTPTR_T && COIN_UINTPTR_T */

#endif /* !COIN_INTTYPES_H */
