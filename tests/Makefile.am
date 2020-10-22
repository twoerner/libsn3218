## Copyright (C) 2020  Trevor Woerner <twoerner@gmail.com>
## SPDX-License-Identifier: OSL-3.0

########################
## tests/Makefile.am
########################
SUBDIRS =

AM_CFLAGS = -Wall -Werror -Wextra -Wconversion -Wreturn-type -Wstrict-prototypes \
	-fprofile-arcs -ftest-coverage -I$(top_srcdir)/lib @CHECK_CFLAGS@
LDADD = $(top_builddir)/lib/libsn3218.la @CHECK_LIBS@

if COND_HAVE_CHECK
TESTS = check_sn3218_init check_sn3218_set1 check_sn3218_setm check_sn3218_unset \
	check_sn3218_fails
check_PROGRAMS = check_sn3218_init check_sn3218_set1 check_sn3218_setm check_sn3218_unset \
	check_sn3218_fails
check_sn3218_init_SOURCES = check_sn3218_init.c
check_sn3218_set1_SOURCES = check_sn3218_set1.c
check_sn3218_setm_SOURCES = check_sn3218_setm.c
check_sn3218_unset_SOURCES = check_sn3218_unset.c
check_sn3218_fails_SOURCES = check_sn3218_fails.c

clean-local::
	$(RM) *.gcda *.gcno
endif
