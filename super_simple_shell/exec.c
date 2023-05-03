#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(int ac, char **argv, char **environ)
{
    pid_t child_pid;
    int status;
    size_t bufsize = 10;
    int i = 0;
    char *buffer = NULL;
    char *buffer_copy = NULL;
    int characters = 0, num_args = 0;
    char* token;
    char* new_path;

    (void)ac;
    while (1)
    {
        printf("$");
        characters = getline(&buffer, &bufsize, stdin);
        if (characters == -1)
        {
            printf("Unable to get line\n");
            exit(1);
        }

        buffer_copy = malloc(sizeof(char) * characters);
        if (buffer_copy == NULL)
        {
            return (-1);
        }

        _strncpy(buffer_copy, buffer, characters);

        token = strtok(buffer, " \n");

        while (token != NULL)
        {
            num_args++;
            token = strtok(NULL, " \n");
        }
        num_args++;
        argv = malloc(sizeof(char *) * num_args);
        token = strtok(buffer_copy, " \n");
        i = 0;
        while (token != NULL)
        {
            argv[i] = malloc((sizeof(char) * _strlen(token)) + 1);
            _strncpy(argv[i], token, _strlen(token) + 1);
            token = strtok(NULL, " \n");
            i++;
        }
        argv[i] = NULL;


        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            return (-1);
        }
        if (child_pid == 0)
        {
            i = 0;

            while (environ[i] != NULL)
            {
                new_path = environ[i];
                if (execve(new_path, argv, environ) == -1)
                {
                    printf("command not found in : %s\n", new_path);
                    printf("error\n");
                    i++;
                }
                sleep(1);
            }
        }
        else
        {
            wait(&status);
            printf("Oh, it's all better now\n");
        }
    }

    free(argv);
    free(buffer);
    free(buffer_copy);
    return (0);
}
