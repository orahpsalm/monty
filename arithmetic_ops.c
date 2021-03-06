#include "monty.h"



/**
 * add_func - function which adds values of top two nodes
 *
 * @stack: stack
 *
 * @line_number: line number
 */

void add_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int sum = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	pop_func(stack, line_number);
}



/**
 * sub_func - function that subtracts top element from second top element
 *
 * @stack: stack
 *
 * @line_number: line number
 */

void sub_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int diff = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	diff = temp->next->n - temp->n;
	temp->next->n = diff;
	pop_func(stack, line_number);
}


/**
 * mul_func - function whcih multipliessecond top element of stack with top
 *
 * @stack: stack
 *
 * @line_number: line number
 */

void mul_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int factor = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	factor = temp->next->n * temp->n;
	temp->next->n = factor;
	pop_func(stack, line_number);
}


/**
 * div_func - function which divides second top elem. of stack by top element
 *
 * @stack: stack
 *
 * @line_number: line number
 */

void div_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int quotient = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	quotient = temp->next->n / temp->n;
	temp->next->n = quotient;
	pop_func(stack, line_number);
}
