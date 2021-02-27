#include <stdio.h>

int main() {
    /*
     * Оператор switch используется тогда,
     * когда необходимо обработать более 2-ух
     * значений, например:
     */
    char operator;
    int a, b;

    scanf("%d %c %d", &a, &operator, &b);

    /*
     * Каждая ветка switch обрабатывает отдельный случай (case) значения
     * внутри switch. Каждая ветвь завершается ключевым словом break
     */

    int result;
    switch (operator) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
    }
    printf("Result is %d\n", result);


    /*
     * Switch может включать ветку "по умолчанию"
     * Некий аналог else в if
     */
    char suit = 'S'
    switch (suit) {
        case 'S':
            puts("Spades!");
            break;
        case 'C':
            puts("Clubs!");
            break;
        case 'H':
            puts("Hearts!");
            break;
        case 'D':
            puts("Diamonds!");
            break;
        default:
            puts("Неизвестная масть...");
            break;
    }
    return 0;
}
