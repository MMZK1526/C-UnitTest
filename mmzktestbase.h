// Made by MMZK1526

/*
	Simple & lightweighted test utility.
*/

#ifndef MMZK1526
#define MMZK1526
#endif /* MMZK1526 */

#ifndef MMZK_TESTBASE_H
#define MMZK_TESTBASE_H

#ifndef MMZKMACRO_MISCELLANEOUS
#define MMZKMACRO_MISCELLANEOUS
/*
	Turns a bool into string literal.
*/
#define MMZK_STR_BOOL(B) B ? "true" : "false"

/*
	Get the string representation of the name of a variable.
*/
#define MMZK_DUMP(VAR) #VAR
#endif /* MMZKMACRO_MISCELLANEOUS */

#include <stdbool.h>
#include <stdint.h>

#ifndef MMZKTYPEDEF_EQUAL_FUN
#define MMZKTYPEDEF_EQUAL_FUN
typedef bool mmzk_eq_fun(const void *, const void *);
#endif /* MMZKTYPEDEF_EQUAL_FUN */

#ifndef MMZKTYPEDEF_STR_FUN
#define MMZKTYPEDEF_STR_FUN
typedef char *mmzk_str_fun(const void *);
#endif /* MMZKTYPEDEF_STR_FUN */

#ifndef MMZKVAR_ASSERT_CAPTION
#define MMZKVAR_ASSERT_CAPTION ""
/*
	The custom caption of a test section.
	Can be set with mmzk_assert_set_caption(char *).
	The caption SHOULD BE a string literal; an empty string disables it.
	When mmzk_assert_show_success = true, the caption will be shown upon
	invoking mmzk_assert_show_caption() or mmzk_assert_pop_caption(char *).
	When mmzk_assert_show_success = false, the caption will not be shown
	when the functions above are invoked. However, they will be shown when
	the first assertion fails.
*/
extern char *mmzk_assert_caption;
#endif /* MMZKVAR_ASSERT_CAPTION */

#ifndef MMZKVAR_ASSERT_SHOW_CAPTION
#define MMZKVAR_ASSERT_SHOW_CAPTION false
/*
	Internal global variable; shouldn't need to mess around with it.
*/
extern bool mmzk_assert_show_caption;
#endif /* MMZKVAR_ASSERT_SHOW_CAPTION */

#ifndef MMZKVAR_ASSERT_SHOW_SUCCESS
#define MMZKVAR_ASSERT_SHOW_SUCCESS false
/*
	When true, an assert will print a message on success as well.
*/
extern bool mmzk_assert_show_success;
#endif /* MMZKVAR_ASSERT_SHOW_SUCCESS */

#ifndef MMZKVAR_ASSERT_SHOW_SUMMARY
#define MMZKVAR_ASSERT_SHOW_SUMMARY true
/*
	Internal global variable; shouldn't need to mess around with it.
*/
extern bool mmzk_assert_show_summary;
#endif /* MMZKVAR_ASSERT_SHOW_SUMMARY */

#ifndef MMZKVAR_TEST_SUMMARY_FAIL_NUM
#define MMZKVAR_TEST_SUMMARY_FAIL_NUM 0
/*
	Total number of asserts that failed.
	Internal global variable; shouldn't need to mess around with it.
*/
extern uint64_t mmzk_test_summary_fail_num;
#endif /* MMZKVAR_TEST_SUMMARY_FAIL_NUM */

#ifndef MMZKVAR_TEST_SUMMARY_TEST_NUM
#define MMZKVAR_TEST_SUMMARY_TEST_NUM 0
/*
	Total number of asserts being executed.
	Internal global variable; shouldn't need to mess around with it.
*/
extern uint64_t mmzk_test_summary_test_num;
#endif /* MMZKVAR_TEST_SUMMARY_TEST_NUM */

typedef struct {
	uint64_t fail_num;
	uint64_t test_num;
} mmzk_test_summary_t;

