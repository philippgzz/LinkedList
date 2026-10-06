//
// Created by Philipp on 16.09.2026.
//

#include "ll.h"
#include <stdlib.h>

struct LLNode {
    double value;
    LLNode *next;
};


void ll_init(LL *list) {
    list->head = NULL;
}

bool ll_push_front(LL *list, double value) {
    LLNode *node = malloc(sizeof(*node));

    if (node == NULL)
    {
        return false;
    }

    node->value = value;
    node->next = list->head;
    list->head = node;

    return true;
}

bool ll_push_back(LL *list, double value) {
    LLNode *node = malloc(sizeof(*node));
    LLNode *current;

    if (node == NULL)
    {
        return false;
    }

    node->value = value;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        return true;
    }

    current = list->head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = node;

    return true;
}

bool ll_pop_front(LL *list, double *out_value) {
    LLNode *node = list->head;

    if (node == NULL)
    {
        return false;
    }

    if (out_value != NULL)
    {
        *out_value = node->value;
    }

    list->head = node->next;
    free(node);

    return true;
}

bool ll_pop_back(LL *list, double *out_value) {
    LLNode *current = list->head;
    LLNode *previous = NULL;

    if (current == NULL)
    {
        return false;
    }

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