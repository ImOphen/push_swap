#include "push_swap.h"

void rotate_small(int *stack, int elements_nb)
{
	int smallest;
	int i;
	int smallest_index;

	i = 0;
	smallest = stack[0];
	while(i < elements_nb)
	{
		if (smallest > stack[i])
		{
			smallest = stack[i];
			smallest_index = i;
		}
		i++;
	}
	if (smallest_index > elements_nb / 2)
		while(smallest != stack[0])
			rra(stack, elements_nb);
	else
		while(smallest != stack[0])
			ra(stack, elements_nb);
}

int is_sorted(int *stack, int elements_nb)
{
	int i;

	i = 0;
	while(i < elements_nb - 1)
	{
		if (stack[i] > stack[i + 1])
			return(0);
		i++;
	}
	return(1);
}

void rotate_and_push(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	int i;
	int elements_nb_copy;

	i = 0;
	elements_nb_copy = *elements_nb;
		while(i < elements_nb_copy)
		{
			rotate_small(stack, *elements_nb);
			pb(stack, stack_b, elements_nb, b_elements_nb);
		i++;
		}
}

void sort(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	if (!(is_sorted(stack, *elements_nb)))
	{
		rotate_small(stack, *elements_nb);
		rotate_and_push(stack, stack_b, elements_nb, b_elements_nb);
		while(*b_elements_nb)
			pa(stack,stack_b, elements_nb, b_elements_nb);
	}
	else
	{
		free(stack_b);
		free(stack);
		exit (1);
	}
}

int main(int argc, char *argv[])
{
	int *stack;
	int elements_nb;
	int *stack_b;
	int b_elements_nb;

	b_elements_nb = 0;
	stack = handle_arguments(argc, argv, &elements_nb);
	stack_b = malloc(elements_nb * sizeof(int));
	sort(stack, stack_b, &elements_nb, &b_elements_nb);
	//testing(stack, stack_b, &elements_nb, &b_elements_nb);
	free(stack);
	free(stack_b);
	return (0);
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
