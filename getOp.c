#include "monty.h"
int get_op_func(char *line, stack_t **stack,unsigned int line_number)
{
	instruction_t func[] = {
		{"pall", __pall},
		{"nop", __nop},
		{NULL,NULL},
	};
	int i;

	for(i = 0;func[i].opcode != NULL;i++)
	{
		if (strcmp(line,func[i].opcode) == 0)
		{
			func[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}

	fprintf(stderr,"L%d: unknown instruction %s\n",line_number,line);
	error = 1;
	return (EXIT_FAILURE);
}
