libsn3218 - A C library to drive the sn3218
The sn3218 is an 18 channel LED driver that uses an i2c interface.


Introduction
============
I want to play with a Pimoron Automation-HAT[1] that I have attached to a
RaspberryPi3. This add-on board includes a bunch of LEDs that are driven by an
sn3218. The code in this library assumes this setup, but hopefully has been
written generically enough to support any sn3218 on any board.


Building
========
This project has a hard dependency on the i2c-tools library[2].

This project uses the autoconf build system. After a fresh clone remember
to run:
	$ autoreconf -i

I generally build all my code/images with OpenEmbedded/Yocto, therefore my
recipes take care of these details.


Tests
=====
The tests/ subdirectory contains a number of unit tests that can be run by
invoking "make check" after a successful "make". However, many of these tests
expect to be run on a Raspberry Pi with an attached Pimoroni Automation-HAT.
I.e. many of these tests send real i2c commands to a device at address 0x54
and can therefore mess things up should these assumptions not be true. These
tests are built on and require the "check" C unit testing framework[3].
Building will not fail, however, if check is not available.


Info
====
Author: Trevor Woerner



[1] https://shop.pimoroni.com/products/automation-hat
[2] https://i2c.wiki.kernel.org/index.php/I2C_Tools
[3] https://libcheck.github.io/check/
