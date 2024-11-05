#include <stdio.h>
#include <stdbool.h>

// 212, -78, 5, 16, 32
// Pocet cisel: 5
// Pocet kladnych: 4
// Pocet zapornych: 1
// Procento kladnych: 80.00
// Procento zapornych: 20.00
// Pocet sudych: 4
// Pocet lichych: 1
// Procento sudych: 80.00
// Procento lichych: 20.00
// Prumer: 37.40
// Maximum: 212
// Minimum: -78

int main()
{
    int num;
    double sum = 0;
    int count = 0;
    int poscount = 0;
    int negcount = 0;
    double prpos = 0;
    double prneg = 0;
    int sudcount = 0;
    int lichcount = 0;
    double prsud = 0;
    double prlich = 0;
    double avg = 0;
    int max = 0;
    int min = 0;

    while (scanf("%i", &num) == true)
    {

        if (-10000 > num || 10000 < num)
        {
            printf("\nError: Vstup je mimo interval!\n");
            return 100;
        }
        switch (count)
        {
        case 0:
            printf("%i", num);
            max = num;
            min = num;
            break;

        default:
            printf(", %i", num);
            break;
        }

        count++;

        sum += num;

        if (num > 0)
        {
            poscount++;
        }
        else if (num < 0)
        {
            negcount++;
        }

        switch (num % 2)
        {
        case 0:
            sudcount++;
            break;

        default:
            lichcount++;
            break;
        }
        if (max < num)
        {
            max = num;
        }

        if (num < min)
        {
            min = num;
        }
    }

    prpos = ((double)poscount / count) * 100;
    prneg = ((double)negcount / count) * 100;
    prsud = ((double)sudcount / count) * 100;
    prlich = ((double)lichcount / count) * 100;
    avg = ((double)sum / count);

    switch (count)
    {
    case 0:
        return 0;

    default:
        // // TODO
        printf("\nPocet cisel: %i\n", count);
        // // TODO
        printf("Pocet kladnych: %i\n", poscount);
        // // TODO
        printf("Pocet zapornych: %i\n", negcount);
        // // TODO
        printf("Procento kladnych: %.2f\n", prpos);
        // // TODO
        printf("Procento zapornych: %.2f\n", prneg);
        // // TODO
        printf("Pocet sudych: %i\n", sudcount);
        // // TODO
        printf("Pocet lichych: %i\n", lichcount);
        // // TODO
        printf("Procento sudych: %.2f\n", prsud);
        // // TODO
        printf("Procento lichych: %.2f\n", prlich);
        // // TODO
        printf("Prumer: %.2f\n", avg);
        // // TODO
        printf("Maximum: %i\n", max);
        // // TODO
        printf("Minimum: %i\n", min);

        return 0;
    }
}
