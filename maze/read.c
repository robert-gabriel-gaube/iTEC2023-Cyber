#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *f = fopen("pictor_olanda.png", "rb");
    char x;
    while(fread(&x, 1, 1, f) == 1) {
        printf("%c", x);
    }

    puts("");
    fclose(f);
    return 0;
}