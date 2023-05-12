#include "monty.h"
int error = 0;
int main(int argc, char **argv)
{
	FILE *fp;
	char *line = NULL,*token = NULL;
	size_t size = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2) 
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1],"r");

	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	while(getline(&line,&size,fp) != -1 && error != 1) 
	{
		line_number++;
		token = strtok(line,"\n\t");
		if (token ==  NULL || strncmp(token,"#",1) == 0)
			continue;

		if (strcmp(token,"push") ==  0)
		{

			token = strtok(NULL,"\n\t");
			__push(token,&stack, line_number);
		}
		else
		{		
			get_op_func(token,&stack,line_number);
		}

	}
	fclose(fp);
	if (error == 1)
		exit(EXIT_FAILURE);

	return (0);
}
