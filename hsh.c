#include "main.h"
/**
 * main - function to generate a simple shell
 * @ac: number of parameters
 * @argv: list of commands
 * @env: environment
 * Return: 1
*/
int main(int ac, char **argv, char **env)
{
	size_t buffsize = 0;
	int line_chars, error_h;
	char *buff = NULL, *c_pth = NULL, *str_exit = "exit\n", *str_env = "env\n";
	struct stat st;
	char **new_argv = NULL;

	(void) ac;
	while (1)
	{
		if (isatty(0))
			printf("$ ");
		line_chars = getline(&buff, &buffsize, stdin);
		error_h = handler(line_chars, buff, str_exit, str_env, env);
		if (error_h == 3)
			continue;
		if (error_h == 2)
			exit(0);
		argv = parse_line(buff, " \n");
		if (stat(argv[0], &st) != 0)
		{
			c_pth = _which(argv[0], env);
			if (c_pth == NULL)
			{
				if (execve(argv[0], argv, env) == -1)
				{
					free_arg_list(argv);
					free(c_pth);
					continue;
				}
			}
			new_argv = replace_first(argv, c_pth);
			execute(new_argv, env);
		}
		else
			execute(argv, env);
	}
	return (0);
}
