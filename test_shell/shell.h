#ifndef SHELL_PROJECT_H
#define SHELL_PROJECT_H
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#define PS1 "$ "
typedef struct path_link
{
        char *token;
        struct path_link *next;
} link_t;
char *_strncpy(char *dest, char *src, int n);
int _strcmp(const char *s1, const char *s2);
int _strlen(char *s);
char **tokenize_string(char *line);
void execute(char **tokens);
extern char** environ;
void free_list(link_t *head);
char *_getenv(const char *name);
link_t *add_node_end(link_t **head, const char *token);
link_t *path_tok (char *match);
#endif /* SHELL_PROJECT_H */
