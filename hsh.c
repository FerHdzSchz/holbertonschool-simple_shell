#include "main.h"
/**
 * main - function to generate a simple shell
 * @ac: number of parameters
 * @argv: list of commands
 * @env: environmente list
 * Return: 1
*/
int main(int ac, char **argv)
{
	size_t buffsize = 0;
	int line_chars;
	char *buffer = NULL, *complete_path = NULL;
	const char *separator = " \n";
	pid_t my_pid;
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

		complete_path = _which(argv[0], environ);
		if (complete_path == NULL && stat(argv[0], &st) != 0)
			{
			free(buffer);
			free(complete_path);
			continue;
			}
		my_pid = fork();
		if (my_pid == -1)
			exit(0);
		else if (my_pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				argv[0] = malloc(sizeof(char) * _strlen(complete_path) + 1);
				argv[0] = complete_path;
				if (execve(argv[0], argv, environ) == -1)
				{
					free(complete_path);
					free(argv[0]);
					free(argv);
					exit(0);
				}
			}
			free(argv);
			free(argv[0]);
			free(complete_path);
			free(buffer);
			sleep(3);
		}
		else
		{
			waitpid(my_pid, NULL, 0);
		}
		free(complete_path);
		free(argv[0]);
		free(argv);
	}
	return (0);
}

