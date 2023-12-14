/* div.c */
#include "monty.h"

/**
 * f_div - Divides the top two elements of the stack
 * @head: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void f_div(stack_t **head, unsigned int line_number)
{
stack_t *h;
int len = 0, aux;

h = *head;

/* Count the number of elements in the stack */
while (h)
{
h = h->next;
len++;
}

/* Check if the stack is too short */
if (len < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
h = *head;

/* Check for division by zero */
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

/* Perform the division and update the stack */
aux = h->next->n / h->n;
h->next->n = aux;
*head = h->next;

/* Free the memory of the previous top element */
free(h);
}
