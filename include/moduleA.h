#ifndef MODULEA_H
#define MODULEA_H

typedef struct Pair Pair;

int get_arg(void);

int sum(int a, int b);

Pair *pair_create(int a, int b);
void pair_destroy(Pair *p);
int pair_get_a(const Pair *p);
int pair_get_b(const Pair *p);

#endif