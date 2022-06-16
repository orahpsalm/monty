#include "monty.h"


/**
 * nop_func - this implements the nop function
 *
 * @stack: the stack
 *
 * @line_number: the line number
 */

void nop_func(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	
	(void) line_number;
}



/**
 * swap_func - function which swaps top two elements of stack
 *
 * @stack: stack
 *
 * @line_number: line number
 */

void swap_func(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;
	stack_t *second = NULL;

	top = *stack;
	
	if (top == NULL || top->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	second = (*stack)->next;

	top->prev = second;
	second->prev = NULL;
	top->next = second->next;
	
	second->next = top;

	*stack = second;
}
