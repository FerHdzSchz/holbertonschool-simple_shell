#include "main.h"

/**
 * **parse_line - parse line derived to getline
 * @content: pointer of content of line
 * @sep: string to separate content
 * Return: list of arguments
*/
char **parse_line(char *content, const char *sep)
{
	char **arg_list;
	char *aux_buffer;
	char *token;
	int num_tokens = 0, i = 0;

	aux_buffer = malloc(sizeof(char) * _strlen(content) + 1);
	_strncpy(aux_buffer, content, _strlen(content) + 1);
	
	token = strtok(aux_buffer, sep);
	while (token != NULL)
	{
		token = strtok(NULL, sep);
		num_tokens++;
	}

	token = strtok(content, sep);
	arg_list = malloc(sizeof(char *) * num_tokens +1);
	while (token != NULL)
		{
			arg_list[i] = malloc((sizeof(char) * _strlen(token)) + 1);
			if (arg_list[i] == NULL)
				exit(-1);
			_strncpy(arg_list[i], token, _strlen(token) + 1);
			token = strtok(NULL, " \n");
			i++;
		}
	arg_list[i] = NULL;
	return(arg_list);
}
