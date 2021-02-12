/*
 * Программа отсчета 10 секунд
 * Разработано под лицензией ТГУ
 * г. Томск, 2021, ШСП
 */

#include <stdio.h>
#include <time.h>

int main() {

    int t = 10;
    while ( t > 0 ) {
        printf( "%d...\n", t );
        sleep( 1 );
        t--;
    }

    return 0;
}
