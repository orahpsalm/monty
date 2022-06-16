#include "monty.h"
#include "lists.h"



/**
 * pstr_handler - This function handles the pstr instruction
 *
 * @stack: A double-pointer to the stack to push to
 *
 *  @line_number: The number of the line in the file
 */

void pstr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;
	if (!node)
	{
		putchar('\n');
		return;
	}
	while (node && node->n != 0 && node->n >= 0 && node->n <= 127)
	{
		putchar(node->n);
		node = node->next;
	}
	putchar('\n');
}




/**
 * pchar_handler - Function that handles the pchar instruction
 *
 * @stack: A double-pointer to the stack to push to
 *
 * @line_number: The number of the line in the file
 */

void pchar_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (!node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	if (node->n < 0 || node->n > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	putchar(node->n);
	putchar('\n');
}

