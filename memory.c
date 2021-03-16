#include <stdio.h>

int main() {
    // Любая объявленная переменная лежит в ячейке памяти.
    // Любая ячейка в памяти имеет адрес.
    int variable = 23;

    // Выражения при объявлении переменной int*, char*, long* являются отдельным типом - УКАЗАТЕЛЬ на память.
    // Тип перед звездочкой является "уточниением" какие данные вы будете хранить по этому указателю.
    int* variable_address = &variable;
    // ^                    ^
    // |                    |
    // тип указатель       взятие адреса переменной variable


    // Эквивалентные записи для ввода значения переменной variable.
    // scanf("%d", &variable);
    // scanf("%d", variable_address);
    printf("Введите значение переменной variable: ");
    scanf("%d", &variable);
    printf("variable = %d\n", variable);

    printf("Введите еще раз значение переменной variable: ");
    scanf("%d", variable_address);
    printf("variable = %d\n", variable);


    // Чтение значений по указателю - разыменование.
    printf("variable = %d\n", variable);
    printf("*variable_address = %d\n", *variable_address); // читаем ячейку в памяти с адресом(номером) variable_address
    printf("variable_address = %p\n", variable_address); // выводим номер ячейки, где лежит переменная variable


    // Дополнительную информацию про указатели читайте в array.c
}
