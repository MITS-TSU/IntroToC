#include <stdio.h>

int main() {

    /*
     * break - досрочно выйти из цикла
     */
    int attempts = 0;
    int pin;
    puts("Enter PIN");
    scanf("%d", &pin);

    while (pin != 1657) {
        puts("Incorrect PIN");
        if (attempts > 3) {
            puts("Better luck next time!");
            break; // ----->----->----->--
        }                  //             |
        scanf("%d", &pin); //             |
        attempts += 1;     //             |
    } // <-----<-----<-----<-----<-----<--

    /*
     * Не стоит злоупотреблять break!
     * Если есть возможность не использовать
     * break без ущерба читабельности кода -
     * - не используйте break. Распишите условие
     */

    attempts = 0;
    puts("Enter PIN");
    scanf("%d", &pin);

    while (attempts <= 3 && pin != 1657) {
        puts("Incorrect PIN");
        scanf("%d", &pin);
        attempts += 1;
    }

    /*
     * continue - завершить ИТЕРАЦИЮ и перейти
     * СРАЗУ на следующую ИТЕРАЦИЮ
     */
    for (int i = 0; i < 100; i++) { // <--
        if (!(i % 15)) {   //             |
            puts("bzzz!"); //             |
            continue; // ->---->---->-----
        }
        printf("%d\n", i);
    }

    return 0;
}
