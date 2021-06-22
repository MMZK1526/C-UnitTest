# C Unit Test (mmzktestbase)

A light-weighted module that generates concise and structured unit tests for programs in the C language.  

It provides a variety of assert functions, supporting highly-configurable equality checks for both basic and user-defined data types. For integral types, it prints the integers in both dec and hex forms; for floating point types, it accepts an extra argument to account for errors. It also contains useful summary and report functions that clearly display the test results.  

The unit test module allows two types of display, namely only showing failed tests (by default) and show all successful and failed tests (verbose mode). One can also set section titles only visible in verbose mode.  

See [Example](/Example/README.md) for a demo.
