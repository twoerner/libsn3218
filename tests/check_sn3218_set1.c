/*
 * Copyright (C) 2020  Trevor Woerner <twoerner@gmail.com>
 * SPDX-License-Identifier: OSL-3.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <check.h>
#include "sn3218.h"

START_TEST(set1)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED1, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED1);
	ck_assert(ret);
}
END_TEST

START_TEST(set2)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED2, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED2);
	ck_assert(ret);
}
END_TEST

START_TEST(set3)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED3, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED3);
	ck_assert(ret);
}
END_TEST

START_TEST(set4)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED4, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED4);
	ck_assert(ret);
}
END_TEST

START_TEST(set5)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED5, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED5);
	ck_assert(ret);
}
END_TEST

START_TEST(set6)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED6, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED6);
	ck_assert(ret);
}
END_TEST

START_TEST(set7)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED7, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED7);
	ck_assert(ret);
}
END_TEST

START_TEST(set8)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED8, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED8);
	ck_assert(ret);
}
END_TEST

START_TEST(set9)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED9, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED9);
	ck_assert(ret);
}
END_TEST

START_TEST(set10)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED10, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED10);
	ck_assert(ret);
}
END_TEST

START_TEST(set11)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED11, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED11);
	ck_assert(ret);
}
END_TEST

START_TEST(set12)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED12, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED12);
	ck_assert(ret);
}
END_TEST

START_TEST(set13)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED13, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED13);
	ck_assert(ret);
}
END_TEST

START_TEST(set14)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED14, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED14);
	ck_assert(ret);
}
END_TEST

START_TEST(set15)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED15, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED15);
	ck_assert(ret);
}
END_TEST

START_TEST(set16)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED16, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED16);
	ck_assert(ret);
}
END_TEST

START_TEST(set17)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED17, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED17);
	ck_assert(ret);
}
END_TEST

START_TEST(set18)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED18, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED18);
	ck_assert(ret);
}
END_TEST

START_TEST(set1_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED1, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED1);
	ck_assert(ret);
}
END_TEST

START_TEST(set2_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED2, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED2);
	ck_assert(ret);
}
END_TEST

START_TEST(set3_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED3, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED3);
	ck_assert(ret);
}
END_TEST

START_TEST(set4_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED4, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED4);
	ck_assert(ret);
}
END_TEST

START_TEST(set5_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED5, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED5);
	ck_assert(ret);
}
END_TEST

START_TEST(set6_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED6, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED6);
	ck_assert(ret);
}
END_TEST

START_TEST(set7_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED7, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED7);
	ck_assert(ret);
}
END_TEST

START_TEST(set8_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED8, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED8);
	ck_assert(ret);
}
END_TEST

START_TEST(set9_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED9, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED9);
	ck_assert(ret);
}
END_TEST

START_TEST(set10_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED10, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED10);
	ck_assert(ret);
}
END_TEST

START_TEST(set11_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED11, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED11);
	ck_assert(ret);
}
END_TEST

START_TEST(set12_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED12, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED12);
	ck_assert(ret);
}
END_TEST

START_TEST(set13_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED13, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED13);
	ck_assert(ret);
}
END_TEST

START_TEST(set14_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED14, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED14);
	ck_assert(ret);
}
END_TEST

START_TEST(set15_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED15, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED15);
	ck_assert(ret);
}
END_TEST

START_TEST(set16_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED16, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED16);
	ck_assert(ret);
}
END_TEST

START_TEST(set17_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED17, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED17);
	ck_assert(ret);
}
END_TEST

START_TEST(set18_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
	ret = sn3218__set_led_brightness(LED18, 1);
	ck_assert(ret);
	ret = sn3218__set_led(LED18);
	ck_assert(ret);
}
END_TEST

void
teardown(void)
{
	sleep(1);
}

Suite*
sn3218_suite(void)
{
	Suite *suite_p = suite_create("sn3218");
	TCase *tcSet_p = tcase_create("set");
	TCase *tcSet2_p = tcase_create("set_2");

	tcase_add_checked_fixture(tcSet_p, NULL, teardown);
	tcase_add_test(tcSet_p, set1);
	tcase_add_test(tcSet_p, set2);
	tcase_add_test(tcSet_p, set3);
	tcase_add_test(tcSet_p, set4);
	tcase_add_test(tcSet_p, set5);
	tcase_add_test(tcSet_p, set6);
	tcase_add_test(tcSet_p, set7);
	tcase_add_test(tcSet_p, set8);
	tcase_add_test(tcSet_p, set9);
	tcase_add_test(tcSet_p, set10);
	tcase_add_test(tcSet_p, set11);
	tcase_add_test(tcSet_p, set12);
	tcase_add_test(tcSet_p, set13);
	tcase_add_test(tcSet_p, set14);
	tcase_add_test(tcSet_p, set15);
	tcase_add_test(tcSet_p, set16);
	tcase_add_test(tcSet_p, set17);
	tcase_add_test(tcSet_p, set18);
	suite_add_tcase(suite_p, tcSet_p);

	tcase_add_checked_fixture(tcSet2_p, NULL, teardown);
	tcase_add_test(tcSet2_p, set1_2);
	tcase_add_test(tcSet2_p, set2_2);
	tcase_add_test(tcSet2_p, set3_2);
	tcase_add_test(tcSet2_p, set4_2);
	tcase_add_test(tcSet2_p, set5_2);
	tcase_add_test(tcSet2_p, set6_2);
	tcase_add_test(tcSet2_p, set7_2);
	tcase_add_test(tcSet2_p, set8_2);
	tcase_add_test(tcSet2_p, set9_2);
	tcase_add_test(tcSet2_p, set10_2);
	tcase_add_test(tcSet2_p, set11_2);
	tcase_add_test(tcSet2_p, set12_2);
	tcase_add_test(tcSet2_p, set13_2);
	tcase_add_test(tcSet2_p, set14_2);
	tcase_add_test(tcSet2_p, set15_2);
	tcase_add_test(tcSet2_p, set16_2);
	tcase_add_test(tcSet2_p, set17_2);
	tcase_add_test(tcSet2_p, set18_2);
	suite_add_tcase(suite_p, tcSet2_p);

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
