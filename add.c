/* add.c */
#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
 */
void add(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;
int len = 0, result;

while (current)
{
current = current->next;
len++;
}

if (len < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
fclose(bus.file);
free(bus.content);
free_stack(*stack);
exit(EXIT_FAILURE);
}

result = (*stack)->n + (*stack)->next->n;
(*stack)->next->n = result;
pop(stack, line_number);
}
