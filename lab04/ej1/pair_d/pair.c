
#include "pair.h"
#include <stdlib.h>

pair_t pair_new(elem x, elem y) {
    pair_t p = malloc(sizeof(struct s_pair_t));
    (p->fst) = x;
    (p->snd) = y;
    return p;
}
/*
 * DESC: Creates a new pair with components (x, y)
 *
 * p = pair_new(x, y);
 *
 * POS: {p --> (x, y)}
 */

elem pair_first(pair_t p) {
    return (p->fst);
}
/*
 * DESC: Returns the first component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  fst = pair_first(p);
 *
 * POS: {fst == x}
 */

elem pair_second(pair_t p) {
    return (p->snd);
}
/*
 * DESC: Returns the second component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  snd = pair_second(p);
 *
 * POS: {snd == y}
 */

pair_t pair_swapped(pair_t p) {
    return pair_new(pair_second(p), pair_first(p));
}
/*
 * DESC: Return a NEW pair with the components of p reversed
 *
 * PRE: {p --> (x, y)}
 *
 *  q = pair_swapped(p)
 *
 * POS: {pair_first(q) == pair_second(p) && pair_second(q) == pair_first(p)}
 *
 */

pair_t pair_destroy(pair_t p) {
    free(p);
    return NULL;
//    return p;
}
/*
 * DESC: Free memory if its necesary
 *
 */
