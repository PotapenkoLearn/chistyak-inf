#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "calculate_primes.h"

void get_golbach_sum(int primes[], int number)
{
    // Если number < 4 или нечетное
    // то найти пару простых чисел, дающих в сумме number не является возможным;
    if (number < 4 || number % 2)
    {
        return;
    }

    // Количество всех найденных вариантов суммы простых чисел, которые
    // в результате дают number
    int count = 0;

    // Минимальное первое слагаемое
    int min = 0;

    for (int i = 2; i <= number / 2; i++)
    {
        // Если пара {i} и {number - i} являются простыми числами,
        // то при их сложении мы получим целевое значение number
        if (primes[i] && primes[number - i])
        {
            // Если это первая пара, то считаем что
            // i и есть минимальное первое слагаемое
            if (!count)
            {
                min = i;
            }

            // Увеличиваем счетчик суммы
            count++;
        }
    }

    if (count)
    {
        printf("%d %d %d %d\n", number, count, min, number - min);
    }
}

int MAX = 10000000;

int main(void)
{
    int n, m;

    printf("Введите пару чисел в диапазоне 4 <= n < m <= 10000000: ");
    scanf("%d %d", &n, &m);

    if (n < 4 || m > MAX || n > m)
    {
        printf("Некорректно задана пара чисел");

        return EXIT_FAILURE;
    }

    int *primes = (int*) malloc((m + 1) + sizeof(int));
    
    if (primes == NULL)
    {
        printf("Ошибка выделения памяти\n");

        return EXIT_FAILURE;
    }

    calculate_primes(primes, m);

    for (int i = n; i <= m; i++)
    {
        get_golbach_sum(primes, i);
    }

    return EXIT_SUCCESS;
}
