#include <stdio.h>
#include "ll.h"

int main(void) {
    LL list;
    double value;

    printf("Test\n");
    printf("====\n\n");

    ll_init(&list);

    if (ll_push_back(&list, 10.50)) {
        printf("10.50 hinten eingefuegt.\n");
    }

    if (ll_push_back(&list, 20.75)) {
        printf("20.75 hinten eingefuegt.\n");
    }

    if (ll_push_front(&list, 5.25)) {
        printf("5.25 vorne eingefuegt.\n");
    }

    if (ll_pop_front(&list, &value)) {
        printf("Erstes Element entfernt: %.2f\n", value);
    }

    if (ll_pop_back(&list, &value)) {
        printf("Letztes Element entfernt: %.2f\n", value);
    }

    if (ll_pop_back(&list, &value)) {
        printf("Letztes Element entfernt: %.2f\n", value);
    }

    if (!ll_pop_front(&list, &value)) {
        printf("Liste ist leer.\n");
    }

    return 0;
}