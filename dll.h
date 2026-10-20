//
// Created by Philipp on 19.10.2026.
//

#ifndef DLL_H
#define DLL_H

#include <stdbool.h>
#include <stdint.h>

typedef struct DLLNode {
    double value;
    struct DLLNode *next;
    struct DLLNode *previous;
} dll_node;

typedef struct {
    dll_node *head;
    dll_node *tail;
} DLL;


void dll_init(DLL *list);

bool dll_push_front(DLL *list, double value);
bool dll_push_back(DLL *list, double value);

bool dll_pop_front(DLL *list, double *out_value);
bool dll_pop_back(DLL *list, double *out_value);

bool dll_find(const DLL *list, double value, uint32_t *out_index);
bool dll_remove_at(DLL *list, uint32_t index, double *out_value);

void dll_clear(DLL *list);

#endif
