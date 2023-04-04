#include "array_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "Error abriendo el archivo '%s'.\n", filepath);
        exit(EXIT_FAILURE);
    }
    unsigned int size = 0;
    fscanf(file, "%u", &size);
    if (size > max_size) {
        fprintf(stderr, "El tamaño máximo permitido es %u.\n", size);
        exit(EXIT_FAILURE);
    }
    unsigned int size_real = 0;
    for (unsigned int i = 0; i < size; i++) {
        int read = fscanf(file, "%d", &array[i]);
        if (read == EOF) {
            fclose(file);
        } else {
            size_real++;
        }
    }
    return size_real;
}

void array_dump(int a[], unsigned int length) {
    printf("[");
    for (unsigned int i = 0; i < length; i++) {
        printf("%d", a[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

bool array_is_sorted(int a[], unsigned int length) {
    bool result = true;

    unsigned int i = 0;
    while (result && i < length - 1) {
        if (a[i] > a[i+1]) {
            result = false;
        }
        i++;
    }

    return result;
}