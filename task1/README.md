# inf/task1-hello-students

1. Начните работу в ОС GNU/Linux, используя выданные входное имя и пароль. В дисплейных классах установлен дистрибутив OpenSUSE, который нужно выбрать в меню загрузчика после включения компьютера.
2. Открыв терминал, создайте в домашнем каталоге каталог inf, а в нем – каталог task1.
3. В каталоге inf/task1 с помощью текстового редактора Emacs создайте файл main.c с следующим содержимым:

```clike
/**
 * main.c -- программа "Hello, students!"
 *
 * Copyright (c) 2022, First Last <student@cs.petrsu.ru>
 *
 * This code is licensed under MIT license.
 */

#include <stdio.h>

int main()
{
    /* Выводим приветствие */
    fprintf(stdout, "Hello, students!\n");

    return 0;
}
```

4. Замените в заголовочном комментарии `First` и `Last` на ваши имя и фамилию, `student@cs.petrsu.ru` на ваш адрес электронной почты. Заголовочный комментарий должен быть также правильно оформлен в каждом исходном файле каждой следующей работы. Информация об условиях использования (MIT license) дана для примера и имеет значение, если код будет опубликован.
5. Используя текстовый редактор, подготовьте файл Makefile (название с заглавной буквы) со следующим содержимым:

```clike
# цель по умолчанию (при вызове make или make task1)
# собираем программу task1 из объектного файла task1.o
task1: main.o
	gcc -g -O0 -o task1 main.o

main.o: main.c
	gcc -g -O0 -c main.c

# цель clean (при вызове make clean)
# удаляем программу и объектные файлы
clean:
	rm task1 *.o
```

6.  Соберите программу с помощью команды `make`. Команду `make` можно вызвать из Емакса: введите `M-x compile` (нажать "Alt+x", ввести "compile") и подтвердите вызов `make`.
7.  Проверьте работу программы в терминале:

    ```javascript
    user@host:~/inf/task1> ./task1
    Hello, students!
    user@host:~/inf/task1>
    ```

8.  Добавьте в файл Makefile цель без зависимостей `indent` для автоматического форматирования кода в стиле K&R, с использованием программы `indent` со следующими параметрами:

    ```javascript
    indent -kr -nut main.c
    ```

9.  Проверьте работу созданной цели: вызов `make` с аргументов `indent` должен привести к выполнению команды `indent` и исправлению форматирования файла, если оно было нарушено.
10. Перезагрузите компьютер в ОС Windows.
11. Используя клиент удаленного доступа PuTTY, настройте соединение с учебным сервером kappa (`kappa.cs.petrsu.ru`) и откройте терминальный сеанс.
12. Удаленно отредактируйте текст программы в текстовом редакторе и выполните сборку.
13. Подготовившись ответить на вопросы инструктора и продемонстрировать приобретенные навыки, сдайте работу.
