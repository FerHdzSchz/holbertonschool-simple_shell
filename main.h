#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/* GLOBAL VAR*/
extern char **environ;
int _putchar(char c);
char *read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_which(char *argument, char **environ);
char *_ispth(char **env_vars);
char **parse_line(char *content, const char *sep);

#endif
