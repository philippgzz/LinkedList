#include <stdint.h>
#include <stdio.h>

void leereEingabezeile(void)
{
    int zeichen;

    while ((zeichen = getchar()) != '\n' && zeichen != EOF)
    {
    }
}

void zeigeBits(uint16_t zahl)
{
    int i;

    for (i = 15; i >= 0; i--)
    {
        if ((zahl & ((uint16_t)1 << i)) != 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }

        if (i == 8)
        {
            printf(" ");
        }
    }
}

void zeigeZahl(char name, uint16_t zahl)
{
    printf("%c  Hex: %04X Bits: ", name, (unsigned int)zahl);
    zeigeBits(zahl);
    printf("\n");
}

void zeigeMenue(uint16_t a, uint16_t b)
{
    printf("\n");
    zeigeZahl('A', a);
    zeigeZahl('B', b);

    printf("\n");
    printf("1  A eingeben (Hex)\n");
    printf("2  B eingeben (Hex)\n");
    printf("3  A = A + B\n");
    printf("0  Ende\n");
    printf("Deine Wahl: ");
}

int main(void)
{
    uint16_t a = 0;
    uint16_t b = 0;
    int wahl;

    while (1)
    {
        zeigeMenue(a, b);

        if (scanf("%d", &wahl) != 1)
        {
            leereEingabezeile();
            printf("Bitte eine Zahl aus dem Menue eingeben.\n");
            continue;
        }

        leereEingabezeile();

        if (wahl == 0)
        {
            printf("Programm beendet.\n");
            break;
        }

        switch (wahl)
        {
            case 1:
                printf("Wert fuer A in Hex eingeben: ");

                if (scanf("%hx", &a) != 1)
                {
                    leereEingabezeile();
                    printf("ungueltige Hexzahl.\n");
                }
                else
                {
                    leereEingabezeile();
                }
                break;

            case 2:
                printf("Wert fuer B in Hex eingeben: ");

                if (scanf("%hx", &b) != 1)
                {
                    leereEingabezeile();
                    printf("ungueltige Hexzahl.\n");
                }
                else
                {
                    leereEingabezeile();
                }
                break;

            case 3:
                a = (uint16_t)(a + b);
                zeigeZahl('A', a);
                break;
        }
    }

    return 0;
}