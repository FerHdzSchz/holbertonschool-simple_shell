#include "main.h"

/**
 * *_ispth - Function to get path from env
 * @env_vars: Pointer of strings of variables from environment
 * Return: String of PATH variable
*/
char *_ispth(char **env_vars)
{
	int i = 0, j = 5;
	char *pth = NULL, *suffix_pth = NULL;

	suffix_pth = malloc(sizeof(char) * 5);
	if (suffix_pth == NULL)
	{
		free(suffix_pth);
		exit(-1);
	}

	i = 0;
	while (env_vars[i] != NULL)
	{
		_strncpy(suffix_pth, env_vars[i], 5);
		if (_strcmp(suffix_pth, "PATH=") == 0)
		{
			pth = malloc((sizeof(char) * _strlen(env_vars[i])) - 4);
			if (pth == NULL)
			{
				free(pth);
				exit(-1);
			}
			for (j = 5; j <= _strlen(env_vars[i]); j++)
			{
				pth[j - 5] = env_vars[i][j];
			}
			break;
		}
		i++;
	}
	free(suffix_pth);
	return (pth);
}

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
		if (_strcmp(token, argument) == 0)
		{
			_strncpy(suffix_pth, argument, _strlen(argument) + 1);
			free(path);
			return (suffix_pth);
		}
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
