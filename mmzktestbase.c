// Made by MMZK1526

/*
	Simple & lightweighted test utility.
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mmzktestbase.h"

char *mmzk_assert_caption = MMZKVAR_ASSERT_CAPTION;
bool mmzk_assert_show_caption = MMZKVAR_ASSERT_SHOW_CAPTION;
bool mmzk_assert_show_success = MMZKVAR_ASSERT_SHOW_SUCCESS;
bool mmzk_assert_show_summary = MMZKVAR_ASSERT_SHOW_SUMMARY;
uint64_t mmzk_test_summary_fail_num = MMZKVAR_TEST_SUMMARY_FAIL_NUM;
uint64_t mmzk_test_summary_test_num = MMZKVAR_TEST_SUMMARY_TEST_NUM;

bool _mmzk_assert_equal_any(
	const void *expected, 
	const void *actual, 
	mmzk_eq_fun *equal, 
	mmzk_str_fun *to_string, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{	
	char *expected_str, *actual_str;

	mmzk_test_summary_test_num++;
	if (equal(expected, actual)) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}

		return true;
	} 
	expected_str = to_string(expected);
	actual_str = to_string(actual);
	mmzk_test_summary_fail_num++;
	if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
		puts(mmzk_assert_caption);
		mmzk_assert_show_caption = false;
	}
	fputs(msg, stdout);
	printf(
		"Not OK!\n%-10s%s\n%-10s%s\n", 
		"Expected:",
		expected_str != NULL ? expected_str : "(null)",
		"Actual:",
		actual_str != NULL ? actual_str : "(null)");
	printf("On line %d of function %s in %s.\n\n", line, func, file);
	free(expected_str);
	free(actual_str);

	return false;
}

bool _mmzk_assert_equal_bool(
	bool expected, 
	bool actual, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	bool result = expected == actual;

	mmzk_test_summary_test_num++;
	if (result) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}
	} else {
		mmzk_test_summary_fail_num++;
		if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
			puts(mmzk_assert_caption);
			mmzk_assert_show_caption = false;
		}
		fputs(msg, stdout);
		printf(
			"Not OK!\n%-10s%s\n%-10s%s\n", 
			"Expected:",
			expected ? "true" : "false",
			"Actual:",
			actual ? "true" : "false");
		printf("On line %d of function %s in %s.\n\n", 
			line, func, file);
	}

	return result;
}

bool _mmzk_assert_equal_char(
	char expected, 
	char actual, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	mmzk_test_summary_test_num++;
	if (expected == actual) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}

		return true;
	}
	mmzk_test_summary_fail_num++;
	if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
		puts(mmzk_assert_caption);
		mmzk_assert_show_caption = false;
	}
	fputs(msg, stdout);
	printf(
		"Not OK!\n%-10s%c (0x%.2x)\n%-10s%c (0x%.2x)\n", 
		"Expected:",
		expected,
		expected, 
		"Actual:",
		actual, 
		actual);
	printf("On line %d of function %s in %s.\n\n", line, func, file);

	return false;
}

bool _mmzk_assert_equal_double(
	double expected, 
	double actual, 
	double error,
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	bool result = expected - actual < error && actual - expected < error;

	mmzk_test_summary_test_num++;
	if (result) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}
	} else {
		mmzk_test_summary_fail_num++;
		if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
			puts(mmzk_assert_caption);
			mmzk_assert_show_caption = false;
		}
		fputs(msg, stdout);
		printf(
			"Not OK!\n%-10s%lf\n%-10s%lf\n", 
			"Expected:",
			expected,
			"Actual:",
			actual);
		printf("On line %d of function %s in %s.\n\n", 
			line, func, file);
	}

	return result;
}

bool _mmzk_assert_equal_float(
	float expected, 
	float actual, 
	float error,
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	bool result = expected - actual < error && actual - expected < error;

	mmzk_test_summary_test_num++;
	if (result) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}
	} else {
		mmzk_test_summary_fail_num++;
		if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
			puts(mmzk_assert_caption);
			mmzk_assert_show_caption = false;
		}
		fputs(msg, stdout);
		printf(
			"Not OK!\n%-10s%f\n%-10s%f\n", 
			"Expected:",
			expected,
			"Actual:",
			actual);
		printf("On line %d of function %s in %s.\n\n", 
			line, func, file);
	}

	return result;
}

bool _mmzk_assert_equal_int8(
	int8_t expected, 
	int8_t actual, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	mmzk_test_summary_test_num++;
	if (expected == actual) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}

		return true;
	} 
	mmzk_test_summary_fail_num++;
	if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
		puts(mmzk_assert_caption);
		mmzk_assert_show_caption = false;
	}
	fputs(msg, stdout);
	printf(
		"Not OK!\n%-10s%.4d (0x%.2x)\n%-10s%.4d (0x%.2x)\n", 
		"Expected:",
		expected,
		expected, 
		"Actual:",
		actual, 
		actual);
	printf("On line %d of function %s in %s.\n\n", line, func, file);

	return false;
}

bool _mmzk_assert_equal_int16(
	int16_t expected, 
	int16_t actual, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	mmzk_test_summary_test_num++;
	if (expected == actual) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}

		return true;
	}
	mmzk_test_summary_fail_num++;
	if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
		puts(mmzk_assert_caption);
		mmzk_assert_show_caption = false;
	}
	fputs(msg, stdout);
	printf(
		"Not OK!\n%-10s%.6d (0x%.4x)\n%-10s%.6d (0x%.4x)\n", 
		"Expected:",
		expected,
		expected, 
		"Actual:",
		actual, 
		actual);
	printf("On line %d of function %s in %s.\n\n", line, func, file);

	return false;
}

bool _mmzk_assert_equal_int32(
	int32_t expected, 
	int32_t actual, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	mmzk_test_summary_test_num++;
	if (expected == actual) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}

		return true;
	}
	mmzk_test_summary_fail_num++;
	if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
		puts(mmzk_assert_caption);
		mmzk_assert_show_caption = false;
	}
	fputs(msg, stdout);
	printf(
		"Not OK!\n%-10s%.11d (0x%.8x)\n%-10s%.11d (0x%.8x)\n", 
		"Expected:",
		expected,
		expected, 
		"Actual:",
		actual, 
		actual);
	printf("On line %d of function %s in %s.\n\n", line, func, file);

	return false;
}

bool _mmzk_assert_equal_int64(
	int64_t expected, 
	int64_t actual, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	mmzk_test_summary_test_num++;
	if (expected == actual) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}

		return true;
	}
	mmzk_test_summary_fail_num++;
	if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
		puts(mmzk_assert_caption);
		mmzk_assert_show_caption = false;
	}
	fputs(msg, stdout);
	printf(
		"Not OK!\n"
		"%-10s%.20lld (0x%.16llx)\n%-10s%.20lld (0x%.16llx)\n", 
		"Expected:",
		expected,
		expected, 
		"Actual:",
		actual, 
		actual);
	printf("On line %d of function %s in %s.\n\n", line, func, file);

	return false;
}

bool _mmzk_assert_equal_ptr(
	const void *expected, 
	const void *actual, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	mmzk_test_summary_test_num++;
	if (expected == actual) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}

		return true;
	}
	mmzk_test_summary_fail_num++;
	if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
		puts(mmzk_assert_caption);
		mmzk_assert_show_caption = false;
	}
	fputs(msg, stdout);
	printf(
		"Not OK!\n%-10s%p\n%-10s%p\n", 
		"Expected:",
		expected,
		"Actual:",
		actual);
	printf("On line %d of function %s in %s.\n\n", line, func, file);

	return false;
}

bool _mmzk_assert_equal_string(
	const char *expected, 
	const char *actual, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	mmzk_test_summary_test_num++;
	if (!strcmp(expected, actual)) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}

		return true;
	}
	mmzk_test_summary_fail_num++;
	if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
		puts(mmzk_assert_caption);
		mmzk_assert_show_caption = false;
	}
	fputs(msg, stdout);
	printf(
		"Not OK!\n%-10s%s\n%-10s%s\n", 
		"Expected:",
		expected,
		"Actual:",
		actual);
	printf("On line %d of function %s in %s.\n\n", line, func, file);

	return false;
}

bool _mmzk_assert_equal_struct(
	const void *expected, 
	const void *actual, 
	mmzk_str_fun *to_string, 
	const char *msg, 
	bool flag,
	int size, 
	int line, 
	const char *func, 
	const char *file)
{
	bool result = flag;

	mmzk_test_summary_test_num++;
	if (result) {
		for (int i = 0; i < size; i++) {
			if (*((const int8_t *)expected + i) != 
				*((const int8_t *)actual + i))
			{
				result = false;
				break;
			}
		}
	}

	if (result) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}
	} else {
		char *expected_str, *actual_str;

		mmzk_test_summary_fail_num++;
		if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
			puts(mmzk_assert_caption);
			mmzk_assert_show_caption = false;
		}
		fputs(msg, stdout);
		expected_str = to_string(expected);
		actual_str = to_string(actual);
		printf(
			"Not OK!\n%-10s%s\n%-10s%s\n", 
			"Expected:",
			expected_str != NULL ? expected_str : "(null)",
			"Actual:",
			actual_str != NULL ? actual_str : "(null)");
		printf("On line %d of function %s in %s.\n\n", 
			line, func, file);
		free(expected_str);
		free(actual_str);
	}

	return result;
}

bool _mmzk_assert_equal_uint8(
	uint8_t expected, 
	uint8_t actual, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	mmzk_test_summary_test_num++;
	if (expected == actual) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}

		return true;
	}
	mmzk_test_summary_fail_num++;
	if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
		puts(mmzk_assert_caption);
		mmzk_assert_show_caption = false;
	}
	fputs(msg, stdout);
	printf(
		"Not OK!\n%-10s%.3u (0x%.2x)\n%-10s%.3u (0x%.2x)\n", 
		"Expected:",
		expected,
		expected, 
		"Actual:",
		actual, 
		actual);
	printf("On line %d of function %s in %s.\n\n", line, func, file);

	return false;
}

bool _mmzk_assert_equal_uint16(
	uint16_t expected, 
	uint16_t actual, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	mmzk_test_summary_test_num++;
	if (expected == actual) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}

		return true;
	}
	mmzk_test_summary_fail_num++;
	if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
		puts(mmzk_assert_caption);
		mmzk_assert_show_caption = false;
	}
	fputs(msg, stdout);
	printf(
		"Not OK!\n%-10s%.5u (0x%.4x)\n%-10s%.5u (0x%.4x)\n", 
		"Expected:",
		expected,
		expected, 
		"Actual:",
		actual, 
		actual);
	printf("On line %d of function %s in %s.\n\n", line, func, file);

	return false;
}

bool _mmzk_assert_equal_uint32(
	uint32_t expected, 
	uint32_t actual, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	mmzk_test_summary_test_num++;
	if (expected == actual) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}

		return true;
	}
	mmzk_test_summary_fail_num++;
	if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
		puts(mmzk_assert_caption);
		mmzk_assert_show_caption = false;
	}
	fputs(msg, stdout);
	printf(
		"Not OK!\n%-10s%.10u (0x%.8x)\n%-10s%.10u (0x%.8x)\n", 
		"Expected:",
		expected,
		expected, 
		"Actual:",
		actual, 
		actual);
	printf("On line %d of function %s in %s.\n\n", line, func, file);

	return false;
}

bool _mmzk_assert_equal_uint64(
	uint64_t expected, 
	uint64_t actual, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	mmzk_test_summary_test_num++;
	if (expected == actual) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}

		return true;
	}
	mmzk_test_summary_fail_num++;
	if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
		puts(mmzk_assert_caption);
		mmzk_assert_show_caption = false;
	}
	fputs(msg, stdout);
	printf(
		"Not OK!\n"
		"%-10s%.20llu (0x%.16llx)\n%-10s%.20llu (0x%.16llx)\n", 
		"Expected:",
		expected,
		expected, 
		"Actual:",
		actual, 
		actual);
	printf("On line %d of function %s in %s.\n\n", line, func, file);

	return false;
}

bool _mmzk_assert_fail(
	const char *msg, int line, const char *func, const char *file) 
{
	mmzk_test_summary_test_num++;
	mmzk_test_summary_fail_num++;
	if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
		puts(mmzk_assert_caption);
		mmzk_assert_show_caption = false;
	}
	puts(msg);
	printf("On line %d of function %s in %s.\n\n", line, func, file);

	return false;
}

bool _mmzk_assert_true(
	bool cond, 
	const char *msg, 
	int line, 
	const char *func, 
	const char *file) 
{
	mmzk_test_summary_test_num++;
	if (cond) {
		if (mmzk_assert_show_success) {
			fputs(msg, stdout);
			puts("OK!");
		}
	} else {
		mmzk_test_summary_fail_num++;
		if (!mmzk_assert_show_success && mmzk_assert_show_caption) {
			puts(mmzk_assert_caption);
			mmzk_assert_show_caption = false;
		}
		fputs(msg, stdout);
		puts("Not OK!");
		printf("On line %d of function %s in %s.\n\n", 
			line, func, file);
	}

	return cond;
}

bool mmzk_eq_int8(const void *x, const void *y) {
	return *(uint8_t *)x == *(uint8_t *)y;
}

bool mmzk_eq_int16(const void *x, const void *y) {
	return *(uint16_t *)x == *(uint16_t *)y;
}

bool mmzk_eq_int32(const void *x, const void *y) {
	return *(uint32_t *)x == *(uint32_t *)y;
}

bool mmzk_eq_int64(const void *x, const void *y) {
	return *(uint64_t *)x == *(uint64_t *)y;
}

int _mmzk_test_report(
	void(*summary_fun)(void), 
	const char *file, 
	int argc, 
	char **argv) 
{
	uint64_t fail_num = mmzk_test_summary_fail_num;

	if (argc >= 2 && !strcmp("-v", argv[1])) {
		mmzk_assert_set_show_success(true);
	}

	(*summary_fun)();

	fail_num = mmzk_test_summary_fail_num - fail_num;
	if (fail_num) {
		printf("Number of failed tests in %s: %llu.\n", 
			file, fail_num);
	} else {
		printf("No failed tests in %s.\n", file);
	}

	return (int)fail_num;
}

mmzk_test_summary_t _mmzk_test_summary(
	void(*test_fun)(void), 
	const char *msg,
	const char *func) 
{
	uint64_t fail_num = mmzk_test_summary_fail_num;
	uint64_t test_num = mmzk_test_summary_test_num;
	char *plural_test, *plural_have;
	bool show_summary = mmzk_assert_show_summary;

	if (*msg != '\0' && show_summary) {
		fputs(msg, stdout);
	}

	mmzk_assert_show_summary = false;
	(*test_fun)();
	mmzk_assert_show_summary = show_summary;

	fail_num = mmzk_test_summary_fail_num - fail_num;
	test_num = mmzk_test_summary_test_num - test_num;
	plural_test = test_num == 1 ? "test" : "tests";
	if (show_summary) {
		if (fail_num) {
			plural_have = fail_num == 1 ? "has" : "have";
			printf(
				"%llu of %llu %s %s failed in the function %s!"
				"\n\n", fail_num, test_num, plural_test, 
				plural_have, func);
		} else {
			plural_have = test_num == 1 ? "has" : "have";
			printf("All %llu %s %s passed in the function %s!\n\n", 
				test_num, plural_test, plural_have, func);
		}
	}

	return (mmzk_test_summary_t){ .fail_num = fail_num, 
		.test_num = test_num };
}
