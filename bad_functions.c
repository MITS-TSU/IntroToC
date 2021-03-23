#include <stdio.h>

int main() {
    int a[10];
    int b[5];

    // Ввод a, b
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 5; i++) {
        scanf("%d", &b[i]);
    }

    // Вывод массива
    printf("Array [");
    for (int i = 0; i < 10; i++) {
        printf("%d, ", a[i]);
    }
    printf("]\n");

    printf("Array [");
    for (int i = 0; i < 5; i++) {
        printf("%d, ", b[i]);
    }
    printf("]\n");

    // Умножить на 2
    for (int i = 0; i < 10; i++) {
        a[i] *= 2;
    }

    for (int i = 0; i < 5; i++) {
        b[i] *= 2;
    }
    
    // Вывод массива
    printf("Array [");
    for (int i = 0; i < 10; i++) {
        printf("%d, ", a[i]);
    }
    printf("]\n");

    printf("Array [");
    for (int i = 0; i < 5; i++) {
        printf("%d, ", b[i]);
    }
    printf("]\n");

    return 0;
}
