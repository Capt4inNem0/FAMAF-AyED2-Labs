#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    unsigned int index = 0;
    while (index < FIXSTRING_MAX && s[index] != '\0') {
        index++;
    }
    return index;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int index = 0;
    bool result = true;
    while (index < FIXSTRING_MAX && result && s1[index] != '\0' && s2[index] != '\0') {
        result = (s1[index] == s2[index]);
        index++;
    }
    return result;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int index = 0;
    bool result = true;
    while (index < FIXSTRING_MAX && s1[index] != '\0' && s2[index] != '\0') {
        if (s1[index] != s2[index]) {
            result = (s1[index] < s2[index]);
            break;
        }
        index++;
    }
    return result;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);
}


