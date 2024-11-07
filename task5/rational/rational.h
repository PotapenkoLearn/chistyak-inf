#ifndef RATIONAL_H
#define RATIONAL_H

typedef struct {
    int num;
    unsigned int denom;
} rational_t;

rational_t rational(long n, long d);

long rat_num(rational_t r);

long rat_denom(rational_t r);

#endif
