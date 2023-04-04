#ifndef ARRAY_HELPERS_H

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

#define ARRAY_HELPERS_H

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath);

void array_dump(int a[], unsigned int length);

#endif