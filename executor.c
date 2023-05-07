#include "main.h"

/**
 * execute - executer function
 * @argument_list: list of arguments
*/
void execute(char **argument_list)
{
	int i = 0;
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
		while (argument_list[i] != NULL)
		{
			free(argument_list[i]);
			i++;
		}
		free(argument_list);
	}
	else
	{
		while (argument_list[i] != NULL)
		{
			free(argument_list[i]);
			i++;
		}
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
	size_t len, num_args = 0, i = 1, j = 0;
	char **new_args;

	while (arguments[num_args] != NULL)
		num_args++;

	new_args = malloc((num_args + 1) * sizeof(char *));
	if (new_args == NULL)
		exit(0);

	new_args[num_args] = NULL;

	len = _strlen(replace);

	new_args[0] = malloc(sizeof(char) * len  + 1);
	if (new_args[0] == NULL)
		exit(0);

	_strncpy(new_args[0], replace, len + 1);
	free(arguments[0]);

	while (arguments[i] != NULL)
	{
		len = _strlen(arguments[i]);
		new_args[i] = malloc(sizeof(char) * len + 1);
		if (new_args[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(new_args[j]);
			free(new_args);
		}
		_strncpy(new_args[i], arguments[i], len + 1);
		free(arguments[i]);
		i++;
	}
	free(arguments);
	free(replace);
	return (new_args);
}

/**
 * _print_env - print environment
 *
*/
void _print_env(void)
{
	int i;

	while (environ[i] == NULL)
	{
		printf("%s", environ[i]);
		i++;
	}
}
