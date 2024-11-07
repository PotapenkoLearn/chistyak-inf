#ifndef RAT_IO_H
#define RAT_IO_H

#include "rational.h"

rational_t rat_parse(const char *str, rational_t last_result);

void rat_print(rational_t r);

#endif
