#include<stdio.h>
#include<string.h>

int main() {
    char *crypted = "[i`ocai,xc,AEX_,X_Y-";
    int secret = 12;
    for (int i=0; i<strlen(crypted); i++) {
        printf("%c", crypted[i] ^ secret);
    }
    printf("\n");
    return 0;
}
