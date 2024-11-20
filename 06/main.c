#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ArrayMaker(char *array, int length)
{
    char input;

    for (int i = 0; i < length; i++)
    {
        switch (scanf("%c", &input))
        {
        case -1:
            fprintf(stderr, "%s", "Error: Chybna delka vstupu!");
            exit(101);

        default:

            switch (input)
            {
            case '\n':
                i--;
                continue;

            default:

                if (input < 65 || (input > 90 && input < 97) || input > 122)
                {

                    fprintf(stderr, "%s", "Error: Chybny vstup!");
                    exit(100);
                }
                else
                {
                    array[i] = input;
                }
            }
        }
    }
}

void shift(char *src, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (src[i] == 'Z')
        {
            src[i] = 'a';
        }
        else if (src[i] == 'z')
        {
            src[i] = 'A';
        }
        else
        {
            src[i] = src[i] + 1;
        }
    }
}

int compare(char *src, char *dst, int length)
{
    int same = 0;
    for (int i = 0; i < length; i++)
    {
        if (src[i] == dst[i])
        {
            same++;
        }
    }
    return same;
}

int main()
{
    int length;
    int bestoffset = 0;

    if ((scanf("%d", &length) == 0))
    {
        fprintf(stderr, "%s", "Error: Chybny vstup!");
        return 100;
    }

    char *cipher = malloc(length * sizeof(char));
    char *ciphertmp = malloc(length * sizeof(char));
    char *listen = malloc(length * sizeof(char));
    ArrayMaker(cipher, length);
    ArrayMaker(listen, length);

    for (int i = 0; i < length; i++)
    {
        ciphertmp[i] = cipher[i];
    }

    int best = 0;
    for (int i = 1; i < 71; i++)
    {
        shift(ciphertmp, length);
        int sametmp = compare(ciphertmp, listen, length);
        if (best < sametmp)
        {
            best = sametmp;
            bestoffset = i;
        }
    }
    for (int i = 0; i < bestoffset; i++)
    {
        shift(cipher, length);
    }

    for (int i = 0; i < length; i++)
    {
        printf("%c", cipher[i]);
    }
    printf("\n");

    free(cipher);
    free(ciphertmp);
    free(listen);
    return 0;
}
