#ifndef MOCK_H
#define MOCK_H

#ifdef TEST_MODE

#include <testsuite.h>

#ifndef TO_STRING
#define TO_STRING(X) _TO_STRING(X)
#define _TO_STRING(X) #X
#endif

#ifndef CONCAT
#define CONCAT(X, Y) _CONCAT(X, Y)
#define _CONCAT(X, Y) X ## Y
#endif

#define MOCK_PREFIX mock_
#define MOCK_ARRAY_NAME(funcName) CONCAT(MOCK_PREFIX, funcName)
#define MOCK_ARRAY_SIZE(suite) CONCAT(CONCAT(suite, _), MAX)
#define MOCK_ARRAY(ret, funcName, suite, ...) ret (*MOCK_ARRAY_NAME(funcName)[MOCK_ARRAY_SIZE(suite)])(__VA_ARGS__)

#define MOCK_FUNC(name, test, func) MOCK_ARRAY_NAME(name)[test] = func

#define MOCK_CALL_FUNC_NO_PARAMS(func) (MOCK_ARRAY_NAME(func)[testsuite_get_test_case()] ? ((*MOCK_ARRAY_NAME(func)[testsuite_get_test_case()])()) : (func()))
#define MOCK_CALL_FUNC_PARAMS(func, ...) (MOCK_ARRAY_NAME(func)[testsuite_get_test_case()] ?  ((*MOCK_ARRAY_NAME(func)[testsuite_get_test_case()])(__VA_ARGS__)) : (func(__VA_ARGS__)))

#endif

#endif