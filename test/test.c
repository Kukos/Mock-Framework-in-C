
/* INCLUDE SECTION */
#include <moduleA.h>
#include <stdio.h>

/* EXTERN */
extern int mul(int, int);

/* STATIC MEMORY */
static char memory[1000];

/* TEST / MOCK INCLUDE */
#include <mock_moduleA.h>
testsuite_alloc_static_memory();

/* MOCKS */
static int get_arg_ret5(void)
{
    return 5;
}

static int get_arg_ret3(void)
{
    return 3;
}

static void *my_malloc(size_t size)
{
    return &memory[0];
}

static void my_free(void *ptr)
{
    (void)ptr;
}

static int fake_mul(int a, int b)
{
    return a > b ? a : b;
}

MOCK_ARRAY(int, get_arg, TEST_SUITE_MODULE_A, void);
MOCK_ARRAY(int, mul, TEST_SUITE_MODULE_A, int, int);
MOCK_ARRAY(void*, malloc, TEST_SUITE_MODULE_A, size_t);
MOCK_ARRAY(void, free, TEST_SUITE_MODULE_A, void*);

/* TESTS */
static void test_init(void)
{
    MOCK_FUNC(get_arg, TEST_SUITE_MODULE_A_1, get_arg_ret5);
    MOCK_FUNC(get_arg, TEST_SUITE_MODULE_A_2, get_arg_ret3);
    MOCK_FUNC(mul, TEST_SUITE_MODULE_A_4, fake_mul);
    MOCK_FUNC(malloc, TEST_SUITE_MODULE_A_4, my_malloc);
    MOCK_FUNC(free, TEST_SUITE_MODULE_A_4, my_free);
}

static void test1(void)
{
    testsuite_set_test_case(TEST_SUITE_MODULE_A_1);
    int error = 0;
    int a = 12345;
    a = get_arg();

    int b = 98765;
    b = get_arg();
    
    if (a == 12345 || b == 98765)
    {
        printf("%s:%d:ERROR\n", __func__, __LINE__);
        ++error;
    }

    if (error == 0)
        printf("%s PASSED\n", __func__);
    else
        printf("%s FAILED\n", __func__);
}

static void test2(void)
{
    testsuite_set_test_case(TEST_SUITE_MODULE_A_2);
    int error = 0;
    int a;

    a = get_arg();

    if (a != 3)
    {
        printf("%s:%d:ERROR\n", __func__, __LINE__);
        ++error;
    }

    if (error == 0)
        printf("%s PASSED\n", __func__);
    else
        printf("%s FAILED\n", __func__);
}

static void test3(void)
{
    testsuite_set_test_case(TEST_SUITE_MODULE_A_3);
    int error = 0;

    if (mul(3, 4) != 12)
    {
        printf("%s:%d:ERROR\n", __func__, __LINE__);
        ++error;
    }

    if (error == 0)
        printf("%s PASSED\n", __func__);
    else
        printf("%s FAILED\n", __func__);
}

static void test4(void)
{
    testsuite_set_test_case(TEST_SUITE_MODULE_A_4);
    int error = 0;

    Pair *p = pair_create(7, 2);
    if ((void *)p != (void *)&memory[0])
    {
        printf("%s:%d:ERROR\n", __func__, __LINE__);
        ++error;
    }

    if (pair_get_a(p) != 9)
    {
        printf("%s:%d:ERROR\n", __func__, __LINE__);
        ++error;
    }
    
    if (pair_get_b(p) != 7)
    {
        printf("%s:%d:ERROR\n", __func__, __LINE__);
        ++error;
    }

    pair_destroy(p);

    if (error == 0)
        printf("%s PASSED\n", __func__);
    else
        printf("%s FAILED\n", __func__);
}

int main(void)
{
    test_init();
    test1();
    test2();
    test3();
    test4();
}