/*
	Test if two pieces of data are equal based on an equal function 
	and a to_string function.
	The data must have the generic type "void *".
	The to_string function MUST RETURN A STRING IN THE HEAP.
	This is a simulation of structural equality.
*/
#define mmzk_assert_equal_any(EXPECTED, ACTUAL, EQ_FUN, TO_STRING_FUN, MSG) \
_mmzk_assert_equal_any(EXPECTED, ACTUAL, EQ_FUN, TO_STRING_FUN, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two bools are equal.
*/
#define mmzk_assert_equal_bool(EXPECTED, ACTUAL, MSG) \
_mmzk_assert_equal_bool(EXPECTED, ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two characters are equal.
*/
#define mmzk_assert_equal_char(EXPECTED, ACTUAL, MSG) \
_mmzk_assert_equal_char(EXPECTED, ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two doubles are equal.
*/
#define mmzk_assert_equal_double(EXPECTED, ACTUAL, ERROR, MSG) \
_mmzk_assert_equal_double(EXPECTED, ACTUAL, ERROR, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two floats are equal.
*/
#define mmzk_assert_equal_float(EXPECTED, ACTUAL, ERROR, MSG) \
_mmzk_assert_equal_float(EXPECTED, ACTUAL, ERROR, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two signed 8-bit ints are equal.
*/
#define mmzk_assert_equal_int8(EXPECTED, ACTUAL, MSG) \
_mmzk_assert_equal_int8(EXPECTED, ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two signed 16-bit ints are equal.
*/
#define mmzk_assert_equal_int16(EXPECTED, ACTUAL, MSG) \
_mmzk_assert_equal_int16(EXPECTED, ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two signed 32-bit ints are equal.
*/
#define mmzk_assert_equal_int32(EXPECTED, ACTUAL, MSG) \
_mmzk_assert_equal_int32(EXPECTED, ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two signed 8-bit ints are equal.
*/
#define mmzk_assert_equal_int64(EXPECTED, ACTUAL, MSG) \
_mmzk_assert_equal_int64(EXPECTED, ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two pointers are equal; referential equality.
*/
#define mmzk_assert_equal_ptr(EXPECTED, ACTUAL, MSG) \
_mmzk_assert_equal_ptr(EXPECTED, ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two strings are equal.
	The strings must be null-terminated.
*/
#define mmzk_assert_equal_string(EXPECTED, ACTUAL, MSG) \
_mmzk_assert_equal_string(EXPECTED, ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two structs are equal.
	The data passed in are the structs themselves instead of a "void *"
	pointer to them. However, since they will be referenced first, they
	must be stored in variables instead of exist as immediate values.
	It checks the equality of all the fields of the struct, but only does
	a shallow (referential) check for fields pointing to the heap.
	It does not tell apart different types of struct as long as they have
	the same order of fields with the same types.
	The to_string function determines how the struct is printed in the case
	of not equal. It MUST RETURN A STRING IN THE HEAP.
*/
#define mmzk_assert_equal_struct(EXPECTED, ACTUAL, TO_STRING_FUN, MSG) \
_mmzk_assert_equal_struct((const void *)&(EXPECTED), (const void *)&(ACTUAL), TO_STRING_FUN, MSG, sizeof(EXPECTED) == sizeof(ACTUAL), sizeof(EXPECTED), __LINE__, __func__, __FILE__)

/*
	Test if two unsigned 8-bit ints are equal.
*/
#define mmzk_assert_equal_uint8(EXPECTED, ACTUAL, MSG) \
_mmzk_assert_equal_uint8(EXPECTED, ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two unsigned 16-bit ints are equal.
*/
#define mmzk_assert_equal_uint16(EXPECTED, ACTUAL, MSG) \
_mmzk_assert_equal_uint16(EXPECTED, ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two unsigned 32-bit ints are equal.
*/
#define mmzk_assert_equal_uint32(EXPECTED, ACTUAL, MSG) \
_mmzk_assert_equal_uint32(EXPECTED, ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Test if two unsigned 64-bit ints are equal.
*/
#define mmzk_assert_equal_uint64(EXPECTED, ACTUAL, MSG) \
_mmzk_assert_equal_uint64(EXPECTED, ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Just go fail.
*/
#define mmzk_assert_fail(EXPECTED, ACTUAL, MSG) \
_mmzk_assert_fail(EXPECTED, ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Set mmzk_show_success.
*/
#define mmzk_assert_set_show_success(BOOL) mmzk_assert_show_success = BOOL

/*
	Set and show the caption of a test section.
*/
#define mmzk_assert_pop_caption(STR) do { \
	mmzk_assert_caption = STR; \
	mmzk_assert_show_caption = *STR != '\0'; \
	if (mmzk_assert_show_success && mmzk_assert_show_caption) { \
		fputs(mmzk_assert_caption, stdout); \
	} \
} while (0)

/*
	Set the caption of a test section.
*/
#define mmzk_assert_set_caption(STR) mmzk_assert_caption = STR

/*
	Show the caption of a test section.
*/
#define mmzk_assert_show_caption() do { \
	mmzk_assert_show_caption = *STR != '\0'; \
	if (mmzk_assert_show_success && mmzk_assert_show_caption) { \
		fputs(mmzk_assert_caption, stdout); \
	} \
} while (0)

/*
	Test if the condition is true.
*/
#define mmzk_assert_true(ACTUAL, MSG) \
_mmzk_assert_true(ACTUAL, MSG, __LINE__, __func__, __FILE__)

/*
	Take a void function(void) that contains test summaries, generate a
	final report.
	It can be used for the main function. When ran with argument '-v', it
	prints out all the successful tests as well.
	The report should be used at most once in one executable.
*/
#define mmzk_test_report(SUMMARY_FUN, ARGC, ARGV) \
_mmzk_test_report(SUMMARY_FUN, __FILE__, ARGC, ARGV)

/*
	Take a void function(void) that uses the assert functions, invoke it
	and generate a summary.
	Do not pass the address of the assert function; use its name directly.
*/
#define mmzk_test_summary(TEST_FUN, MSG) \
_mmzk_test_summary(&TEST_FUN, MSG, MMZK_DUMP(TEST_FUN))

#ifdef __cplusplus
extern "C" {
#endif 

/*
	Default equality function by casting the pointers to 8-bit int 
	pointers and dereference.
*/
extern bool mmzk_eq_int8(const void *, const void *);

/*
	Default equality function by casting the pointers to 16-bit int 
	pointers and dereference.
*/
extern bool mmzk_eq_int16(const void *, const void *);

/*
	Default equality function by casting the pointers to 32-bit int 
	pointers and dereference.
*/
extern bool mmzk_eq_int32(const void *, const void *);

/*
	Default equality function by casting the pointers to 64-bit int 
	pointers and dereference.
*/
extern bool mmzk_eq_int64(const void *, const void *);

/*
	Never mind the functions below; use their macro versions above instead.
*/

extern bool _mmzk_assert_equal_any(const void *, const void *, mmzk_eq_fun *, mmzk_str_fun *, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_bool(bool, bool, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_char(char, char, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_double(double, double, double, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_float(float, float, float, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_int8(int8_t, int8_t, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_int16(int16_t, int16_t, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_int32(int32_t, int32_t, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_int64(int64_t, int64_t, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_ptr(const void *, const void *, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_string(const char *, const char *, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_struct(const void *, const void *, mmzk_str_fun *, const char *, bool, int, int, const char *, const char *);
extern bool _mmzk_assert_equal_uint8(uint8_t, uint8_t, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_uint16(uint16_t, uint16_t, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_uint32(uint32_t, uint32_t, const char *, int, const char *, const char *);
extern bool _mmzk_assert_equal_uint64(uint64_t, uint64_t, const char *, int, const char *, const char *);
extern bool _mmzk_assert_fail(const char *, int, const char *, const char *);
extern bool _mmzk_assert_true(bool, const char *, int, const char *, const char *);
extern int _mmzk_test_report(void(*)(void), const char *, int, char **);
extern mmzk_test_summary_t _mmzk_test_summary(void(*)(void), const char *, const char *);

#ifdef __cplusplus
}
#endif

#endif /* MMZK_TESTBASE_H */
