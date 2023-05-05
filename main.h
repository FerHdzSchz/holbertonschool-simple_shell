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
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_which(char *argument, char **environ);
char *_ispth(char **env_vars);
char **parse_line(char *content, const char *sep);
int executer(char **arguments, char *comp_path, char **penv);

#endif
