#include <stdio.h>
#include "ll.h"
#include "time.h"

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

    printf("\nGeschwindigkeitstest\n");
    printf("====================\n");

    ll_init(&list);

    clock_t start = clock();

    for (int i = 0; i < 100000; i++) {
        ll_push_back(&list, i);
    }

    clock_t ende = clock();

    double zeit = (double)(ende - start) / CLOCKS_PER_SEC;

    printf("Zeit: %.3f Sekunden\n", zeit);

    return 0;
}