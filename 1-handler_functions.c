#include "lists.h"
#include "monty.h"


/**
 * nop_handler - Function that handles the nop instruction
 *
 * @stack: A double-pointer to the stack to push to
 *
 * @line_number: The number of the line in the file
 */

void nop_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * add_handler - This handles the add instruction
 *
 * @stack: A double-pointer to the stack to push to
 *
 * @line_number: The number of the line in the file
 */

void add_handler(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	sum = node_0->n + node_1->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, sum);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}


/**
 * swap_handler - Function which handles the swap instruction
 * @stack: A double-pointer to the stack to push to
 * @line_number: The number of the line in the file
 */

void swap_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *node = NULL;
	int num;

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_dnodeint_at_index(stack, 0);
	node = insert_dnodeint_at_index(stack, 1, num);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}


/**
 * pop_handler - Function that handles the pop instruction
 *
 * @stack: A double-pointer to the stack to push to
 *
 * @line_number: The number of the line in the file
 */

void pop_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(stack, 0);
}


/**
 * pint_handler - This function handles the pint instruction
 *
 * @stack: A double-pointer to the stack to push to
 *
 * @line_number: The number of the line in the file
 */

void pint_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!head)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
