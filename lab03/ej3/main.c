#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size){
    FILE * file = fopen(path, "r");
    if (file == NULL) {
        fprintf(stderr, "El archivo no existe.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int length = 0u;
    while (!feof(file) && length < max_size){
        unsigned int index_unsafe;
        fscanf(file, "%u -", &index_unsafe);
        if (index_unsafe >= max_size) {
            printf("El indice %u no puede ser almacenado en el espacio actual!\n", index_unsafe);
        } else {
            indexes[length] = index_unsafe;
        }
        fscanf(file, "> *%c*\n", &letters[length]);
        length++;
    }
    fclose(file);
    return length;
}

int main(int agrc, char * argv[]) {
    // FILE *file;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0;

    if (agrc != 2) {
        printf("Uso: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    length = data_from_file(argv[1], indexes, letters, MAX_SIZE);

    for (unsigned int i = 0; i < length; ++i) {
        sorted[indexes[i]] = letters[i];
    }

    dump(sorted, length);

    return EXIT_SUCCESS;
}

