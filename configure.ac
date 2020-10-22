dnl Copyright (C) 2020  Trevor Woerner <twoerner@gmail.com>
dnl SPDX-License-Identifier: OSL-3.0

AC_PREREQ(2.57)
AC_INIT([libsn3218], 0.1.0, twoerner@gmail.com, libsn3218)
AC_CONFIG_SRCDIR(lib/sn3218.c)
AC_CONFIG_AUX_DIR(cfg)
AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE([serial-tests foreign no-dist-gzip dist-bzip2 1.9])
AM_CONFIG_HEADER(cfg/config.h)
AM_EXTRA_RECURSIVE_TARGETS([buildtest-TESTS])

SUBDIRS="tests lib doc"

dnl **********************************
dnl checks for programs
dnl **********************************
AC_PROG_CC
AC_PROG_CPP
AC_PROG_MAKE_SET
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_LIBTOOL
AC_CHECK_PROG(strip, strip, strip, :)

PKG_CHECK_MODULES([CHECK], [check >= 0.15.2], [HAVE_CHECK=true], [HAVE_CHECK=false])
AM_CONDITIONAL(COND_HAVE_CHECK, test x$HAVE_CHECK = xtrue)
AC_SUBST(HAVE_CHECK)

dnl **********************************
dnl checks for user features
dnl **********************************
AC_MSG_CHECKING(whether we want debugging)
AC_ARG_WITH(debug,
AS_HELP_STRING([--with-debug],[add debugging output]),
[ac_cv_use_debug="true"],
[ac_cv_use_debug="false"])
if test $ac_cv_use_debug = "true"; then
	AC_SUBST(AM_CFLAGS,[-DDEBUG])
	AC_MSG_RESULT(yes)
else
	AC_MSG_RESULT(no)
fi

dnl **********************************
dnl checks for libraries
dnl **********************************
AC_CHECK_LIB(i2c, i2c_smbus_write_block_data, ,AC_MSG_ERROR([Can't find i2c library]), )

dnl **********************************
dnl checks for header files
dnl **********************************
AC_HEADER_STDC
AC_CHECK_HEADERS(stdio.h stdlib.h stdbool.h stdint.h)
AC_CHECK_HEADERS(string.h)
AC_CHECK_HEADERS(sys/types.h sys/stat.h sys/ioctl.h fcntl.h unistd.h)
AC_CHECK_HEADERS(linux/i2c.h linux/i2c-dev.h i2c/smbus.h)

dnl **********************************
dnl checks for typedefs, structs, and
dnl compiler characteristics
dnl **********************************
AC_TYPE_SIZE_T

dnl **********************************
dnl output
dnl **********************************
AC_SUBST(SUBDIRS)
AC_OUTPUT(Makefile
libsn3218.pc
cfg/Makefile
lib/Makefile
tests/Makefile
doc/Makefile)
