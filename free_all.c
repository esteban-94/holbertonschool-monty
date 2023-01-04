#include "monty.h"

/**
 * free_all - function to free and leave proper
 * @stack: pointer to head of stack
 * @fd: pointer to file opened
 */

void free_all(stack_t *stack, FILE *fd)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	fclose(fd);
}
