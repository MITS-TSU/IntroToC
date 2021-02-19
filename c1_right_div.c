/*
 * Программа высчитывает массу кошки,
 * которая бежит со скоростью v и импульсом p
 *
 * Программа работает некорректно когда v = 0
 * (когда кошка сидит на месте)
 */

#include <stdio.h>

int main() {
    float v, p;
    scanf("%f %f", &v, &p); // Считываем v и p

    if (v == 0) {
        printf("Кошка должна двигаться чтобы высчитать массу!\n");
        return 1;
    }

    float mass = p / v;     // Вычисляем массу по определению импульса p = mv
    printf("Кошка весит %.2fкг\n", mass);
    return 0;
}
