#ifndef LL_H
#define LL_H

#include <stdbool.h>
#include <stdint.h>

typedef struct LLNode {
    double value;
    struct LLNode *next;
} ll_node;

typedef struct {
    ll_node *head;
} LL;

void ll_init(LL *list);
bool ll_push_front(LL *list, double value);
bool ll_push_back(LL *list, double value);
bool ll_pop_front(LL *list, double *out_value);
bool ll_pop_back(LL *list, double *out_value);
bool ll_find(LL *list, double value, uint32_t *out_index);
void ll_clear(LL *list);

#endif