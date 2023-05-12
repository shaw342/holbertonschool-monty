#include "monty.h"
void __push(char *token,stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = NULL;
	int i;


	if (token == NULL)
	{
		fprintf(stderr,"L%d: usage: push integer",line_number);
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
