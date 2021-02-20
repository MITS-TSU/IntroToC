/*
 * Условные операторы в СИ
 * IF
 * ELSE
 * IF + ELSE
 *
 * Используются для ветвления в ходе программы
 */

#include <stdio.h>

int main() {
    /*
     * =======================================================
     * Простейший вариант.
     * Если условие в скобках истинно, выполняет код внутри блока if.
     * Если нет - пропускает его
     * =======================================================
     */
    int n;
    puts("Введите число");
    scanf("%d", &n);

    if (n % 2 == 1) {
        puts("Введено нечетное число. Программа продолжит работу с n = n + 1");
        n = n + 1;
    }
    printf("N / 2 = %d\n", n / 2);

    /* 
     * =======================================================
     * Существует необязательный блок else
     * Код в нем выполнится если условие в скобках if НЕ выполняется
     * Условие в else писать не нужно!
     * =======================================================
     */
    char gender;
    scanf("%c", &gender);
    if (gender == 'M') {
        puts("Пройдите налево");
    } else {
        puts("Пройдите направо");
    }

    /* 
     * =======================================================
     * Блоки else можно комбинировать с условиями
     * Таким образом можно обработать несколько различных условий
     * =======================================================
     */
    int a, b;
    char operator;

    puts("Введите число, символ операции, число через пробел");
    scanf("%d %c %d", &a, &b, &operator);

    int result;
    if (operator == '+') {
        result = a + b;
    } else if (operator == '-') {
        result = a - b;
    } else if (operator == '*') {
        result = a * b;
    } else if (operator == '/') {
        result = a / b;
    }

    printf("%d %c %d = %d\n", result);

    /* 
     * =======================================================
     * Условия в скобках внутри if можно комбинировать
     * A && B - истина когда и A и B - истина
     * A || B - истина когда A или B - истина
     * =======================================================
     */
    char card = 'A';
    char suit = 'S';

    if (card == 'A' && suit == 'S') {
        puts("Ace of spades!");
    }
}
