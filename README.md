# Mock-Framework-in-C
Framework for mocking functions in C, compatible with C99+ and gnu99+

## How to use framework in my C code ?

### Setup ###

You need to copy files from mock_framework directory to your include directory

### Mock Header ###
For each your module you need to create mock_"module".h. This file have to include mock.h header from mock framework.
In this file you need specify test cases in dedicated enum for your test suite (see Test chapter).

Also for each function that will be mocked you need to create array of pointers and 2 mock macros (see include/mock_moduleA.h).
If function will be mocked in another module (by including this module) and doesn't mocked here, you don't need to create array of pointers (i.e sum function from moduleA)

### Product Code ###
You need to include your mock_"module".h file as a last include AFTER static allocation memory, because framework is removing static keyword.
Before each function's definision you need to add \#undef "func_name" line. After function's definition you need add mock macro. Please see ./src/moduleA.c

### Tests ###
First you need to create dedicated enum for test suite. Each test case must have separate field in enum. Typedefed enum have to be written into your mock_"module".h file.
In your test file you need to create a few code section. As a first code section create normal include section. After that create section with all externed function (Framework removes static keyword, so static function from module can be externed). As 3th section write down all static memory. After that you can include mock_"module".h file.

To setup your test suite you need to call testsuite_alloc_static_memory() outside of functions scope. Also you need to alloc memory for mock arrays (using MOCK_ARRAY macro).
In separate function like test_init you need to map mocked functions to testcases.
After that you can write test cases, but remember to set testcase in each TC function by calling testsuite_set_test_case(test_case)

### Example ###
This project is a full example of using new mock framework. 

### How to build this project ###
To compile application type make. 

To compile tests type make test.

