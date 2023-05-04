
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * getnprint - get command from user and print it back
 *
*/

int main()
{
    char *buffer;
    size_t bufsize = 10;
    int characters;
    char *token;

    buffer = malloc(sizeof(char) * bufsize);

    if (buffer == NULL)
    {
        printf("Unable to allocate memory\n");
        exit(1);
    }

    printf("$");
    characters = getline(&buffer, &bufsize, stdin);
    if (characters == -1)
    {
        printf("Unable to get line\n");
        exit(1);
    }
    printf("%s\n", buffer);
    token = strtok(buffer, " ");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;

}
