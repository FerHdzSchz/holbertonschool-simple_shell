#include "main.h"

int main(int ac, char **argv, char **env)
{
    size_t buffsize = 0;
    int line_chars;
    char *buffer, *complete_path;
    const char *separator = " ";
    pid_t my_pid;

    (void) ac;

    while (1)
    {
        printf("$ ");
        line_chars = getline(&buffer, &buffsize, stdin);
        if (line_chars == -1)
            exit(-1);

        if (_strcmp(buffer,"exit") == 0)
        {
            break;
        }

        argv = malloc(sizeof(char *) * 10);
        argv = parse_line(buffer, separator);
        complete_path = _which(argv[0], env);

        if (complete_path != NULL)
        {
            my_pid = fork();
            if (my_pid == -1)
            {
                exit(-1);
            }
            else if (my_pid == 0)
            {
                argv[0] = malloc(sizeof(char) * _strlen(complete_path) + 1);
                argv[0] = complete_path;

                if(execve(argv[0], argv, env) == -1)
                {
                    free(argv);
                    exit(-1);
                }
            }
            else
            {
                waitpid(my_pid, NULL, 0);
            }
        }
        else
        {
            break;
        }
    }
    return (1);
}

