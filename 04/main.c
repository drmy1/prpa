#include <stdio.h>
#include <stdbool.h>

int main()
{
    int countsum = 0;
    int count = 0;
    char cur;
    int encrypted = 0;
    char old = 0;

    while (scanf("%c", &cur) == true)
    {
        switch (cur)
        {
        case 10:
            break;

        default:
            if ('A' > cur || 'Z' < cur)
            {
                switch (count)
                {
                case 0:
                    break;
                case 1:
                    printf("%c", old);
                    break;

                case 2:
                    printf("%c", old);
                    break;
                default:
                    printf("%i\n", count);
                    break;
                }
                // printf("%c", 10);
                fprintf(stderr, "%s", "Error: Neplatny symbol!\n");
                return 100;
            }
            if (old == cur)
            {
                switch (count)
                {
                case 255:
                    printf("%i", count);
                    encrypted += 3;
                    old = 0;
                    count = 0;

                    break;

                default:
                    count += 1;
                    break;
                }
            }
            if (old != cur)
            {
                switch (count)
                {
                case 0:
                    printf("%c", cur);
                    encrypted += 1;
                    count += 1;
                    break;

                case 1:
                    printf("%c", cur);
                    encrypted += 1;
                    count = 1;
                    break;

                case 2:
                    printf("%c%c", old, cur);
                    encrypted += 2;
                    count = 1;
                    break;

                default:
                    printf("%i%c", count, cur);
                    if (count >= 10)
                    {
                        encrypted += 3;
                        count = 1;
                    }
                    else if (count >= 100)
                    {
                        encrypted += 4;
                        count = 1;
                    }
                    else
                    {
                        encrypted += 2;
                        count = 1;
                    }
                    break;
                }
            }

            old = cur;
            countsum += 1;
            break;
        }
    }

    switch (count)
    {

    case 1:
        printf("%c", cur);
        // encrypted += 1;
        break;

    case 2:
        printf("%c\n", cur);
        encrypted += 1;
        break;

    default:
        printf("%i\n", count);
        if (count >= 10)
        {
            encrypted += 2;
        }
        else if (count >= 100)
        {
            encrypted += 3;
        }
        else
        {
            encrypted += 1;
        }
        break;
    }
    // printf("%c", 10);
    fprintf(stderr, "Pocet vstupnich symbolu: %i\nPocet zakodovanych symbolu: %i\nKompresni pomer: %.2f\n", countsum, encrypted, (float)encrypted / (float)countsum);
    return 0;
}
