#include "monty.h"


/**
 * free_stack - function that frees a memory stack
 *
 * @head: the head of a stack
 */



void free_stack(stack_t *head)
{
	stack_t *temp;
	
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
