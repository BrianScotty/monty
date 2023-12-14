/* addnode.c */
#include "monty.h"

/**
 * addnode - Add a node to the head of the stack
 * @head: Double pointer to the head of the stack
 * @n: New value to be added
 */
void addnode(stack_t **head, int n)
{
stack_t *new_node, *aux;
aux = *head;
new_node = malloc(sizeof(stack_t));

if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
if (aux)
aux->prev = new_node;

new_node->n = n;
new_node->next = *head;
new_node->prev = NULL;
*head = new_node;
}
