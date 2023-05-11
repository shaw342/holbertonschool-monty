#include "monty.h"
void __nop(stack_t **stack,unsigned int line_number)
{
	(void) **stack;
	(void) line_number;

}
void __pall(stack_t **stack,unsigned int line_number)
{
	stack_t *h = *stack;

	(void)line_number;
	while(h != NULL)
	{
		printf("%d\n",h->n);
		h = h->next;
	}
}

void __push(char *token, stack_t **stack,unsigned int line_number)
{
	stack_t *newNode = NULL;
	int i;


	if (token == NULL)
	{
		fprintf(stderr,"L%d: usage: push integer",line_number);
		//perror = 1;
		exit(EXIT_FAILURE);

	}
	for(i = 0;token[i] !=  '\0';i++)
	{
		if (isdigit(token[i]) == 0)
		{
			fprintf(stderr,"L%d: usage: push integer",line_number);
			//perror = 1;
			exit(EXIT_FAILURE);
		}
	}

	newNode = malloc(sizeof(stack_t));
	
	if (newNode == NULL)
	{
		fprintf(stderr,"Error: malloc failed");
		//perror = 1;
		exit(EXIT_FAILURE);
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
