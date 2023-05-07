#include "main.h"

/**
 * execute - executer function
 * @argument_list: list of arguments
*/
void execute(char **argument_list)
{
	pid_t my_pid;

	my_pid = fork();
	if (my_pid == -1)
	{
		free(argument_list);
		exit(0);
	}
	else if (my_pid == 0)
	{
		if (execve(argument_list[0], argument_list, environ) == -1)
			exit(EXIT_FAILURE);
		free(argument_list[0]);
		free(argument_list);
	}
	else
	{
		free(argument_list[0]);
		free(argument_list);
		waitpid(my_pid, NULL, 0);
	}
}

/**
 * replace_first - replaces first item of array of pointers
 * @arguments: list of pointers
 * @replace: pointer to replace first element
 * Return: replaced argument list
*/
char **replace_first(char **arguments, char *replace)
{
	size_t len;

	len = strlen(replace);
	arguments[0] = realloc(arguments[0], sizeof(char) * len);
	if (arguments[0] == NULL)
	{
		return (NULL);
	}
	arguments[0][len - 1] = '\0';
	arguments[0] = replace;

	return (arguments);
}
