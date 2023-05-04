#include "main.h"


/**
 * *_which - finds program in PATH
 * @argument: pointer to the command to search
 * @environ: pointer to pointer of environment variables
 * Return: pointer to string of path
 */

char *_which(char *argument, char **environ)
{
	char *path,  *token, *suffix_pth = NULL;
	int i = 0;
	struct  stat st;

	path = _ispth(environ);
	token = strtok(path, ":");
	suffix_pth = malloc(sizeof(char) * _strlen(path) + 1);
	if (suffix_pth == NULL)
		exit(-1);
	while (token != NULL)
	{
		_strncpy(suffix_pth, token, _strlen(token) + 1);
		_strcat(suffix_pth, "/");
		_strcat(suffix_pth, argument);
		if (stat(suffix_pth, &st) == 0)
		{
			free(path);
			return (suffix_pth);
		}
		token = strtok(NULL, ":");
		i++;
	}

	free(path);
	free(suffix_pth);
	return (NULL);
}
