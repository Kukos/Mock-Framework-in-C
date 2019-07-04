#include <moduleA.h>
#include <stdio.h>
#include <stdlib.h>
#include <mock_moduleA.h>

typedef struct Pair
{
    int a;
    int b;
} Pair;

#undef mul
static int mul(int a, int b)
{
    return a * b;
}
#ifdef TEST_MODE
#define mul(a, b) __mock_mul(a, b)
#endif

#undef get_arg
int get_arg(void)
{
    int arg;
    scanf("%d", &arg);

    return arg;
}

#ifdef TEST_MODE
#define get_arg() __mock_get_arg()
#endif

#undef sum
int sum(int a, int b)
{
    return a + b;
}
#ifdef TEST_MODE
#define sum(a, b) __mock_sum(a, b)
#endif

#undef pair_create
Pair *pair_create(int a, int b)
{
    Pair *pair = malloc(sizeof(Pair));

    pair->a = sum(a, b);
    pair->b = mul(a, b);

    return pair;
}
#ifdef TEST_MODE
#define pair_create(a, b) __mock_pair_create(a, b)
#endif

#undef pair_destroy
void pair_destroy(Pair *p)
{
    free(p);
}
#ifdef TEST_MODE
#define pair_destroy(p) __mock_pair_destroy(p)
#endif

/* NEVER MOCK THIS FUNC */
int pair_get_a(const Pair *p)
{
    return p->a;
}

/* NEVER MOCK THIS FUNC */
int pair_get_b(const Pair *p)
{
    return p->b;
}