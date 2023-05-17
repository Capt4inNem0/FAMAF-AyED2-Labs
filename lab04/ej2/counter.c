#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = malloc(sizeof(struct _counter));
    c->count = 0u;
    assert(counter_is_init(c));
    return c;
}

void counter_inc(counter c) {
    c->count++;
}

bool counter_is_init(counter c) {
    return (c != NULL) && (c->count == 0);
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count--;
}

counter counter_copy(counter c) {
    counter q = malloc(sizeof(struct _counter));
    q->count = c->count;
    return (q);
}

void counter_destroy(counter c) {
    free(c);
}
