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
	int line_chars, global_counter = 0, repl_counter = 0;
	char *buffer = NULL, *complete_path = NULL, *str_exit = "exit\n";
	struct stat st;

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
				free(buffer);
				free(argv[0]);
				free(argv);
				free(complete_path);
				continue;
			}
			replace_first(argv, complete_path);
			repl_counter++;
			printf("%i\n", repl_counter);
		}
		execute(argv);
		global_counter++;
		printf("global_counter: %i\n", global_counter);
	}
	return (0);
}
