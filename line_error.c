#include "main.h"

/**
 * handler - error handler in get line
 * @_chars: number of characters in getline
 * @buff: buffer of getline
 * @cexit: string for exit
 * @cenv: string for printing env
 * @env: enviroment to print
 * Return: int for error
*/

int handler(int _chars, char *buff, char *cexit, char *cenv, char **env)
{
	if (_chars == -1 || _strcmp(buff, cexit) == 0)
	{
		free(buff);
		return (2);
	}
	if (is_empty(buff) == 1)
		return (3);
	if (_strcmp(buff, cenv) == 0)
	{
		_print_env(env);
		return (4);
	}
	return (0);
}
