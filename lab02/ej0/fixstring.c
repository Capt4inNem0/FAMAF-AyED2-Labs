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

