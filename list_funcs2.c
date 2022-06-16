#include "lists.h"
#include "monty.h"

/**
 * free_dlistint - Function that frees a doubly-linked list
 *
 * @head: pointer to the list to free
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}


/**
 * insert_dnodeint_at_index - This inserts a node at
 * a given index in a doubly-linked list
 *
 * @h: This is a double pointer to the list
 *
 * @idx: The index of node to insert
 *
 * @n: The data to insert
 *
 * Return: The address of the new node, or NULL if failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *new;
	dlistint_t *temp = *h;

	if (idx == 0)
		return (add_dnodeint(h, n));
	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			if (temp->next == NULL)
				return (add_dnodeint_end(h, n));
			new = malloc(sizeof(dlistint_t));
			if (!new || !h)
				return (NULL);
			new->n = n;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}
	return (NULL);
}


/**
 * add_dnodeint_end - This adds new node at end of a doubly-linked list
 *
 * @head: A double pointer to the list
 *
 * @n: The data to insert in new node
 *
 * Return: the address of the new element, NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *temp = *head;

	if (!head)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;
	return (new);
}
