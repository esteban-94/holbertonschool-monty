#include "monty.h"

/**
 *_push - push an integer onto the stack
 *@stack: double pointer to head of stack
 *@line_number: line number of file we are processing
 *
 */

void _push(stack_t **stack, unsigned int line_number)
{
	int data;
	char *arg;

	arg = strtok(NULL, "\n\t ");
	if (arg == NULL || check_digit(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	data = atoi(arg);
	if (add_node(stack, data) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}


/**
 * _pall - prints all value on stack from top to down
 * @stack: double pointer to head of stack
 * @line_number: line number we are executing from script file
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *mover;

	(void)line_number;

	mover = *stack;
	while (mover != NULL)
	{
		printf("%d\n", mover->n);
		mover = mover->next;
		if (mover == *stack)
		{
			return;
		}
	}
}


/**
 *_pint - prints the value at top of stack, followed by newline
 * @stack: double pointer at head of stack
 * @line_number: line number of the file we process on
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (*stack == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		error = 1;
		return;
	}
	printf("%d\n", head->n);
}


/**
 * _pop - function that removes the top element of stack
 * @stack: double pointer to head of stack
 * @line_number: line number of file we process on
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		error = 1;
		return;
	}
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}


/**
 *_swap - swaps the top two elements of stack
 *@stack: double pointer to head of stack
 *@line_number: line number of file we process on
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int swapper;

	if (*stack && (*stack)->next)
	{
		swapper = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = swapper;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		error = 1;
		return;
	}
}
