#include "monty.h"

void __push(char *token,stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = NULL;
	int i;

	if (token == NULL)
	{
		fprintf(stderr,"L%d: usage: push integer\n",line_number);
		error = 1;
		return;

	}
	for(i = 0;token[i] !=  '\0';i++)
	{
		if (token[i] == '-')
			i++;
		if (isdigit(token[i]) == 0)
		{
			fprintf(stderr,"L%d: usage: push integer\n",line_number);
			error = 1;
			return;
		}
	}

	newNode = malloc(sizeof(stack_t));
	
	if (newNode == NULL)
	{
		fprintf(stderr,"Error: malloc failed\n");
		error = 1;
		return;
	}

	newNode->n = atoi(token);
	newNode->next = NULL;
	newNode->prev = NULL;

	if (*stack)
	{

		(*stack)->prev = newNode;
		newNode->next = *stack;
	}
	*stack = newNode;

}
void __pall(stack_t **stack,unsigned int line_number)
{
	(void) (line_number);
	stack_t *h = *stack;
	while(h != NULL)
	{
		printf("%d\n",h->n);
		h = h->next;
	}
}
void __nop(stack_t **stack,unsigned int line_number)
{
	(void) **stack;
	(void) line_number;
}
void __pint(stack_t **stack,unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr,"L%d: can't pint, stack empty\n",line_number);
		error = 1;
		return;
	}
	printf("%d",(*stack)->n);
}
