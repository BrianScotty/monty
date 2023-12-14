/* execute.c */
#include "monty.h"

/**
 * execute - Executes the opcode
 * @content: Line content from the Monty file
 * @stack: Double pointer to the head of the stack
 * @counter: Line counter in the Monty file
 * @file: Pointer to the Monty file
 * Return: 0 if the line is a comment, 1 otherwise
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
instruction_t instructions[] = {
        {"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", f_add},
        {"nop", f_nop},
        {"sub", f_sub},
        {"div", f_div},
        {"mul", f_mul},
        {"mod", f_mod},
        {"pchar", f_pchar},
        {"pstr", f_pstr},
        {"rotl", f_rotl},
        {"rotr", f_rotr},
        {"queue", f_queue},
        {"stack", f_stack},
        {NULL, NULL}
};

unsigned int i = 0;
char *op;

op = strtok(content, " \n\t");

if (op && op[0] == '#')
return 0; /* Line is a comment */

bus.arg = strtok(NULL, " \n\t");

while (instructions[i].opcode && op)
{
if (strcmp(op, instructions[i].opcode) == 0)
{
instructions[i].f(stack, counter);
return 1; /* Line is not a comment */
}
i++;
}
if (op && instructions[i].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE);
}
return 1; /* Line is not a comment */
}
