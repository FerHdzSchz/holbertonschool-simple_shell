#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int i;

    printf("Number of args: %i\n\n", ac);
    for (i = 1; av[i] != NULL; i++)
    {
        printf("%s\n", av[i]);
    }

    return(0);
}

