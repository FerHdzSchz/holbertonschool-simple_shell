#include "main.h"
/**
 * main - function to generate a simple shell
 * @ac: number of parameters
 * @argv: list of commands
 * @env: environmente list
 * Return: 1
*/
int main(int ac, char **argv, char **env)
{
	size_t buffsize = 0;
	int line_chars;
	char *buffer = NULL, *complete_path = NULL;
	const char *separator = " \n";
	struct stat st;

	(void) ac;
	while (1)
	{
		if (isatty(0))
			printf("$ ");
		line_chars = getline(&buffer, &buffsize, stdin);
		if (line_chars == -1 || _strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(0);
		}
		argv = parse_line(buffer, separator);
		complete_path = _which(argv[0], env);
		if (complete_path == NULL && stat(argv[0], &st) != 0)
		{
			free(buffer);
			free(complete_path);
			continue;
		}
		executer(argv, complete_path, env);
	}
	return (0);
}

