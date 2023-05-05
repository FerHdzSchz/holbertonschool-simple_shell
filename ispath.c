#include "main.h"


/**
 * *_ispth - Function to get path from env
 * @env_vars: Pointer of strings of variables from environment
 * Return: String of PATH variable
*/
char *_ispth(char **env_vars)
{
	int i, j;
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
