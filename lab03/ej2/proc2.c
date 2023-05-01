#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    if (x < 0) {
        *y = -x;
    } else {
        *y = x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    a = -10;
    absolute(a, &res);
    printf("%d\n", res);
    return EXIT_SUCCESS;
}

/* *y es un parametro de tipo in, luego nosotros utilizamos operadores para modificarlo, pero no podemos modificarlo directamente */

/* C solo tiene parametros in */

