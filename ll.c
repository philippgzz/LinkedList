//
// Created by Philipp on 16.09.2026.
//

#include "ll.h"
#include <stdlib.h>

void ll_init(LL *list) {
    list->head = NULL;
}

bool ll_push_front(LL *list, double value) {
    ll_node *node = malloc(sizeof(*node));

    node->value = value;
    node->next = list->head;
    list->head = node;

    return true;
}

bool ll_push_back(LL *list, double value) {
    ll_node *node = malloc(sizeof(*node));

    node->value = value;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        return true;
    }

    ll_node *current = list->head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = node;

    return true;
}

bool ll_pop_front(LL *list, double *out_value) {
    ll_node *node = list->head;

    *out_value = node->value;

    list->head = node->next;
    free(node);

    return true;
}

bool ll_pop_back(LL *list, double *out_value) {
    ll_node *current = list->head;
    ll_node *previous = NULL;

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    if (out_value != NULL)
    {
        *out_value = current->value;
    }

    if (previous == NULL) {
        list->head = NULL;
    }
    else {
        previous->next = NULL;
    }

    free(current);

    return true;
}

bool ll_find(LL *list, double value, uint32_t *out_index) {
    ll_node *current = list->head;
    uint32_t index = 0;

    while (current != NULL) {
        if (current->value == value) {
            *out_index = index;
            return true;
        }

        current = current->next;
        index++;
    }

    return false;
}

void ll_clear(LL *list) {
    double value;

    while (ll_pop_front(list, &value)) {
    }
}