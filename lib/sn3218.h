/*
 * Copyright (C) 2020  Trevor Woerner <twoerner@gmail.com>
 * SPDX-License-Identifier: OSL-3.0
 */

#ifndef __SN3218__H
#define __SN3218__H

#include <stdbool.h>
#include <stdint.h>

typedef enum {
	LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8, LED9,
	LED10, LED11, LED12, LED13, LED14, LED15, LED16, LED17, LED18,
	MAXLED,
} SN3218_LED_e;

typedef union {
	struct {
		unsigned LED1 : 1;
		unsigned LED2 : 1;
		unsigned LED3 : 1;
		unsigned LED4 : 1;
		unsigned LED5 : 1;
		unsigned LED6 : 1;
		unsigned LED7 : 1;
		unsigned LED8 : 1;
		unsigned LED9 : 1;
		unsigned LED10: 1;
		unsigned LED11: 1;
		unsigned LED12: 1;
		unsigned LED13: 1;
		unsigned LED14: 1;
		unsigned LED15: 1;
		unsigned LED16: 1;
		unsigned LED17: 1;
		unsigned LED18: 1;
	} bits;
	uint32_t uint;
} SN3218_LED_MASK_t;
#define SN3218_ALL_ON 0x3ffff

bool sn3218__init(const char *dev_p, bool resetOnStart, bool resetOnExit);

bool sn3218__set_led(SN3218_LED_e led);
bool sn3218__set_led_mask(SN3218_LED_MASK_t mask);
bool sn3218__clear_led(SN3218_LED_e led);
bool sn3218__clear_led_mask(SN3218_LED_MASK_t mask);
bool sn3218__toggle_led(SN3218_LED_e led);

bool sn3218__set_led_brightness(SN3218_LED_e led, uint8_t val);
bool sn3218__set_all_brightness(uint8_t val);

#endif // __SN3218__H
