#include "shell.h"

/**
 * main - calls functions for shell
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL;
	ssize_t chars_read;
	size_t i;
	ssize_t line_len = 0;
	char **tok_args;
	char *match;
	link_t *head;

	match = _getenv("PATH");
	head = path_tok(match);
//	free_list(head);
	while (head != NULL)
        {
                printf("Here's my list: %s\n", head->token);
                head = head->next;
        }

	while (42)
	{
		write(STDOUT_FILENO, PS1, _strlen(PS1));
		chars_read = getline(&line, &line_len, stdin);
		tok_args = tokenize_string(line);
		execute(tok_args);
		
		free(tok_args);
	}

	return (EXIT_SUCCESS);
}

/**
 * _getenv - tokenizes env variables
 * for variable name and matches it with
 * passed in string
 * @name: name to match
 * Return: matched environmental variable
 */
char *_getenv(const char *name)
{
        char *token;
        char *match;

        while (*environ)
        {
                token = strtok(*environ, "=");
                if(_strcmp(token, name) == 0)
                {
                        match = strtok(NULL, "\0");
                        return (match);
                }
                environ++;
        }
}

/**
 * add_node_end - adds new node to end of link_t list
 * @head: double pointer to head
 * @token: path key value
 * Return: pointer to head
 */
link_t *add_node_end(link_t **head, const char *token)
{
        link_t *temp, *new_node;

        temp = *head;

        new_node = malloc(sizeof(link_t));

        if (new_node == NULL)
                return (NULL);

        new_node->token = strdup(token);
        new_node->next = NULL;

        if (*head == NULL)
        {
                *head = new_node;
                return (*head);
        }

        else
        {
                while (temp->next != NULL)
                        temp = temp->next;

                temp->next = new_node;
        }
        return (*head);
}

/**
 * free_list - free's list_t
 * @head: pointer to head
 */
/*
void free_list(link_t *head)
{
        link_t *temp;

        while (head != NULL)
        {
                temp = head;
                head = temp->next;
                free(temp->token);
                free(temp);
        }
}
*/
/**
 * execute - forks program into parent and child
 * executes input command and flags
 * @tokens: array of tokens
 */
void execute(char **tokens)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	execve(tokens[0], tokens, environ);
	}
	if (pid < 0)
		perror("FORK FAILED");
	
	else
		wait(&status);
}

/**
 * path_tok - tokenizes path variable
 * into its constituent directories separated
 * by colons and calls add_node_end
 * @match: string of path's key
 * Return: pointer head
 */
link_t *path_tok (char *match)
{
        char *token;
        link_t *head = NULL;

        token = strtok(match, ":");
        while (token != NULL)
        {
                printf("Sending token! %s\n", token);
                add_node_end(&head, token);
                token = strtok(NULL, ":");
        }
        return (head);
}

/**
 * tokenize_string - tokenizes input string
 * delimited by whitespaces and stores them
 * in array args
 * @line: input string
 * Return: array args
 */
char **tokenize_string(char *line)
{
	char *token;
	char **args;

	args = malloc(sizeof(char *) * 100);
	
	if (args == NULL)
		return (NULL);

	size_t i = 0;

	token = strtok(line, " \r\t\n");

	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " \n\t\r");
		i++;
	}
	return (args);
}
