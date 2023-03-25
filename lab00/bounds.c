#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    unsigned int index = 0;
    res.exists = false;
    res.is_lowerbound = true;
    res.is_upperbound = true;
    while (index < length){
        int current_element = arr[index];
        if (value == current_element){
            res.exists = true;
            res.where = index;
        }
        res.is_upperbound = res.is_upperbound && value >= arr[index];
        res.is_lowerbound = res.is_lowerbound && value <= arr[index];
        index ++;
    }
    return res;
}

void get_array(int arr [], unsigned int length){
    unsigned int index = 0;
    while (index < length){
        int new_element;
        printf("Ingrese el elemento n° %u", index +1);
        scanf("%d", &new_element);
        arr[index] = new_element;
        index ++;
    }
}

int get_value(){
    int value;
    printf("Ingrese el valor a buscar");
    scanf("%d", &value);
    return value;
}

int main(void) {
    int a[ARRAY_SIZE];
    get_array(a, ARRAY_SIZE);
    int value=get_value();

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    if (result.is_upperbound){
        printf("El valor es una cota superior.\n");
        if (result.exists){
            printf("El valor es maximo y se encuentra en la posicion %u\n", result.where);
        }
    }
    if (result.is_lowerbound){
        printf("El valor es una cota inferior.\n");
        if (result.exists){
            printf("El valor es minimo y se encuentra en la posicion %u\n", result.where);
        }
    }

    return EXIT_SUCCESS;
}

