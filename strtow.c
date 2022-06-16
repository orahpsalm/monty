#include "monty.h"
#include "lists.h"




/**
 * free_everything - A function that frees arrays of strings
 *
 * @args: An array of strings to free
 */

void free_everything(char **args)
{
	int i;

	if (!args)
		return;
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}



/**
 * count_word - A helper fxn to count num of words in a string
 *
 * @s: The string to evaluate
 *
 * Return: The number of words
 */

int count_word(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}
	return (w);
}



/**
 * **strtow - Function that splits a string into words
 *
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (Success) or NULL (Error)
 */

char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	len = strlen(str);
	words = count_word(str);
	if (words == 0)
		return (NULL);
	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
	{
		if (isspace(str[i]) || str[i] == '\0' || str[i] == '\n')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}
	matrix[k] = NULL;
	return (matrix);
}
