/* free_stack.c */
#include "monty.h"

/**
 * free_stack - Frees a doubly linked list
 * @head: Head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *current, *next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
