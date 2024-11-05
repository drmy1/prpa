#include <stdio.h>

int main()
{
    int x, y;

    scanf("%i", &x);
    scanf("%i", &y);

    if (x < -10000 || x > 10000 || y < -10000 || y > 10000)
    {
        printf("Vstup je mimo interval!\n");
        return 0;
    }

    printf("Desitkova soustava: %i %i\n", x, y);
    printf("Sestnactkova soustava: %x %x\n", x, y);
    printf("Soucet: %i + %i = %i\n", x, y, x + y);
    printf("Rozdil: %i - %i = %i\n", x, y, x - y);
    printf("Soucin: %i * %i = %i\n", x, y, x * y);

    switch (y)
    {
    case 0:
        printf("Nedefinovany vysledek!\n");
        break;
    default:
        printf("Podil: %i / %i = %i\n", x, y, x / y);
        break;
    }

    double p = (x + y);
    printf("Prumer: %.1f\n", p / 2);
    return 0;
    
}