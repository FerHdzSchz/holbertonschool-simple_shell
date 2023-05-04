#include "main.h"

int main(int ac, char **argv, char **env)
{
    size_t buffsize = 0;
    int line_chars;
    char *buffer;
    char *complete_path;
    const char *separator = " ";

    (void) ac;

    printf("$");
    line_chars = getline(&buffer, &buffsize, stdin);
    if (line_chars == -1)
        exit(-1);

    argv = malloc(sizeof(char *) * 10);
    argv = parse_line(buffer, separator);
    complete_path = _which(argv[0], env);

    argv[0] = malloc(sizeof(char) * _strlen(complete_path) + 1);
    argv[0] = complete_path;


    if(execve(argv[0], argv, env) == -1)
    {
        exit(-1);
    }
    return (1);
}
