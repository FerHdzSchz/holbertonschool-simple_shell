#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * _which - finds program in PATH
 * 
 */

int main(int ac, char **argv, char **env)
{
    unsigned int i;
    struct  stat st;
    char *pth;

    if (ac < 2)
    {
        printf ("Usage: %s path_to_file...\n", argv[0]);
    }

    i = 0;

    while (env[i])
    {
        _strncpy(pth, env[i], 5);
        if (pth == "PATH")
        {
            printf("PATH: \n%s", pth);
        }

        i++;
    }

    i = 1;
    while (argv[i])
    {
        if (stat(argv[i], &st) == 0)
        {
            printf("FILE FOUND\n");
        }
        else
        {
            printf("FILE NOT FOUND\n");
        }
        i++;
    }
    return (0);
}