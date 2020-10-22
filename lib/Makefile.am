## Copyright (C) 2020  Trevor Woerner <twoerner@gmail.com>
## SPDX-License-Identifier: OSL-3.0

########################
## lib/Makefile.am
########################
SUBDIRS =
AM_CFLAGS = -Wall -Werror -Wextra -Wconversion -Wreturn-type -Wstrict-prototypes
pkginclude_HEADERS = sn3218.h

########################
## shared lib
########################
lib_LTLIBRARIES = libsn3218.la
libsn3218_la_SOURCES = sn3218.c sn3218.h
libsn3218_la_LDFLAGS =  -release @VERSION@
libsn3218_la_LDFLAGS += -version-info 0:1:0
## C:R:A
## any code change       -> inc(R)
## interface add/del/chg -> R=0, inc(C)
## interface added       -> inc(A)
## interfece removed     -> A=0
