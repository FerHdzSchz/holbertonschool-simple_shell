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

	if (ac < 2)
	{
		printf("Use: %s command\n", argv[0]);
	}

	ruta_commando = _which(argv[1], env);
	/*
	ruta_commando = _ispth(env);
	*/
	printf("%s", ruta_commando);
	return (1);
}
