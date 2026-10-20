//
// Created by Philipp on 19.10.2026.
//

#include "dll.h"
#include <stdlib.h>

void dll_init(DLL *list) {
    list->head = NULL;
    list->tail = NULL;
}

bool dll_push_front(DLL *list, double value) {
    dll_node *node = malloc(sizeof(*node));

    if (node == NULL) {
        return false;
    }

    node->value = value;
    node->previous = NULL;
    node->next = list->head;

    if (list->head == NULL) {
        list->tail = node;
    } else {
        list->head->previous = node;
    }

    list->head = node;

    return true;
}

bool dll_push_back(DLL *list, double value) {
    dll_node *node = malloc(sizeof(*node));

    if (node == NULL) {
        return false;
    }

    node->value = value;
    node->next = NULL;
    node->previous = list->tail;

    if (list->tail == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }

    list->tail = node;

    return true;
}

bool dll_pop_front(DLL *list, double *out_value) {
    dll_node *node = list->head;

    if (node == NULL) {
        return false;
    }

    if (out_value != NULL) {
        *out_value = node->value;
    }

    list->head = node->next;

    if (list->head == NULL) {
        list->tail = NULL;
    } else {
        list->head->previous = NULL;
    }

    free(node);

    return true;
}

bool dll_pop_back(DLL *list, double *out_value) {
    dll_node *node = list->tail;

    if (node == NULL) {
        return false;
    }

    if (out_value != NULL) {
        *out_value = node->value;
    }

    list->tail = node->previous;

    if (list->tail == NULL) {
        list->head = NULL;
    } else {
        list->tail->next = NULL;
    }

    free(node);

    return true;
}

bool dll_find(const DLL *list, double value, uint32_t *out_index) {
    dll_node *current = list->head;
    uint32_t index = 0;

    while (current != NULL) {
        if (current->value == value) {
            if (out_index != NULL) {
                *out_index = index;
            }

            return true;
        }

        current = current->next;
        index++;
    }

    return false;
}

bool dll_remove_at(DLL *list, uint32_t index, double *out_value) {
    dll_node *current = list->head;
    uint32_t current_index = 0;

    while (current != NULL && current_index < index) {
        current = current->next;
        current_index++;
    }

    if (current == NULL) {
        return false;
    }

    if (out_value != NULL) {
        *out_value = current->value;
    }

    if (current->previous == NULL) {
        list->head = current->next;
    } else {
        current->previous->next = current->next;
    }

    if (current->next == NULL) {
        list->tail = current->previous;
    } else {
        current->next->previous = current->previous;
    }

    free(current);

    return true;
}

void dll_clear(DLL *list) {
    while (dll_pop_front(list, NULL)) {
    }
}