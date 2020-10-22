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
START_TEST(unset1)
{
	bool ret;
	uint8_t i;
	SN3218_LED_MASK_t leds;

	leds.uint = SN3218_ALL_ON;
	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_all_brightness(1);
	ck_assert(ret);
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);
	for (i=LED1; i<MAXLED; ++i) {
		ret = sn3218__clear_led(i);
		ck_assert(ret);
		usleep(USLEEP);
	}
}
END_TEST

START_TEST(unset2)
{
	bool ret;
	SN3218_LED_MASK_t leds;

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);

	ret = sn3218__set_all_brightness(1);
	ck_assert(ret);

	leds.uint = SN3218_ALL_ON;
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);

	sleep(1);

	leds.uint = 0;
	leds.bits.LED5 = 1;
	leds.bits.LED7 = 1;
	leds.bits.LED10 = 1;
	leds.bits.LED13 = 1;
	ret = sn3218__clear_led_mask(leds);
	ck_assert(ret);
}
END_TEST

START_TEST(unset3)
{
	int i;
	bool ret;
	SN3218_LED_MASK_t leds, ledArr[10];

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);

	ret = sn3218__set_all_brightness(1);
	ck_assert(ret);

	leds.uint = SN3218_ALL_ON;
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);

	ledArr[0].uint = 0x55555;
	ledArr[0].uint = 0xaaaaa;
	ledArr[0].uint = 0xa5a5a;
	ledArr[0].uint = 0x5a5a5;
	ledArr[0].uint = 0x0f0f0;
	ledArr[0].uint = 0xf0f0f;
	ledArr[0].uint = 0x12345;
	ledArr[0].uint = 0x6789a;
	ledArr[0].uint = 0xbcdef;
	ledArr[0].uint = 0xfdb97;

	for (i=0; i<30; ++i) {
		ret = sn3218__clear_led_mask(ledArr[i%10]);
		ck_assert(ret);
		usleep(USLEEP);
		ret = sn3218__set_led_mask(leds);
		ck_assert(ret);
	}
}
END_TEST

START_TEST(unset4)
{
	int i;
	bool ret;
	SN3218_LED_MASK_t leds, ledArr[3];

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);

	ret = sn3218__set_all_brightness(1);
	ck_assert(ret);

	leds.uint = SN3218_ALL_ON;
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);

	ledArr[0].uint = 0x24924;
	ledArr[1].uint = 0x12492;
	ledArr[2].uint = 0x09249;

	for (i=0; i<60; ++i) {
		ret = sn3218__clear_led_mask(ledArr[i%3]);
		ck_assert(ret);
		usleep(USLEEP);
		ret = sn3218__set_led_mask(leds);
		ck_assert(ret);
	}
}
END_TEST

START_TEST(unset5)
{
	int i;
	bool ret;
	SN3218_LED_MASK_t leds;

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);

	ret = sn3218__set_all_brightness(1);
	ck_assert(ret);

	leds.uint = SN3218_ALL_ON;
	ret = sn3218__set_led_mask(leds);
	ck_assert(ret);

	for (i=0; i<100; ++i) {
		ret = sn3218__toggle_led(i%MAXLED);
		ck_assert(ret);
		usleep(USLEEP);
		ret = sn3218__toggle_led(i%MAXLED);
		ck_assert(ret);
		usleep(USLEEP);
	}
}
END_TEST

START_TEST(unset6)
{
	int i;
	bool ret;

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);

	ret = sn3218__set_all_brightness(1);
	ck_assert(ret);

	for (i=0; i<100; ++i) {
		ret = sn3218__toggle_led(i%MAXLED);
		ck_assert(ret);
		usleep(USLEEP);
		ret = sn3218__toggle_led(i%MAXLED);
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
	TCase *tcUnset_p = tcase_create("unset");

	tcase_add_checked_fixture(tcUnset_p, NULL, teardown);
	tcase_set_timeout(tcUnset_p, 0);
	tcase_add_test(tcUnset_p, unset1);
	tcase_add_test(tcUnset_p, unset2);
	tcase_add_test(tcUnset_p, unset3);
	tcase_add_test(tcUnset_p, unset4);
	tcase_add_test(tcUnset_p, unset5);
	tcase_add_test(tcUnset_p, unset6);
	suite_add_tcase(suite_p, tcUnset_p);

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
