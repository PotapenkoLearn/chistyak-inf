#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void show_lychrel_candidates(long last_number);

int is_lychrel_candidate(long number);

long reverse(long n);

int main(void)
{
    long last_number;

    do
    {
        printf("Введите верхнюю границу отрезка поиска чисел Лишрел: ");
        scanf("%ld", &last_number);

        if (last_number <= 0)
        {
            printf("Введите натуральное число\n");
        }
    } while(last_number <= 0);
    
    
    show_lychrel_candidates(last_number);

    return EXIT_SUCCESS;
}

void show_lychrel_candidates(long last_number)
{
    long number;

    for (number = 1; number <= last_number; number++)
    {
        if (is_lychrel_candidate(number))
        {
            printf("%ld\n", number);
        }
    }
}

int is_lychrel_candidate(long number)
{
    long n = number;
    long r = reverse(n);

    if (r == -1) {
        return 1;
    }

    do
    {
        if (n > LONG_MAX - r)
        {
            return 1;
        }
    
        n = n + r;

        r = reverse(n);

    } while (n != r);

    return 0;
}

long reverse(long number)
{
    long reversed = 0;

    while(number != 0)
    {
        // Считается ли хорошей практикой выносить переменную наверх?
        // На каждой итерации выделяется память. Трудоемкая ли эта операция для ПК?

        // Можем использовать short
        // Переполнения памяти не произойдет так как % 10 ограничивается диапозоном от -9 до 9
        // Стоит ли экономить 6 байт памяти?

        long rest = number % 10;

        if (reversed > (LONG_MAX - rest) / 10)
        {
            return -1;
        }

        reversed = reversed * 10 + rest;
        
        number /= 10;
    }

    return reversed;
}