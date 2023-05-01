#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x < 0) {
        y = -x;
    } else {
        y = x;
    }
}

int main(void) {
    int a=0, res=0;
    a = -10;
    absolute(a, res);
    printf("%d\n", res);
    return EXIT_SUCCESS;
}

/* El progama no coincide con el del teorico porque y es una variable del scope local de la funcion absolute
 * entonces no se puede modificar la variable a utilizando y * /