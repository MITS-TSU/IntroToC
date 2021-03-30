#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Объявление стуктур:
//
// struct <название> {
//      <список переменных>
// }
//
struct item {
	char         name[256];
	char         description[1024];
    unsigned int price;
};

struct user {
	char         name[256];
	struct item  bag[256];
    int          item_counter;
    unsigned int money;
};


// Функция добавления товара в корзину.
// Вопрос: что будет, если мы будем передавать в функцию не указатель на структуру user?
void add_to_bag(struct user* some_user, struct item some_item) {
    some_user->bag[some_user->item_counter] = some_item;
    // Если то же самое выражение написать без стрелочек:
    // (*some_user).bag[(*some_user).item_counter] = some_item;
    // 
    // Так же обратите внимание, что значение структуры копируется через равно, как обычная переменная.
    // В ранних версиях языка приходилось копировать структуру, копируя каждую структуру.

    some_user->item_counter++;

    printf("Товар %s добавлен в корзину пользователя %s\n", some_item.name, some_user->name);
}

// Функция оформления заказа.
// - считает стоимость всей корзины
// - проверяет, что пользователь может позволить себе эту стоимость.
// - если да, вычитает из денег пользователя полную стоимость корзины, очищает корзину.
// - если нет, ничего не делает -_0_0_-.
void finish_order(struct user* some_user) {
    if (some_user->item_counter == 0) {
        printf("Корзина пользователя %s пуста:(\n", some_user->name);
        return;
    }

    // Считаем итоговую цену всей корзины.
    int total_price = 0;
    for (int i = 0; i < some_user->item_counter; i++) {
        total_price += some_user->bag[i].price;
    }

    printf("total_price = %d\n", total_price);

    if (some_user->money < total_price) {
        printf("Пользователю %s не хватает денег на оформление заказа :(\n", some_user->name);
        return;
    }

    some_user->money -= total_price;
    some_user->item_counter = 0;

    printf("Заказ оплачен!\n");
}

int main() {
    // Инициализация структуры. Вариант 1.
    struct item t_shirt = {"black t_shirt\0", "awesome black t_shirt!\0", 100};
    
    // Инициализация структуры. Вариант 2.
    struct user roma;
    strncpy(roma.name, "chicken_2007\0", 256);
    roma.item_counter = 0;
    roma.money = 100;

    add_to_bag(&roma, t_shirt);
    finish_order(&roma);

    return 0;
}
