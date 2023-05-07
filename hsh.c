#include "main.h"
/**
 * main - function to generate a simple shell
 * @ac: number of parameters
 * @argv: list of commands
 * Return: 1
*/
int main(int ac, char **argv)
{
	size_t buffsize = 0;
	int line_chars;
	char *buffer = NULL, *complete_path = NULL, *str_exit = "exit\n";
	struct stat st;
	char **new_argv = NULL;

	(void) ac;
	while (1)
	{
		if (isatty(0))
			printf("$ ");
		line_chars = getline(&buffer, &buffsize, stdin);
		if (line_chars == -1 || _strcmp(buffer, str_exit) == 0)
		{
			free(buffer);
			exit(0);
		}
		if (is_empty(buffer) == 1)
			continue;
		argv = parse_line(buffer, " \n");
		if (stat(argv[0], &st) != 0)
		{
			complete_path = _which(argv[0]);
			if (complete_path == NULL)
			{
				free(complete_path);
				continue;
			}
			new_argv = replace_first(argv, complete_path);
			execute(new_argv);
		}
		else
		{
			execute(argv);
		}
	}
	return (0);
}
