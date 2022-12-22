#
# USB PalmSecure Sensor driver (kernel-2.6) Makefile
#
# Copyright (C) 2012 FUJITSU FRONTECH LIMITED
#
#	This program is free software; you can redistribute it and/or
#	modify it under the terms of the GNU General Public License version
#	2 as published by the Free Software Foundation.
#
# Notes:
#
#

VERSION  := $(shell uname -r)
KERNDIR = # PATH TO YOUR KERNEL BUILD 
INSTALLDIR = /lib/modules/$(VERSION)/misc
BUILD_DIR := $(shell pwd)
VERBOSE = 0
TARGET = fjveincam

RM      = rm -f

obj-m = ${TARGET}.o


all:
	@if test -f $(KERNDIR)/Makefile; \
	then \
		make -C $(KERNDIR) SUBDIRS=$(BUILD_DIR) KBUILD_VERBOSE=$(VERBOSE) modules; \
	else \
		echo Path \"$(KERNDIR)\"" not found."; \
		echo "You have to configure your Makefile." ; \
		echo "And, set your target kernel source path to KERNDIR." ; \
	fi;

install:
	install -d $(INSTALLDIR)
	install -m 644 -g root -o root ${TARGET}.ko $(INSTALLDIR)

clean:
	$(RM) ${TARGET}.*o ${TARGET}.mod.c ${TARGET}.mod.o .${TARGET}.* *~
	$(RM) Module.symvers modules.order
	$(RM) -r .tmp_versions

