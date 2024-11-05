#include <stdio.h>

int main()
{
    int x, y, z;

    scanf("%i", &x);
    scanf("%i", &y);
    scanf("%i", &z);

    int des = (y * y) - (4 * x * z);

    if (des < -999 || des > 999)
    {
        printf("Diskriminant mimo povoleny interval!\n");
        return 0;
    }

    printf("+-----+-----+-----+-----+\n");
    printf("|%4d |%4d |%4d |%4d |\n", x, y, z, des);
    printf("+-----+-----+-----+-----+\n");
    switch (des)
    {
    case 0:
        printf("|           Jeden koren |\n");
        break;

    default:
        if (des < 0)
        {
            printf("| Dva imaginarni koreny |\n");
        }
        else
        {
            printf("|     Dva realne koreny |\n");
        }
        break;
    }

    printf("+-----------------------+\n");
    return 0;
}