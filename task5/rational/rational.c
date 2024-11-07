#include "rational.h"

// Функция для поиска НОД двуч чисел
static long gcd(long a, long b) {
    long temp;

    // При a < b остаток от деления a % b = b. В таком случае на первой
    // a и b поменяются местами, что бы соблюдалость условие a >= b

    // Цикл будет выполняться до тех пор, пока остаток от деления a на b != 0
    // Если остаток = 0, то значение a и будет НОД 
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a < 0 ? -a : a;
}


rational_t rational(long n, long d) {
    rational_t r;

    // Обработка случа если у нас в знаменателе 0   
    if (d == 0) {
        r.num = 1;
        r.denom = 0;
    } else {
        // Если у нас в знаменателе значение < 0, то переносим минус в числитель
        // и избавляемся от минуса в знаменателе
        if (d < 0) {
            n = -n;
            d = -d;
        }
        
        // Находим НОД
        long divisor = gcd(n, d);

        // Сокращаем дробь, деля числитель и знаменатель на НОД
        r.num = n / divisor;
        r.denom = (unsigned int)(d / divisor);
    }

    return r;
}

// Возвращает числитель дроби
long rat_num(rational_t r) {
    return r.num;
}

// Возвращает знаменатель дроби
long rat_denom(rational_t r) {
    return r.denom;
}
