#include "monty.h"

/**
  *f_sub- subtracts first element from the second element
  *@head: first node
  *@counter: line number
  *Return: void
 */

void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *x;
	int sus, nodes;

	x = *head;
	for (nodes = 0; x != NULL; nodes++)
		x = x->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	x = *head;
	sus = x->next->n - x->n;
	x->next->n = sus;
	*head = x->next;
	free(x);
}
