#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NORMAL  "\x1b[0m"
#define RED     "\x1b[91m"
#define GREEN   "\x1b[32m"
#define BLUE    "\x1b[34m"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    char buffer[1024];
    int size;
    char current;

    if (argc == 1)
    {
        printf("Insert the Christmas tree height: ");
        scanf("%s", &buffer);

        if(!(size = atoi(buffer)))
        {
            printf("Invalid value\n");
            return EXIT_FAILURE;
        }
    }
    else
    {
        size = atoi(argv[1]);
        if (size == 0)
        {
            fputs("Invalid argument\n", stdout);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = size-1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++) 
            putchar(' ');
        
        if (i % 2)
        {
            printf(GREEN);
            for (int j = i; j < 1 + 2*(size-1) - i; j++)
                putchar('*');
        }
        else
        {
            printf(BLUE);
            for (int j = i; j < 1 + 2*(size-1) - i; j++)
                printf(rand()%10 ? "~" : RED"o"BLUE);
        }

        putchar('\n');
    }

    printf(NORMAL);

    for (int i = 0; i < size/3; i++)
    {
        for (int j = 0; j < size - 1 - size/6; j++)
            putchar(' ');
        for (int j = 0; j < 1 + 2*(size/6); j++)
            putchar('|');

        putchar('\n');
    }

    return EXIT_SUCCESS;
}
