/*
 * Copyright (C) 2020  Trevor Woerner <twoerner@gmail.com>
 * SPDX-License-Identifier: OSL-3.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <check.h>
#include "sn3218.h"

#define USLEEP 100000
START_TEST(setm_1)
{
	bool ret;
	uint8_t i;

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_all_brightness(1);
	ck_assert(ret);
	for (i=0; i<18; ++i) {
		ret = sn3218__set_led(i);
		ck_assert(ret);
		usleep(USLEEP);
	}
}
END_TEST

START_TEST(setm_2)
{
	bool ret;
	uint8_t i;

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_all_brightness(3);
	ck_assert(ret);
	ret = sn3218__set_led(LED18);
	ck_assert(ret);
	for (i=0; i<18; ++i) {
		ret = sn3218__set_led(i);
		ck_assert(ret);
		usleep(USLEEP);
	}
}
END_TEST

START_TEST(setm_3)
{
	bool ret;
	SN3218_LED_MASK_t leds;

	leds.uint = 0;
	leds.bits.LED1 = 1;
	leds.bits.LED16 = 1;

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_all_brightness(3);
	ck_assert(ret);
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);
}
END_TEST

START_TEST(setm_4)
{
	bool ret;
	SN3218_LED_MASK_t leds;

	leds.uint = 0;
	leds.bits.LED1 = 1;
	leds.bits.LED3 = 1;
	leds.bits.LED5 = 1;
	leds.bits.LED7 = 1;
	leds.bits.LED9 = 1;
	leds.bits.LED11 = 1;
	leds.bits.LED13 = 1;
	leds.bits.LED15 = 1;
	leds.bits.LED17 = 1;

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_all_brightness(3);
	ck_assert(ret);
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);
}
END_TEST

START_TEST(setm_5)
{
	bool ret;
	SN3218_LED_MASK_t leds;

	leds.uint = 0;
	leds.bits.LED2 = 1;
	leds.bits.LED4 = 1;
	leds.bits.LED6 = 1;
	leds.bits.LED8 = 1;
	leds.bits.LED10 = 1;
	leds.bits.LED12 = 1;
	leds.bits.LED14 = 1;
	leds.bits.LED16 = 1;
	leds.bits.LED18 = 1;

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_all_brightness(3);
	ck_assert(ret);
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);
}
END_TEST

START_TEST(setm_6)
{
	bool ret;
	SN3218_LED_MASK_t leds;

	leds.uint = 0;
	leds.uint = 0x3ffff;
	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_all_brightness(3);
	ck_assert(ret);
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);
}
END_TEST

START_TEST(setm_7)
{
	bool ret;
	SN3218_LED_MASK_t leds;

	leds.uint = 0;
	leds.uint = 0x15a5a;
	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_all_brightness(3);
	ck_assert(ret);
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);
}
END_TEST

START_TEST(setm_8)
{
	bool ret;
	SN3218_LED_MASK_t leds;

	leds.uint = 0;
	leds.uint = 0x2a5a5;
	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_all_brightness(3);
	ck_assert(ret);
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);
}
END_TEST

START_TEST(setm_9)
{
	bool ret;
	SN3218_LED_MASK_t leds;

	leds.uint = 0;
	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_all_brightness(3);
	ck_assert(ret);
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);
}
END_TEST

START_TEST(setm_10)
{
	bool ret;
	SN3218_LED_MASK_t leds;
	volatile uint8_t i, j;

	leds.uint = SN3218_ALL_ON;
	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);
	for (i=0; i<4; ++i) {
		for (j=0; j<20; ++j) {
			ret = sn3218__set_all_brightness(j);
			ck_assert(ret);
			usleep(USLEEP);
		}
		for (j=20; j>0; --j) {
			ret = sn3218__set_all_brightness(j);
			ck_assert(ret);
			usleep(USLEEP);
		}
	}
}
END_TEST

START_TEST(setm_11)
{
	bool ret;
	SN3218_LED_MASK_t leds;

	leds.uint = SN3218_ALL_ON;
	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);
	ret = sn3218__set_all_brightness(1);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED14, 12);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED8, 3);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED2, 7);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED7, 10);
	ck_assert(ret);
}
END_TEST

START_TEST(setm_12)
{
	int i;
	bool ret;
	SN3218_LED_MASK_t ledArr[3];

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);

	ret = sn3218__set_all_brightness(1);
	ck_assert(ret);

	ledArr[0].uint = 0x24924;
	ledArr[1].uint = 0x12492;
	ledArr[2].uint = 0x09249;

	for (i=0; i<100; ++i) {
		ret = sn3218__set_led_mask(ledArr[i%3]);
		ck_assert(ret);
		usleep(USLEEP);
	}
}
END_TEST

void
teardown(void)
{
	sleep(2);
}

Suite*
sn3218_suite(void)
{
	Suite *suite_p = suite_create("sn3218");
	TCase *tcSetM_p = tcase_create("setM");

	tcase_add_checked_fixture(tcSetM_p, NULL, teardown);
	tcase_set_timeout(tcSetM_p, 0);
	tcase_add_test(tcSetM_p, setm_1);
	tcase_add_test(tcSetM_p, setm_2);
	tcase_add_test(tcSetM_p, setm_3);
	tcase_add_test(tcSetM_p, setm_4);
	tcase_add_test(tcSetM_p, setm_5);
	tcase_add_test(tcSetM_p, setm_6);
	tcase_add_test(tcSetM_p, setm_7);
	tcase_add_test(tcSetM_p, setm_8);
	tcase_add_test(tcSetM_p, setm_9);
	tcase_add_test(tcSetM_p, setm_6);
	tcase_add_test(tcSetM_p, setm_10);
	tcase_add_test(tcSetM_p, setm_11);
	tcase_add_test(tcSetM_p, setm_9);
	tcase_add_test(tcSetM_p, setm_12);
	suite_add_tcase(suite_p, tcSetM_p);

	return suite_p;
}

int
main(void)
{
	int f1;
	SRunner *suiteRun_p;

	suiteRun_p = srunner_create(sn3218_suite());
	srunner_run_all(suiteRun_p, CK_VERBOSE);
	f1 = srunner_ntests_failed(suiteRun_p);
	srunner_free(suiteRun_p);

	return (f1 == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
