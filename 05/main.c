#include <stdio.h>
#include <stdbool.h>

int main()
{
    int sir = 0;
    int inputvys;
    int input2 = 0;
    int sirnew;
    int circle = 0;
    int star = 0;
    int fenceinput;
    int fence = 0;
    int input3 = 0;
    int row = 0;

    if ((scanf("%d", &sir) == 0))
    {
        fprintf(stderr, "%s", "Error: Chybny vstup!\n");
        return 100;
    }
    int vys = sir;

    switch (scanf("%d", &inputvys))
    {
    case 0:
        fprintf(stderr, "%s", "Error: Chybny vstup!\n");
        return 100;
        break;

    case true:
        vys = inputvys;
        input2 = 1;
        break;

    default:
        break;
    }

    switch (scanf("%d", &fenceinput))
    {
    case 0:
        fprintf(stderr, "%s", "Error: Chybny vstup!\n");
        return 100;
        break;

    case true:
        fence = fenceinput;
        input3 = 1;
        break;

    default:
        break;
    }

    if (sir < 3 || sir > 69 || vys < 3 || vys > 69 || ((input3 == 1) && (fenceinput < 3)) || ((input3 == 1) && (fenceinput > 69)))
    {
        fprintf(stderr, "%s", "Error: Vstup mimo interval!\n");
        return 101;
    }

    if ((input2 == 1) && (sir % 2 != 1))
    {
        fprintf(stderr, "%s", "Error: Sirka neni liche cislo!\n");
        return 102;
    }

    if ((input3 == 1) && (fence >= vys))
    {
        fprintf(stderr, "%s", "Error: Neplatna velikost plotu!\n");
        return 103;
    }
    else
    {
        row = vys - fence;
    }

    switch (input2)
    {
    case 1:
        if (sir % 2 == 1)
        {
            for (int k = 0; k < (sir - 1) / 2; k++)
            {
                printf(" ");
            }
            printf("X\n");
            if (sir != 3)
            {
                sirnew = sir;
                int loop = 1;
                int mez = 1;
                while (sirnew != 3)
                {
                    for (int k = 0; k < ((sir - 1) / 2) - loop; k++)
                    {
                        printf(" ");
                    }
                    printf("X");

                    for (int o = 0; o < mez; o++)
                    {
                        printf(" ");
                    }
                    printf("X\n");
                    mez += 2;
                    loop += 1;
                    sirnew -= 2;
                }
            }
        }
        break;

    default:
        break;
    }

    // Height
    for (int i = 0; i < vys; i++)
    { // Width
        if (i == 0 || i == vys - 1)
        {
            for (int j = 0; j < sir; j++)
            {
                printf("X");
            }
            if ((row == (fence * -1)) && (input3 == 1))
            {
                if (fence % 2 == 0)

                {
                    for (int b = 0; b < fence - 1; b += 2)
                    {
                        printf("-|");
                    }
                }
                else
                {
                    printf("|");
                    for (int b = 1; b < fence; b += 2)
                    {
                        printf("-|");
                    }
                }
            }
            row -= 1;
        }

        // X space X
        else
        {
            printf("X");
            for (int j = 0; j < sir - 2; j++)
            {

                if ((input2 == 0) || (sir != vys))
                {
                    printf(" ");
                }
                else
                {

                    switch (circle)
                    {
                    case 0:
                        printf("o");
                        circle += 1;
                        break;

                    default:
                        if (circle > star)
                        {
                            printf("*");
                            star += 1;
                        }
                        else
                        {
                            printf("o");
                            circle += 1;
                        }
                    }
                }
            }
            printf("X");
            switch (input3)
            {
            case 1:
                if ((row == -1) || (row == (fence * -1)))
                {
                    if (fence % 2 == 0)
                    {
                        for (int b = 0; b < fence - 1; b += 2)
                        {
                            printf("-|");
                        }
                    }
                    else
                    {
                        printf("|");
                        for (int b = 1; b < fence; b += 2)
                        {
                            printf("-|");
                        }
                    }
                }
                else
                {
                    if ((fence % 2 == 0) && (row < -1))
                    {
                        printf(" |");
                        for (int b = 1; b < fence - 1; b += 2)
                        {
                            printf(" |");
                        }
                    }
                    else if (row < -1)

                    {
                        printf("|");
                        for (int b = 1; b < fence - 1; b += 2)
                        {
                            printf(" |");
                        }
                    }
                }
                break;

            default:
                break;
            }
        }
        printf("\n");
        row -= 1;
    }
    return 0;
}
