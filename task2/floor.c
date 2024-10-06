/**
 * floor.c -- программа для расчета нужного этажа
 *
 * Copyright (c) 2022, Pavel Potapenko <potapenko.dev@gmail.com>
 *
 * This code is licensed under MIT license.
 */

#include<stdio.h>

int main()
{
    // Номер квартиры
    int flat_number = 0;

    /* Число квартир на этаже */
    int flats_per_floor = 0;

    while (flat_number < 1) {
        /* Запрашиваем квартиру, в которой проживает адресат */
        printf("Введите номер интересующей квартиры: ");
        scanf("%d", &flat_number);

        if (flat_number < 1) {
            printf("Номер интересующей квартиры введен некорректно\n");
        }
    }

    while (flats_per_floor < 1) {
        /* Запрашиваем число квартир на этаже */
        printf("Введите число квартир на каждом этаже: ");
        scanf("%d", &flats_per_floor);

        if (flats_per_floor < 1) {
            printf("Число квартир на каждом этаже введено некорректно\n");
        }
    }

    /* Рассчитываем и выводим номер этажа */
    printf("Вам нужно подняться на %d этаж\n", (flat_number - 1) / flats_per_floor + 1);

    return 0;
}
