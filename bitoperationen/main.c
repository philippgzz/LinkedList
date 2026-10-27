#include <stdint.h>
#include <stdio.h>

void leereEingabezeile(void)
{
    int zeichen;

    while ((zeichen = getchar()) != '\n' && zeichen != EOF)
    {
        /* Rest der Zeile wird verworfen. */
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
    printf("4  A = A UND B\n");
    printf("5  A = A ODER B\n");
    printf("6  A = A XOR B\n");
    printf("7  A = NICHT A\n");
    printf("8  A nach links schieben\n");
    printf("9  A nach rechts schieben\n");
    printf("10 Ein Bit in A setzen\n");
    printf("11 Ein Bit in A loeschen\n");
    printf("12 Ein Bit in A umschalten\n");
    printf("13 Ein Bit in A pruefen\n");
    printf("0  Ende\n");
    printf("Deine Wahl: ");
}

int liesBitnummer(void)
{
    int bitnummer;

    printf("Bitnummer eingeben (0 bis 15): ");

    if (scanf("%d", &bitnummer) != 1)
    {
        leereEingabezeile();
        printf("Ungueltige Eingabe.\n");
        return -1;
    }

    leereEingabezeile();

    if (bitnummer < 0 || bitnummer > 15)
    {
        printf("Die Bitnummer muss zwischen 0 und 15 liegen.\n");
        return -1;
    }

    return bitnummer;
}

int main(void)
{
    uint16_t a = 0;
    uint16_t b = 0;
    int wahl;
    int bitnummer;
    uint16_t maske;

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
                printf("Neuen Wert fuer A in Hex eingeben: ");

                if (scanf("%hx", &a) != 1)
                {
                    leereEingabezeile();
                    printf("Das war keine gueltige Hexzahl.\n");
                }
                else
                {
                    leereEingabezeile();
                }
                break;

            case 2:
                printf("Neuen Wert fuer B in Hex eingeben: ");

                if (scanf("%hx", &b) != 1)
                {
                    leereEingabezeile();
                    printf("Das war keine gueltige Hexzahl.\n");
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

            case 4:
                a = (uint16_t)(a & b);
                zeigeZahl('A', a);
                break;

            case 5:
                a = (uint16_t)(a | b);
                zeigeZahl('A', a);
                break;

            case 6:
                a = (uint16_t)(a ^ b);
                zeigeZahl('A', a);
                break;

            case 7:
                a = (uint16_t)(~a);
                zeigeZahl('A', a);
                break;

            case 8:
                if (b >= 16)
                {
                    a = 0;
                }
                else
                {
                    a = (uint16_t)(a << b);
                }
                zeigeZahl('A', a);
                break;

            case 9:
                if (b >= 16)
                {
                    a = 0;
                }
                else
                {
                    a = (uint16_t)(a >> b);
                }
                zeigeZahl('A', a);
                break;

            case 10:
                bitnummer = liesBitnummer();

                if (bitnummer != -1)
                {
                    maske = (uint16_t)1 << bitnummer;
                    a = (uint16_t)(a | maske);
                    zeigeZahl('A', a);
                }
                break;

            case 11:
                bitnummer = liesBitnummer();

                if (bitnummer != -1)
                {
                    maske = (uint16_t)1 << bitnummer;
                    a = (uint16_t)(a & (uint16_t)~maske);
                    zeigeZahl('A', a);
                }
                break;

            case 12:
                bitnummer = liesBitnummer();

                if (bitnummer != -1)
                {
                    maske = (uint16_t)1 << bitnummer;
                    a = (uint16_t)(a ^ maske);
                    zeigeZahl('A', a);
                }
                break;

            case 13:
                bitnummer = liesBitnummer();

                if (bitnummer != -1)
                {
                    maske = (uint16_t)1 << bitnummer;

                    if ((a & maske) != 0)
                    {
                        a = 1;
                    }
                    else
                    {
                        a = 0;
                    }

                    zeigeZahl('A', a);
                }
                break;

            default:
                printf("Diesen Menuepunkt gibt es nicht.\n");
                break;
        }
    }

    return 0;
}