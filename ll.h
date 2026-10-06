//
// Created by Philipp on 16.09.2026.
//

#ifndef LL_H
#define LL_H

#include <stdbool.h>
#include <stdint.h>

typedef struct LLNode LLNode;

typedef struct {
    LLNode *head;
} LL;

void ll_init(LL *list);
bool ll_push_front(LL *list, double value);
bool ll_push_back(LL *list, double value);
bool ll_pop_front(LL *list, double *out_value);
bool ll_pop_back(LL *list, double *out_value);

#endif