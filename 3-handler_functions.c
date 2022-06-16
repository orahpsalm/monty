#include "monty.h"
#include "lists.h"


/**
 * stack_handler - Function that handles stack instruction
 *
 * @stack: A double-pointer to the stack to push to
 *
 * @line_number: The number of the line in the file
 */

void stack_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 0;
}


/**
 * queue_handler - Function that handles the queue instruction
 *
 * @stack: A double-pointer to the stack to push to
 *
 * @line_number: The number of the line in the file
 */

void queue_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 1;
}


/**
 * rotr_handler - This function handles the rotr instruction
 *
 * @stack: A double-pointer to the stack to push to
 *
 * @line_number: The number of the line in the file
 */

void rotr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0, len = dlistint_len(*stack);

	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}
	temp = get_dnodeint_at_index(*stack, len - 1);
	num = temp->n;
	delete_dnodeint_at_index(stack, len - 1);
	add_dnodeint(stack, num);
}


/**
 * rotl_handler - Function which handles the rotl instruction
 *
 * @stack: A double-pointer to the stack to push to
 *
 * @line_number: The number of the line in the file
 */

void rotl_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num  = 0;

	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}
	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, num);
}
