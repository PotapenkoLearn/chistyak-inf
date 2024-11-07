#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rat_io.h"

#define TEMPLATE_RATIONAL "%ld/%ld"
#define TEMPLATE_INTEGER "%ld"
#define TEMPLATE_LAST "last"

rational_t rat_parse(const char *str, rational_t last_result) {
    long n, d;

    // Если переданное значение является рациональным числом
    // то возвращаем обьект rational_t с соответствующими значениями
    // в числителе и знаменателе
    if (sscanf(str, TEMPLATE_RATIONAL, &n, &d) == 2) {
        return rational(n, d);
    // Если переданное значение является целым числом, 
    // то возвращаем значение обьект rational_t с соответствующим числителем
    // и единицей в знаменателе
    } else if(sscanf(str, TEMPLATE_INTEGER, &n) == 1) {
        return rational(n, 1);
    // Если переданное значение == last, возвращаем last_result
    } else if (strcmp(str, TEMPLATE_LAST) == 0) {
        return last_result;
    } else {
        fprintf(stderr, "Ошибка ввода\n");

        exit(1);
    }
}

// Функция вывода рационального числа
void rat_print(rational_t r) {
    if (rat_denom(r) == 0) {
        // Если в знаменателе 0 то выводим Infinity
        printf("Infinity\n");
    } else if (rat_denom(r) == 1) {
        // Если в знаменателе 1 то выводим только числитель дроби
        printf("%ld\n", rat_num(r));
    } else {
        // Иначе выводи значение вида a/b
        printf("%ld/%ld\n", rat_num(r), rat_denom(r));
    }
}
