#include "push_swap.h"

typedef struct s_quarters{
	int one;
	int two;
	int three;
	int four;
}	t_quarters;

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

t_quarters sort_array_half(int *stack, int elements_nb)
{
	int *tab;
	int i;
	int j;
	int tmp;
	t_quarters quarters;

	i = 0;
	tab = malloc(elements_nb * sizeof(int));
	ft_memmove_int(tab,stack, elements_nb);
	while(i < elements_nb)
	{
		j = 0;
		while(j < elements_nb)
		{
			if (tab[i] < tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	quarters.one = tab[elements_nb / 4 - 1];
	quarters.two = tab[elements_nb / 2 - 1];
	quarters.three = tab[elements_nb / 4 * 3 - 1];
	quarters.four = tab[elements_nb - 1];

	// i = 0;
	// while (i < elements_nb)
	// 	printf("%d ", tab[i++]);
	free(tab);
	return (quarters);
}


void sort(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	int el_nb_cpy;

	el_nb_cpy = *elements_nb;
	if (*elements_nb < 2)
			return ;
	else if (!(is_sorted(stack, *elements_nb)))
	{
		t_quarters quarters;
		quarters = sort_array_half(stack, *elements_nb);
		while(*elements_nb > el_nb_cpy / 4 * 3)
		{
			if (stack[0] > quarters.three)
				pb(stack, stack_b, elements_nb, b_elements_nb);
			else
				ra(stack, *elements_nb);
		}
		while(*elements_nb > el_nb_cpy / 2)
		{
			if (stack[0] > quarters.two)
				pb(stack, stack_b, elements_nb, b_elements_nb);
			else
				ra(stack, *elements_nb);
		}
		while(*elements_nb > el_nb_cpy / 4)
		{
			if (stack[0] > quarters.one)
				pb(stack, stack_b, elements_nb, b_elements_nb);
			else
				ra(stack, *elements_nb);
		}
		//push_back_to_a_2(stack, stack_b, elements_nb, b_elements_nb);
	}
	else
	{
		(void)b_elements_nb;
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