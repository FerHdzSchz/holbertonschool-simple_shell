#include "main.h"

/**
 * execute - executer function
 * @argument_list: list of arguments
 * @envp: environment
*/
void execute(char **argument_list, char **envp)
{
	pid_t my_pid;

	my_pid = fork();
	if (my_pid == -1)
	{
		free_arg_list(argument_list);
		exit(0);
	}
	else if (my_pid == 0)
	{
		if (execve(argument_list[0], argument_list, envp) == -1)
		{
			free_arg_list(argument_list);
			free(argument_list);
			exit(EXIT_FAILURE);
		}
		free_arg_list(argument_list);
	}
	else
	{
		free_arg_list(argument_list);
		waitpid(my_pid, NULL, 0);
	}
}

/**
 * free_arg_list - free memory of arg_list
 * @arg_list: argument lists
*/

void free_arg_list(char **arg_list)
{
	int i =0;

	while (arg_list[i] != NULL)
	{
		free(arg_list[i]);
		i++;
	}
	free(arg_list);
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
 * @envp: environment
*/
void _print_env(char **envp)
{
	int i;

	while (envp[i] == NULL)
	{
		printf("%s", environ[i]);
		i++;
	}
}
