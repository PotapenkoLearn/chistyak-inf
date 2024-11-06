/**
 * priems.c -- программа для вывода всех простых числел.
 *
 * Copyright (c) 2024, Potapenko Pavel <poptapenko.dev@gmail.com>
 *
 * This code is licensed under MIT license.
 */
#include <stdio.h>
#include <stdlib.h>

#include "calculate_primes.h"
  
int MAX = 10000000;

int main(void)
{
    int n;

    printf("Введите число в диапазоне 1 < n <= 10000000: ");
    scanf("%d", &n);

    if (n > MAX || n <= 1)
    {
        printf("Некорректно введено число");

        return EXIT_FAILURE;
    }

    int *primes = (int*) malloc((n + 1) * sizeof(int));

    if (primes == NULL)
    {
        printf("Ошибка выделения памяти");

        return EXIT_FAILURE;
    }

    calculate_primes(primes, n);

    for (int i = 0; i <= n; i++)
    {
       if (primes[i])
       {
           printf("%d\n", i);
       }
    }

    return EXIT_SUCCESS;
}
