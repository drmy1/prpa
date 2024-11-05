#include <stdio.h>
#include <stdbool.h>

int main()
{
    int count = 1;
    int cur;
    int old = -1;

    while (scanf("%i", &cur) == true)
    {

        if (0 > cur || 100 < cur)
        {
            if (old != cur && count > 1)
            {
                printf("%ix %i\n", count, old);
            }

            printf("Error: Vstup je mimo interval!\n");
            return 100;
        }
        if (cur == old)
        {
            count += 1;
        }
        else if (old != cur && count > 1)
        {
            printf("%ix %i\n", count, old);
            count = 1;
        }

        old = cur;
    }

    switch (count)
    {
    case 0 || 1:
        return 0;
        break;

    default:
        printf("%ix %i\n", count, old);
        break;
    }

    return 0;
}
