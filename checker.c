#include "push_swap.h"

int main(int argc, char *argv[])
{
	int *stack;
	int elements_nb;
	int *stack_b;
	int b_elements_nb;

	b_elements_nb = 0;
	stack = handle_arguments(argc, argv, &elements_nb);
	stack_b = malloc(elements_nb * sizeof(int));
	testing(stack, stack_b, &elements_nb, &b_elements_nb);
}


void testing(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	int i = 0;
	while (i < *elements_nb)
		printf("STACK A NUM %d : %d\n",i, stack[i]),i++;
	i = 0;
	printf("---------\n");
	while (i < *b_elements_nb)
		printf("STACK B NUM %d : %d\n",i, stack_b[i]),i++;
}
