#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int pivot = izq;
    unsigned int i = izq + 1u;
    unsigned int j = der;
    while (i <= j) {
        if (fstring_less_eq(a[i], a[pivot])) {
            i++;
        } else if (fstring_less_eq(a[pivot], a[j])) {
            j--;
        } else {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a, pivot, j);
    return j;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int pivot;
    if (izq < der) {
        pivot = partition(a, izq, der);
        quick_sort_rec(a, izq, pivot);
        quick_sort_rec(a, pivot+1u, der);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

static unsigned int partition_len(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int pivot = izq;
    unsigned int i = izq + 1u;
    unsigned int j = der;
    while (i <= j) {
        if (fstring_length(a[i]) < fstring_length(a[pivot])) {
            i++;
        } else if (fstring_length(a[pivot]) < fstring_length(a[j])) {
            j--;
        } else {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a, pivot, j);
    return j;
}

static void quick_sort_rec_len(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int pivot;
    if (izq < der) {
        pivot = partition_len(a, izq, der);
        quick_sort_rec_len(a, izq, pivot);
        quick_sort_rec_len(a, pivot+1u, der);
    }
}

void quick_sort_len(fixstring a[], unsigned int length) {
    quick_sort_rec_len(a, 0, (length == 0) ? 0 : length - 1);
}


