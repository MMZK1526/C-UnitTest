# Example

The example is [here](/Example).  

After compiling the tests with `make`, it will generate a number of executables corresponding to the **.c** test files as well as a **testsuite** containing on tests.  

# Modular Tests

First, let's run one of the modular tests, say **integraltest**:

`./integraltest`

```

Test int & uint (int_test):
Test int:
        Int 16: Not OK!
Expected: 000003 (0x0003)
Actual:   000004 (0x0004)
On line 12 of function int_test in integraltest.c.

        Int 32: Not OK!
Expected: 00000000004 (0x00000004)
Actual:   00000000003 (0x00000003)
On line 13 of function int_test in integraltest.c.

2 of 8 tests have failed in the function int_test!


Test char & bool (char_bool_test):
Test char:
        'C' == 'c': Not OK!
Expected: C (0x43)
Actual:   c (0x63)
On line 28 of function char_bool_test in integraltest.c.

1 of 4 tests has failed in the function char_bool_test!


Test pointer (pointer_test):
Test address:
        different address: Not OK!
Expected: 0x7ffee2dde69c
Actual:   0x7ffee2dde698
On line 48 of function pointer_test in integraltest.c.

1 of 3 tests has failed in the function pointer_test!


----------------------------------------------------------

Number of failed tests in integraltest.c: 4.

```

As shown above, the report only contains failed assertions. There are three functions, namely int_test, char_bool_test, and pointer_test. Each function has one or more sections. Only the sections containing failed assertions are shown.

To show all assertions, run with the `-v` option:

`./integraltest -v`

```

Test int & uint (int_test):
Test int:
        Int 8: OK!
        Int 16: Not OK!
Expected: 000003 (0x0003)
Actual:   000004 (0x0004)
On line 12 of function int_test in integraltest.c.

        Int 32: Not OK!
Expected: 00000000004 (0x00000004)
Actual:   00000000003 (0x00000003)
On line 13 of function int_test in integraltest.c.

        Int 64: OK!

Test uint:
        Unsigned Int 8: OK!
        Unsigned Int 16: OK!
        Unsigned Int 32: OK!
        Unsigned Int 64: OK!

2 of 8 tests have failed in the function int_test!


Test char & bool (char_bool_test):
Test char:
        'c' == 'c': OK!
        'C' == 'c': Not OK!
Expected: C (0x43)
Actual:   c (0x63)
On line 28 of function char_bool_test in integraltest.c.


Test bool:
        true: OK!
        bool: OK!

1 of 4 tests has failed in the function char_bool_test!


Test pointer (pointer_test):
Test value:
        x == y: OK!

Test address:
        same address: OK!
        different address: Not OK!
Expected: 0x7ffee20b569c
Actual:   0x7ffee20b5698
On line 48 of function pointer_test in integraltest.c.


1 of 3 tests has failed in the function pointer_test!


----------------------------------------------------------

Number of failed tests in integraltest.c: 4.

```

Note that the sections `Test uint:` and  `Test value:` appear only in this verbose run, since they contain no failed assertions.  

The other modular tests work similarly.  

# Test Suite

We can run all tests together with `.\testsuite`:

```

Compound Type Tests (compoundtest_summary):
Test string:
        Uppercase & Lowercase: Not OK!
Expected: abc
Actual:   ABC
On line 78 of function string_test in compoundtest.c.

Test same struct:
        Distinct foo_t: Not OK!
Expected: char: a; bool: false; xs: [0, 1, 2]
Actual:   char: a; bool: true; xs: [0, 1, 2]
On line 95 of function struct_test in compoundtest.c.

Test different struct:
        Distinct Order: Not OK!
Expected: char: a; bool: true; xs: [0, 1, 2]
Actual:   char: a; bool: true; xs: [0, 1, 2]
On line 100 of function struct_test in compoundtest.c.

3 of 8 tests have failed in the function compoundtest_summary!


Floating Point Tests (floattest_summary):
Test float:
        Allow Tiny Error: Not OK!
Expected: 3.000000
Actual:   3.010000
On line 15 of function float_test in floattest.c.

Test double:
        Allow Tiny Error: Not OK!
Expected: 3.000000
Actual:   3.010000
On line 21 of function float_test in floattest.c.

2 of 6 tests have failed in the function floattest_summary!


Integral Tests (integraltest_summary):
Test int:
        Int 16: Not OK!
Expected: 000003 (0x0003)
Actual:   000004 (0x0004)
On line 12 of function int_test in integraltest.c.

        Int 32: Not OK!
Expected: 00000000004 (0x00000004)
Actual:   00000000003 (0x00000003)
On line 13 of function int_test in integraltest.c.

Test char:
        'C' == 'c': Not OK!
Expected: C (0x43)
Actual:   c (0x63)
On line 28 of function char_bool_test in integraltest.c.

Test address:
        different address: Not OK!
Expected: 0x7ffeeec6762c
Actual:   0x7ffeeec67628
On line 48 of function pointer_test in integraltest.c.

4 of 15 tests have failed in the function integraltest_summary!


----------------------------------------------------------

Number of failed tests in testsuite.c: 9.

```

The report is similar, but the summary titles in the modular tests are ignored; instead each title represent one whole modular test.  

Running it with `-v` shows all succesful tests as well.
