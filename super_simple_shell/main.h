#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int _putchar(char c);
char* read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
#endif
