/*
 * Copyright (C) 2020  Trevor Woerner <twoerner@gmail.com>
 * SPDX-License-Identifier: OSL-3.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>

#include "sn3218.h"
#include "config.h"

#define SN3218_I2C_ADDR 0x54

#define SN3218_REG__SHUTDOWN 0x00
#define SN3218_REG__PWM_LED01 0x01
#define SN3218_REG__PWM_LED02 0x02
#define SN3218_REG__PWM_LED03 0x03
#define SN3218_REG__PWM_LED04 0x04
#define SN3218_REG__PWM_LED05 0x05
#define SN3218_REG__PWM_LED06 0x06
#define SN3218_REG__PWM_LED07 0x07
#define SN3218_REG__PWM_LED08 0x08
#define SN3218_REG__PWM_LED09 0x09
#define SN3218_REG__PWM_LED10 0x0a
#define SN3218_REG__PWM_LED11 0x0b
#define SN3218_REG__PWM_LED12 0x0c
#define SN3218_REG__PWM_LED13 0x0d
#define SN3218_REG__PWM_LED14 0x0e
#define SN3218_REG__PWM_LED15 0x0f
#define SN3218_REG__PWM_LED16 0x10
#define SN3218_REG__PWM_LED17 0x11
#define SN3218_REG__PWM_LED18 0x12
#define SN3218_REG__LED_CTL_1 0x13
#define SN3218_REG__LED_CTL_2 0x14
#define SN3218_REG__LED_CTL_3 0x15
#define SN3218_REG__UPDATE 0x16
#define SN3218_REG__RESET 0x17
#define TOTAL_REGS 0x18

static bool freeDeviceString_G = false;
static char *i2cDevice_pG = "/dev/i2c-1";
static int i2cFd_G = 0;
static bool libInit_G = false;
static uint8_t currentRegVals[TOTAL_REGS];

static void
reset_device(void)
{
	if (i2cFd_G <= 0)
		return;

	i2c_smbus_write_byte_data(i2cFd_G, SN3218_REG__SHUTDOWN, 0x00);
	i2c_smbus_write_byte_data(i2cFd_G, SN3218_REG__RESET, 0xff);
}

static void
sn3218__cleanup(void)
{
	// preconds
	if (!libInit_G)
		return;

	if (freeDeviceString_G)
		free(i2cDevice_pG);
	if (i2cFd_G > 0)
		close(i2cFd_G);
}

bool
sn3218__init(const char *dev_p, bool resetOnStart, bool resetOnExit)
{
	int ret;
	unsigned long funcs;

	// open i2c device
	if (dev_p != NULL) {
		i2cDevice_pG = strdup(dev_p);
		if (i2cDevice_pG == NULL) {
			perror("strdup()");
			return false;
		}
		freeDeviceString_G = true;
	}
	i2cFd_G = open(i2cDevice_pG, O_RDWR);
	if (i2cFd_G < 0) {
		perror("open(i2c device)");
		return false;
	}

	// check/verify i2c functionality on device
	ret = ioctl(i2cFd_G, I2C_FUNCS, &funcs);
	if (ret < 0) {
		perror("can't get i2c functionality");
		close(i2cFd_G);
		return false;
	}
	if (!(funcs & I2C_FUNC_SMBUS_WRITE_BYTE_DATA)) {
		fprintf(stderr, "I2C_FUNC_SMBUS_WRITE_BYTE_DATA not available\n");
		close(i2cFd_G);
		return false;
	}
	if (!(funcs & I2C_FUNC_SMBUS_WRITE_I2C_BLOCK)) {
		fprintf(stderr, "I2C_FUNC_SMBUS_WRITE_I2C_BLOCK not available\n");
		close(i2cFd_G);
		return false;
	}

	// set device
	ret = ioctl(i2cFd_G, I2C_SLAVE, SN3218_I2C_ADDR);
	if (ret < 0) {
		perror("I2C_SLAVE");
		close(i2cFd_G);
		return false;
	}

	// resets
	atexit(sn3218__cleanup);
	if (resetOnStart)
		reset_device();
	if (resetOnExit)
		atexit(reset_device);

	memset(currentRegVals, 0, sizeof(currentRegVals));
	i2c_smbus_write_byte_data(i2cFd_G, SN3218_REG__SHUTDOWN, 0x01);
	libInit_G = true;
	return true;
}

static uint8_t
get_led_ctrl_reg(SN3218_LED_e led)
{
	if ((led >= LED1) && (led <= LED6))
		return SN3218_REG__LED_CTL_1;
	if ((led >= LED7) && (led <= LED12))
		return SN3218_REG__LED_CTL_2;
	return SN3218_REG__LED_CTL_3;
}

static uint8_t
get_led_reg_bit(SN3218_LED_e led)
{
	if ((led >= LED1) && (led <= LED6))
		return (uint8_t)(0x01 << led);
	if ((led >= LED7) && (led <= LED12))
		return (uint8_t)(0x01 << (led - LED7));
	return (uint8_t)(0x01 << (led - LED13));
}

bool
sn3218__set_led(SN3218_LED_e led)
{
	uint8_t reg, mask;

	// preconds
	if (led >= MAXLED)
		return false;
	if (i2cFd_G <= 0)
		return false;
	if (!libInit_G)
		return false;

	reg = get_led_ctrl_reg(led);
	mask = get_led_reg_bit(led);

	currentRegVals[reg] |= mask;

	i2c_smbus_write_byte_data(i2cFd_G, reg, currentRegVals[reg]);
	i2c_smbus_write_byte_data(i2cFd_G, SN3218_REG__UPDATE, 0xff);

	return true;
}

bool
sn3218__set_led_mask(SN3218_LED_MASK_t mask)
{
	uint8_t data[3];

	// preconds
	if (i2cFd_G <= 0)
		return false;
	if (!libInit_G)
		return false;

	// turn off any undefined bits
	mask.uint &= SN3218_ALL_ON;

	data[0] = (uint8_t)(mask.uint & 0x0000003f);
	currentRegVals[SN3218_REG__LED_CTL_1] |= data[0];
	data[1] = (uint8_t)((mask.uint & 0x00000fc0) >> 6);
	currentRegVals[SN3218_REG__LED_CTL_2] |= data[1];
	data[2] = (uint8_t)((mask.uint & 0x0003f000) >> 12);
	currentRegVals[SN3218_REG__LED_CTL_3] |= data[2];
	i2c_smbus_write_i2c_block_data(i2cFd_G, SN3218_REG__LED_CTL_1, 3, data);
	i2c_smbus_write_byte_data(i2cFd_G, SN3218_REG__UPDATE, 0xff);
	return true;
}

bool
sn3218__clear_led(SN3218_LED_e led)
{
	uint8_t reg, mask;

	// preconds
	if (led >= MAXLED)
		return false;
	if (i2cFd_G <= 0)
		return false;
	if (!libInit_G)
		return false;

	reg = get_led_ctrl_reg(led);
	mask = get_led_reg_bit(led);

	currentRegVals[reg] &= (uint8_t)~mask;

	i2c_smbus_write_byte_data(i2cFd_G, reg, currentRegVals[reg]);
	i2c_smbus_write_byte_data(i2cFd_G, SN3218_REG__UPDATE, 0xff);

	return true;
}

bool
sn3218__clear_led_mask(SN3218_LED_MASK_t mask)
{
	mask.uint = (~mask.uint) & SN3218_ALL_ON;
	return sn3218__set_led_mask(mask);
}

bool
sn3218__toggle_led(SN3218_LED_e led)
{
	uint8_t reg, mask;

	// preconds
	if (led >= MAXLED)
		return false;
	if (i2cFd_G <= 0)
		return false;
	if (!libInit_G)
		return false;

	reg = get_led_ctrl_reg(led);
	mask = get_led_reg_bit(led);
	if (currentRegVals[reg] & mask)
		return sn3218__clear_led(led);
	return sn3218__set_led(led);
}

bool
sn3218__set_led_brightness(SN3218_LED_e led, uint8_t val)
{
	uint8_t reg;

	// preconds
	if (led >= MAXLED)
		return false;
	if (i2cFd_G <= 0)
		return false;
	if (!libInit_G)
		return false;

	reg = (uint8_t)(led + 1);
	i2c_smbus_write_byte_data(i2cFd_G, reg, val);
	i2c_smbus_write_byte_data(i2cFd_G, SN3218_REG__UPDATE, 0xff);
	return true;
}

bool
sn3218__set_all_brightness(uint8_t val)
{
	uint8_t i, data[32], dataPtr = 0;

	// preconds
	if (i2cFd_G <= 0)
		return false;
	if (!libInit_G)
		return false;

	dataPtr = 0;
	for (i=0; i<SN3218_REG__PWM_LED18; ++i)
		data[dataPtr++] = val;
	i2c_smbus_write_i2c_block_data(i2cFd_G, SN3218_REG__PWM_LED01, dataPtr, data);
	i2c_smbus_write_byte_data(i2cFd_G, SN3218_REG__UPDATE, 0xff);
	return true;
}
