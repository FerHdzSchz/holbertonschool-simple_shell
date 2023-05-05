#include "main.h"
/**
 * executer - program to execute arguments
 * @arguments: list of arguments
 * @comp_path: complete path of first item in argument list
 * @penv: pointer to pointer to environment variables
 * Return:  Always 0
*/

int executer(char **arguments, char *comp_path, char **penv)
{
	pid_t my_pid;

	my_pid = fork();
	if (my_pid == -1)
		exit(0);
	else if (my_pid == 0)
	{
		if (execve(arguments[0], arguments, penv) == -1)
		{
			arguments[0] = malloc(sizeof(char) * _strlen(comp_path) + 1);
			arguments[0] = comp_path;
			if (execve(arguments[0], arguments, penv) == -1)
			{
				free(comp_path);
				free(arguments[0]);
				free(arguments);
				exit(0);
			}
		}
		free(comp_path);
		free(arguments[0]);
		free(arguments);
		sleep(3);
	}
	else
	{
		waitpid(my_pid, NULL, 0);
	}
	free(comp_path);
	free(arguments[0]);
	free(arguments);

	return (0);
}
