#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#ifdef TEST_MODE

extern long test_case;

#define testsuite_alloc_static_memory() long test_case
#define testsuite_set_test_case(tc) test_case = (long)tc
#define testsuite_get_test_case() test_case

#define static

#endif

#endif