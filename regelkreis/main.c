//
// Created by Philipp on 27.10.2026.
//

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    double temperatur = 18.0;
    double sollwert = 22.0;
    bool heizungAn = false;
    double hysterese = 0.5;

    for (int minute = 0; minute < 10; minute++) {
        if (temperatur < sollwert - hysterese) {
            heizungAn = true;
        } else {
            heizungAn = false;
        }

        if (heizungAn) {
            temperatur += 0.5;
        } else {
            temperatur -= 0.1;
        }

        printf("%d,%.1f,%d\n", minute, temperatur, heizungAn);
    }

    return 0;
}
