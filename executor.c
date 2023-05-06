#include "main.h"

 /**
  * execute - program to fork and execute
  * @argument_list: list of argumenrs
  *
 */

void execute(char **argument_list)
{
	pid_t my_pid;

	my_pid = fork();
	if (my_pid == -1)
		exit(0);
	else if (my_pid == 0)
	{
		if (execve(argument_list[0], argument_list, environ) == -1)
			exit(EXIT_FAILURE);
		free(argument_list);
		free(argument_list[0]);
	}
	else
		waitpid(my_pid, NULL, 0);
}

char **replace_first(char **arguments, char *replace)
{
	size_t len;

	len = strlen(replace);
	arguments[0] = realloc(arguments[0], sizeof(char) * len);
	if (arguments[0] == NULL)
	{
		free(arguments[0]);
		return(NULL);
	}
	arguments[0][len - 1] = '\0';
	arguments[0] = replace;

	return (arguments);
}