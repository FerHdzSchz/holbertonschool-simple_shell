#include "main.h"

/**
 * *_ispth - Function to get path from env
 * @envp: enviroment
 * Return: String of PATH variable
*/
char *_ispth(char **envp)
{
	size_t i = 0;
	int j = 5;
	char *pth = NULL, *suffix_pth = NULL, *pth_str = NULL;

	pth_str = "PATH=";
	suffix_pth = malloc(sizeof(char) * 6);
	if (suffix_pth == NULL)
	{
		free(suffix_pth);
		exit(EXIT_SUCCESS);
	}
	suffix_pth[5] = '\0';
	i = 0;
	while (envp[i] != NULL)
	{
		_strncpy(suffix_pth, envp[i], 5);
		if (_strcmp(suffix_pth, pth_str) == 0)
		{
			pth = malloc((sizeof(char) * _strlen(envp[i])));
			if (pth == NULL)
			{
				free(pth);
				exit(-1);
			}
			for (j = 5; j <= _strlen(envp[i]); j++)
			{
				pth[j - 5] = envp[i][j];
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
 * @envp: enviroment
 * Return: pointer to string of path
 */

char *_which(char *argument, char **envp)
{
	char *path = NULL,  *token = NULL, *suffix_pth = NULL;
	int i = 0;
	struct  stat st;

	if (stat(argument, &st) == 0 || argument == NULL)
		return (argument);

	path = _ispth(envp);
	token = strtok(path, ":");
	suffix_pth = malloc(sizeof(char) * _strlen(path) + _strlen(argument) + 2);
	if (suffix_pth == NULL)
		exit(-1);
	suffix_pth[0] = '\0';
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

	free(suffix_pth);
	free(path);
	return (NULL);
}

/**
 * copy_env - copy envpment list
 * @env: envpment list
 * Return: copy of env list
*/

char **copy_env(char **env)
{
	size_t i = 0, j = 0, str_len = 0, num_lists = 0;
	char **env_copy = NULL;

	while (env[num_lists] != NULL)
		num_lists++;

	env_copy = malloc((num_lists + 1) * sizeof(char *));
	if (env_copy == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; i < num_lists; i++)
	{
		str_len = strlen(env[i]);
		env_copy[i] = malloc(sizeof(char) * str_len);
		if (env_copy[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(env_copy[j]);
			free(env_copy);
			exit(EXIT_FAILURE);
		}
		_strncpy(env_copy[i], env[i], str_len);
		env_copy[i][str_len - 1] = '\0';
	}
	env_copy[num_lists] = NULL;
	return (env_copy);
}

/**
 * is_empty - checks for all spaces in getline
 * @s: string
 * Return: 1 if all are spaces 0 otherwise
*/

int is_empty(const char *s)
{
	while (*s != '\0')
	{
		if (!isspace((unsigned char)*s))
			return (0);
		s++;
	}
	return (1);
}
