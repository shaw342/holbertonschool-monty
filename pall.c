#include "monty.h"
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
