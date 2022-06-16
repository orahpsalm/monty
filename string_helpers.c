#include "monty.h"



/**
 * is_number - fxn whcih checks if input is a num
 *
 * @s: the input to check for its numberhood
 *
 * Return: 1 if number, 0 if not
 */

int is_number(char *s)
{
	int i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (*(s + i) != '\0')
	{
		if (*(s + i) >= '0' && *(s + i) <= '9')
		{
			i++;
		}
		
		else
		{
			return (0);
		}
	}
	
	return (1);
}



/**
 * get_tokens - function which gets the tokens from the line
 *
 * @line: the line from the file
 *
 * @line_number: the line number
 *
 * Return: integer
 */

char *get_tokens(char *line, unsigned int line_number)
{
	char delim[2] = "\n ";
	char *token = NULL;
	char *holder = NULL;

	token = strtok(line, delim);

	if (token == NULL)
		return (NULL);
	holder = strtok(NULL, delim);

	if (holder != NULL)
	{
		if (is_number(holder))
			global_var = atoi(holder);

		else
		{
			printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	else if (holder == NULL && strcmp(token, "push") == 0)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	return (token);
}
