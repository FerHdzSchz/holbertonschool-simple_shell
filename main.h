#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
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
int handler(int _chars, char *buff, char *cexit, char *cenv, char **env);
char *_which(char *argument, char **envp);
char *_ispth(char **envp);
char **copy_env(char **env);
char **parse_line(char *content, const char *sep);
int count_tokens(char *string, const char *sep);
void free_arg_list(char **arg_list);
void execute(char **arguments, char **envp);
char **replace_first(char **arguments, char *replace);
void _print_env(char **envp);
int is_empty(const char *s);
#endif
