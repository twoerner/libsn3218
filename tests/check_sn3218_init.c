/*
 * Copyright (C) 2020  Trevor Woerner <twoerner@gmail.com>
 * SPDX-License-Identifier: OSL-3.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <check.h>
#include "sn3218.h"

START_TEST(test_init_1)
{
	bool ret;

	ret = sn3218__init(NULL, false, false);
	ck_assert(ret);
}
END_TEST

START_TEST(test_init_2)
{
	bool ret;

	ret = sn3218__init(NULL, true, false);
	ck_assert(ret);
}
END_TEST

START_TEST(test_init_3)
{
	bool ret;

	ret = sn3218__init(NULL, false, true);
	ck_assert(ret);
}
END_TEST

START_TEST(test_init_4)
{
	bool ret;

	ret = sn3218__init(NULL, true, true);
	ck_assert(ret);
}
END_TEST

START_TEST(test_init_5)
{
	bool ret;

	ret = sn3218__init("/dev/i2c-1", false, false);
	ck_assert(ret);
}
END_TEST

START_TEST(test_init_6)
{
	bool ret;

	ret = sn3218__init("/dev/i2c-1", true, false);
	ck_assert(ret);
}
END_TEST

START_TEST(test_init_7)
{
	bool ret;

	ret = sn3218__init("/dev/i2c-1", false, true);
	ck_assert(ret);
}
END_TEST

START_TEST(test_init_8)
{
	bool ret;

	ret = sn3218__init("/dev/i2c-1", true, true);
	ck_assert(ret);
}
END_TEST

Suite*
sn3218_suite(void)
{
	Suite *suite_p = suite_create("sn3218");
	TCase *tcInit_p = tcase_create("init");

	tcase_add_test(tcInit_p, test_init_1);
	tcase_add_test(tcInit_p, test_init_2);
	tcase_add_test(tcInit_p, test_init_3);
	tcase_add_test(tcInit_p, test_init_4);
	tcase_add_test(tcInit_p, test_init_5);
	tcase_add_test(tcInit_p, test_init_6);
	tcase_add_test(tcInit_p, test_init_7);
	tcase_add_test(tcInit_p, test_init_8);
	suite_add_tcase(suite_p, tcInit_p);

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
