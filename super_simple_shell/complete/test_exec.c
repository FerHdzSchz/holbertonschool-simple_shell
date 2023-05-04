#include "main.h"
/**
 * main - test of which
 * @ac: count of args
 * @argv: array of strings that are arguments
 * @env: array of env variables
 * Return: always 1
*/
int main(int ac, char **argv, char **env)
{
	char *ruta_commando;
    char **aux_args;
    int i, num_args;

	if (ac < 2)
	{
		printf("Use: %s command\n", argv[0]);
        exit(-1);
    }


	ruta_commando = _which(argv[1], env);
    if (ruta_commando != NULL)
    {

        argv[1] = malloc(sizeof(char) * _strlen(ruta_commando) + 1);
        _strncpy(argv[1], ruta_commando, _strlen(ruta_commando) + 1);

        num_args = 0;
        while(argv[num_args])
            num_args++;

        aux_args = malloc(sizeof(char *) * num_args);
        for(i = 1; i <= num_args; i++)
            aux_args[i-1] = argv[i];
        printf("%s\n", aux_args[0]);
        if (execve(ruta_commando, aux_args, env) == -1)
        {
            printf("error");
            free(ruta_commando);
            exit (-1);
        }
    }
	free(ruta_commando);
	return (1);
}
