#include <stdio.h>
#include <stdlib.h>

#include "rational.h"
#include "rat_math.h"
#include "rat_io.h"

int main() {
    rational_t last = rational(0, 1);

    char exp1[20], exp2[20];
    char op;

    while (scanf("%s %c %s", exp1, &op, exp2) == 3) {
        rational_t r1 = rat_parse(exp1, last);
        rational_t r2 = rat_parse(exp2, last);

        rational_t result; 

        if (op == '+')
            result = rat_add(r1, r2);

        if (op == '-')
            result = rat_sub(r1, r2);

        if (op == '*')
            result = rat_mul(r1,r2);

        if (op == '/')
            result = rat_div(r1, r2);


        printf("= ");
        rat_print(result);

        last = result;
    }

    return EXIT_SUCCESS;
}
