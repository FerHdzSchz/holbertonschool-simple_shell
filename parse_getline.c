#include "main.h"

/**
 * **parse_line - parse line derived to getline
 * @content: pointer of content of line
 * @sep: string to separate content
 * Return: list of arguments
*/
char **parse_line(char *content, const char *sep)
{
	char **arg_list = NULL;
	char *token = NULL;
	int num_tokens = 0, i = 0, j = 0;

	num_tokens = count_tokens(content, sep);
	token = strtok(content, sep);

	arg_list = malloc(sizeof(char *) * num_tokens + 1);
	if (arg_list == NULL)
	{
		free(arg_list);
		free(token);
		exit(EXIT_FAILURE);
	}

	while (token != NULL)
	{
		arg_list[i] = malloc((sizeof(char) * _strlen(token)) + 1);
		if (arg_list[i] == NULL)
		{
			for (j = 0; j <= i; j++)
			{
				free(arg_list[j]);
			}
			free(arg_list);
			free(token);
			exit(EXIT_FAILURE);
		}
		_strncpy(arg_list[i], token, _strlen(token) + 1);
		token = strtok(NULL, " \n");
		i++;
	}
	free(token);
	arg_list[i] = NULL;
	return (arg_list);
}


/**
 * num_tokens - gets the number of tokens
 * @string: string to parse
 * Return: number of tokens
*/

int count_tokens(char *string, const char *sep)
{
	int n = 0;
	int len = 0;
	char *aux_buf;
	char *token;

	len = _strlen(string);
	aux_buf = malloc(sizeof(char) * len + 1);
	if (aux_buf == NULL)
	{
		free(aux_buf);
		exit(EXIT_FAILURE);
	}
	_strncpy(aux_buf, string, len + 1);
	token = strtok(aux_buf, sep);
	while (token != NULL)
	{
		token = strtok(NULL, sep);
		n++;
	}
	n++;
	free(aux_buf);
	free(token);

	return (n);
}