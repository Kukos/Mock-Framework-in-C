#include <moduleA.h>

#include <stdio.h>

int main(void)
{
    int a;
    int b;
    Pair *p;

    a = get_arg();
    b = get_arg();

    p = pair_create(a, b);

    printf("%d + %d = %d\n", a, b, sum(a, b));
    printf("Pair=(%d, %d)\n", pair_get_a(p), pair_get_b(p));

    pair_destroy(p);
    return 0;
}