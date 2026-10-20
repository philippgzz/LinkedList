#include <stdio.h>
#include <time.h>

#include "ll/ll.h"
#include "dll/dll.h"

int main(void) {
    LL ll_list;
    DLL dll_list;
    double value;

    printf("Linked List\n");

    ll_init(&ll_list);

    if (ll_push_back(&ll_list, 10.50)) {
        printf("10.50 hinten eingefuegt.\n");
    }

    if (ll_push_back(&ll_list, 20.75)) {
        printf("20.75 hinten eingefuegt.\n");
    }

    if (ll_push_front(&ll_list, 5.25)) {
        printf("5.25 vorne eingefuegt.\n");
    }

    if (ll_pop_front(&ll_list, &value)) {
        printf("Erstes Element entfernt: %.2f\n", value);
    }

    if (ll_pop_back(&ll_list, &value)) {
        printf("Letztes Element entfernt: %.2f\n", value);
    }

    if (ll_pop_back(&ll_list, &value)) {
        printf("Letztes Element entfernt: %.2f\n", value);
    }

    ll_clear(&ll_list);


    printf("\nDouble Linked List\n");

    dll_init(&dll_list);

    if (dll_push_back(&dll_list, 10.50)) {
        printf("10.50 hinten eingefuegt.\n");
    }

    if (dll_push_back(&dll_list, 20.75)) {
        printf("20.75 hinten eingefuegt.\n");
    }

    if (dll_push_front(&dll_list, 5.25)) {
        printf("5.25 vorne eingefuegt.\n");
    }

    if (dll_pop_front(&dll_list, &value)) {
        printf("Erstes Element entfernt: %.2f\n", value);
    }

    if (dll_pop_back(&dll_list, &value)) {
        printf("Letztes Element entfernt: %.2f\n", value);
    }

    if (dll_pop_back(&dll_list, &value)) {
        printf("Letztes Element entfernt: %.2f\n", value);
    }

    dll_clear(&dll_list);

    printf("\nGeschwindigkeitstest: 100000-mal push_back\n");
    printf("==========================================\n");

    ll_init(&ll_list);

    clock_t start = clock();

    for (int i = 0; i < 100000; i++) {
        ll_push_back(&ll_list, i);
    }

    clock_t ende = clock();
    double zeit = (double)(ende - start) / CLOCKS_PER_SEC;
    printf("LL-Zeit:  %.3f Sekunden\n", zeit);

    ll_clear(&ll_list);


    dll_init(&dll_list);

    start = clock();

    for (int i = 0; i < 100000; i++) {
        dll_push_back(&dll_list, i);
    }

    ende = clock();
    zeit = (double)(ende - start) / CLOCKS_PER_SEC;
    printf("DLL-Zeit: %.3f Sekunden\n", zeit);

    dll_clear(&dll_list);

    return 0;
}