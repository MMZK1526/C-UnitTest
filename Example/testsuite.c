/* Boilerplate auto-generated by MMZK1526 */

#include "mmzktestbase.h"
#include "testsuite.h"

void testsuite_summary(void) {
	mmzk_test_summary(
		floattest_summary, 
		"Floating Point Tests (floattest_summary):\n");
	mmzk_test_summary(
		integraltest_summary, 
		"Integral Tests (integraltest_summary):\n");
}

// Run with the option "-v" to go verbose (show successful tests).
int main(int argc, char **argv) {
	return mmzk_test_report(&testsuite_summary, argc, argv);
}
