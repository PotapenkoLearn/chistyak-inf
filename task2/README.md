# inf/task2-required-floor

Предложена программа для вычисления номера этажа дома по номеру квартиры и числу квартир на каждом этаже. К сожалению, программа содержит ошибки.

Во время выполнения этой лабораторной работы необходимо зафиксировать в отдельном текстовом файле последовательность появления тех или иных диагностических сообщений, текст каждого сообщения и способ устранения. При ведении журнала предлагаем поставить номер шага (в соответствии с планом работы), на котором был выявлен дефект, скопировать диагностическое сообщение, скопировать строку исходного кода, содержащую дефект, скопировать исправленную строку.

Модификация программы должна быть минимально необходимой, чтобы исправить обнаруженный при сборке дефект или недочет в формуле, значительные изменения в коде не допускаются.

1. Подготовьте каталог task2 в каталоге inf.
2. В каталоге inf/task2 с помощью текстового редактора создайте текстовый файл fixes.log для ведения журнала исправлений.
3. В каталоге inf/task2 с помощью текстового редактора создайте файл main.c с следующим содержимым (не забудьте обновить заголовочный комментарий):

```clike
/**
 * floor.c -- программа для расчета нужного этажа
 *
 * Copyright (c) 2022, First Last <student@cs.petrsu.ru>
 *
 * This code is licensed under MIT license.
 */

#include<studio.h>

int Main()
{
    // Номер квартиры
    int flat_number;

    /* Число квартир на этаже */
    int flats_per_floor;

    /* Запрашиваем квартиру, в которой проживает адресат */
    printf("Введите номер интересующей квартиры: ");
    scanf("%d", &flat_number)

    /* Запрашиваем число квартир на этаже */
    printf("Введите число квартир на каждом этаже: ");
    scanf("%d", &flats_per_floor);

    /* Рассчитываем и выводим номер этажа */
    printf("Вам нужно подняться на %d этаж\n",
           flat_number / flats_per_floor, flat_number);

    return 0;
}
```

4. Подготовьте файл Makefile для программы по аналогии с первым заданием.
5. Попытайтесь собрать программу с помощью команды make.
6. Ориентируясь по диагностическим сообщениям, последовательно идентифицируйте, зафиксируйте в журнале и исправьте недочеты, добиваясь отсутствия предупреждений и сообщений об ошибках.
7. Убедившись в отсутствии предупреждений и ошибок, включите дополнительные проверки, добавив в файл Makefile ключи компилятора -Wall и -Wextra:

```clike
main.o: main.c
	gcc -g -O0 -c -Wall -Wextra main.c
```

8. Исправив код и зафиксировав изменения в журнале, устраните новые предупреждения компилятора.
9. Включите проверку строгого соответствия стандарту C89, добавив ключи компилятора -pedantic -pedantic-errors -ansi, объясните, что изменилось в диагностике, зафиксируйте в журнале.
10. Измените используемую версию стандарта на более современную, заменив ключ -ansi на -std=c11, объясните, почему исчезло диагностическое сообщение.
11. Запустив программу, убедитесь, что, для восьмой квартиры в доме с четырьмя квартирами на этаже, программа верно печатает номер этажа.

```clike
user@host:~> ./floor
Введите номер интересующей квартиры: 8
Введите число квартир на каждом этаже: 4
Вам нужно подняться на 2 этаж
user@host:~>
```

12. Подберите тестовые данные, на которых программа работает неверно.
13. Проанализируйте и исправьте формулу для вычисления нужного этажа. Внимание: исправления должны затрагивать только формулу расчета нужного этажа. Для составления правильной формулы достаточно операций целочисленного деления (/), сложения и вычитания, условный оператор использовать не следует.
14. Подготовьтесь ответить на вопросы инструктора и сдайте работу. Представляя результаты работы преподавателю вам необходимо продемонстрировать навыки:
    1. уверенного чтения и интерпретации диагностических сообщений и использования диагностики для обнаружения дефектов в коде программы (на примере собранных в файле fixes.log диагностических сообщений);
    2. планирования тестирования программы и подготовки достаточного количества тестовых наборов данных для проверки ее корректности (на примере тестовых данных для программы расчета нужного этажа).