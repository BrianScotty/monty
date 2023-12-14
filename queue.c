#include "monty.h"

/**
 * f_queue - sets format of the data to a queue
 * @head: first node
 * @counter: line number
 * Return: void
 */

void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail of the stack
 * @n: new value
 * @head: first node
 * Return: void
*/

void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *x;

	x = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (x)
	{
		while (x->next)
			x = x->next;
	}
	if (!x)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		x->next = new_node;
		new_node->prev = x;
	}
}
