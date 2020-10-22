/*
 * Copyright (C) 2020  Trevor Woerner <twoerner@gmail.com>
 * SPDX-License-Identifier: OSL-3.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <check.h>
#include "sn3218.h"

START_TEST(fail1)
{
	bool ret;

	ret = sn3218__set_all_brightness(1);
	ck_assert(!ret);
}
END_TEST

START_TEST(fail2)
{
	bool ret;

	ret = sn3218__init("/dev/trevor", true, true);
	ck_assert(!ret);
}
END_TEST

START_TEST(fail3)
{
	bool ret;

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_led(MAXLED);
	ck_assert(!ret);
	ret = sn3218__set_led(MAXLED + 10);
	ck_assert(!ret);
}
END_TEST

START_TEST(fail4)
{
	bool ret;

	ret = sn3218__set_led(LED1);
	ck_assert(!ret);
}
END_TEST

START_TEST(fail5)
{
	bool ret;
	SN3218_LED_MASK_t mask;

	mask.uint = 1;
	ret = sn3218__set_led_mask(mask);
	ck_assert(!ret);
}
END_TEST

START_TEST(fail6)
{
	bool ret;

	ret = sn3218__clear_led(LED1);
	ck_assert(!ret);
}
END_TEST

START_TEST(fail7)
{
	bool ret;

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__clear_led(MAXLED);
	ck_assert(!ret);
	ret = sn3218__clear_led(MAXLED+10);
	ck_assert(!ret);
}
END_TEST

START_TEST(fail8)
{
	bool ret;

	ret = sn3218__init("/dev/ttyS0", true, true);
	ck_assert(!ret);
}
END_TEST

START_TEST(fail9)
{
	bool ret;
	SN3218_LED_MASK_t mask;

	mask.uint = 1;
	ret = sn3218__clear_led_mask(mask);
	ck_assert(!ret);
}
END_TEST

START_TEST(fail10)
{
	bool ret;

	ret = sn3218__toggle_led(LED1);
	ck_assert(!ret);
}
END_TEST

START_TEST(fail11)
{
	bool ret;

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__toggle_led(MAXLED);
	ck_assert(!ret);
	ret = sn3218__toggle_led(MAXLED+10);
	ck_assert(!ret);
}
END_TEST

START_TEST(fail12)
{
	bool ret;

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(MAXLED, 5);
	ck_assert(!ret);
	ret = sn3218__set_led_brightness(MAXLED+10, 5);
	ck_assert(!ret);
}
END_TEST

START_TEST(fail13)
{
	bool ret;

	ret = sn3218__set_led_brightness(LED1, 1);
	ck_assert(!ret);
}
END_TEST

START_TEST(fail14)
{
	bool ret;

	ret = sn3218__set_all_brightness(5);
	ck_assert(!ret);
}
END_TEST

Suite*
sn3218_suite(void)
{
	Suite *suite_p = suite_create("sn3218");
	TCase *tcFail_p = tcase_create("fail");

	tcase_set_timeout(tcFail_p, 0);
	tcase_add_test(tcFail_p, fail1);
	tcase_add_test(tcFail_p, fail2);
	tcase_add_test(tcFail_p, fail3);
	tcase_add_test(tcFail_p, fail4);
	tcase_add_test(tcFail_p, fail5);
	tcase_add_test(tcFail_p, fail6);
	tcase_add_test(tcFail_p, fail7);
	tcase_add_test(tcFail_p, fail8);
	tcase_add_test(tcFail_p, fail9);
	tcase_add_test(tcFail_p, fail10);
	tcase_add_test(tcFail_p, fail11);
	tcase_add_test(tcFail_p, fail12);
	tcase_add_test(tcFail_p, fail13);
	tcase_add_test(tcFail_p, fail14);
	suite_add_tcase(suite_p, tcFail_p);

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
