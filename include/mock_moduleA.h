#ifndef MOCK_MODULEA_H
#define MOCK_MODULEA_H

#ifdef TEST_MODE

#include <mock.h>

typedef enum TEST_SUITE_MODULE_A
{
    TEST_SUITE_MODULE_A_1,
    TEST_SUITE_MODULE_A_2,
    TEST_SUITE_MODULE_A_3,
    TEST_SUITE_MODULE_A_4,
    TEST_SUITE_MODULE_A_MAX

} TEST_SUITE_MODULE_A;

/* MODULE A MOCKS */
extern MOCK_ARRAY(int, getArg, TEST_SUITE_MODULE_A, void);
#define __mock_get_arg() MOCK_CALL_FUNC_NO_PARAMS(get_arg)
#define get_arg() __mock_get_arg()

extern MOCK_ARRAY(int, mul, TEST_SUITE_MODULE_A, int, int);
#define __mock_mul(a, b) MOCK_CALL_FUNC_PARAMS(mul, a, b)
#define mul(a, b) __mock_mul(a, b)

/* THOSE FUNCTION CAN BE MOCKED, BUT FOR NO ARE NO MOCKED */
#define __mock_sum(a, b) sum(a, b)
#define sum(a, b) __mock_sum(a, b)

#define __mock_pair_create(a, b) pair_create(a, b)
#define pair_create(a, b) __mock_pair_create(a, b)

#define __mock_pair_destroy(p) pair_destroy(p)
#define pair_destroy(p) __mock_pair_destroy(p)

/* OTHER MOCKS */
extern MOCK_ARRAY(void*, malloc, TEST_SUITE_MODULE_A, size_t);
#define __mock_malloc(size) MOCK_CALL_FUNC_PARAMS(malloc, size)
#define malloc(size) __mock_malloc(size)

extern MOCK_ARRAY(void, free, TEST_SUITE_MODULE_A, void*);
#define __mock_free(ptr) MOCK_CALL_FUNC_PARAMS(free, ptr)
#define free(ptr) __mock_free(ptr)

#endif

#endif