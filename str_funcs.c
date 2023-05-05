#include "main.h"

/**
 * _strcat - Concatenate strings
 * @dest: string appended to
 * @src: string to append
 *
 * Return: Appended string
 */

char *_strcat(char *dest, char *src)
{
	int str_len, j;

	str_len = 0;
	while (dest[str_len] != '\0')
	{
		str_len++;
	}

	j = 0;
	while (src[j] != '\0')
	{
		dest[str_len] = src[j];
		str_len++;
		j++;
	}
	dest[str_len] = '\0';
return (dest);
}

/**
 * _strcmp - Compare two strings
 * @s1: string 1
 * @s2 : string 2
 * Return: 1 if the strings are the same, else print diff
 */

int _strcmp(char *s1, char *s2)
{
	int char_count;

	char_count = 0;

	while (s1[char_count] != '\0' && s2[char_count] != '\0')
	{
		if (s1[char_count] != s2[char_count])
		{
			return (s1[char_count] - s2[char_count]);
		}
	char_count++;
	}
return (0);
}

/**
 * _strlen - Function that returns length of a string
 *
 * @s: string to evaluate
 *
 * Return: length of string to evaluate
 */

int _strlen(char *s)
{
	int s_len = 0;

	while (*s != '\0')
	{
		s++;
		s_len++;
	}
	s_len++;
	return (s_len);
}

/**
 * _strncpy - Function to copy strings
 *
 * @dest: qord 2
 * @src: word 1
 * @n:number of overall chars to copy
 * Return: Copied text
 */
char *_strncpy(char *dest, char *src, int n)
{

int word_letter;

word_letter = 0;
while (src[word_letter] != '\0' && word_letter < n)
{
dest[word_letter] = src[word_letter];
word_letter++;
}
while (word_letter < n)
{
dest[word_letter] = '\0';
word_letter++;
}

return (dest);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
