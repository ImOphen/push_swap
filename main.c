#include "push_swap.h"

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

int sort_array_half(int *stack, int elements_nb)
{
	int *tab;
	int i;
	int j;
	int tmp;
	int half;

	i = 0;
	tab = malloc(elements_nb * sizeof(int));
	ft_memmove_int(tab,stack, elements_nb);
	while(i < elements_nb)
	{
		j = 0;
		while(j < elements_nb)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	half = tab[elements_nb / 2];
	free(tab);
	return (half);
}

int does_have_smaller(int *stack, int elements_nb, int half)
{
	int i;

	i = 0;
	while (i < elements_nb)
	{
		if(stack[i] < half)
			return(1);
		i++;
	}
	return (0);

}

int find_closest_smaller(int *stack, int elements_nb, int half)
{
	int i;
	int closest;
	int rev_closest;
	int el_cpy;

	// el_cpy = elements_nb;
	rev_closest = 1;
	i = 0;
	while(i < elements_nb)
		{
			if (stack[i] < half)
			{
				closest = i;
				break;
			}
			i++;
		}
	while(elements_nb--)
		{
			if (stack[elements_nb] < half)
				break;
			rev_closest++;

		}
	if (closest < rev_closest)
		return(1);
	else
		return 0;
}

int find_closest_biggest(int *stack, int elements_nb, int biggest)
{
	int i;
	int closest;
	int rev_closest = 1;

	// el_cpy = elements_nb;
	i = 0;
	while(i < elements_nb)
		{
			if (stack[i] == biggest)
			{
				closest = i;
				break;
			}
			i++;
		}
	while(elements_nb--)
		{
			if (stack[elements_nb] == biggest)
				break;
			rev_closest++;

		}
	if (closest < rev_closest)
		return(1);
	else
		return 0;
}

void put_bigger_to_b(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	int half;

	while(*elements_nb > 2)
		{
			half = sort_array_half(stack, *elements_nb);
			while((does_have_smaller(stack, *elements_nb, half)))
			{
				if (stack[0] < half)
					pb(stack, stack_b, elements_nb, b_elements_nb);
				else
				{
			//		if (find_closest_smaller(stack, *elements_nb, half))
						ra(stack, *elements_nb);
				//	else
			//			rra(stack, *elements_nb);
				}
			}
		}
	if (stack[0] > stack[1])
		sa(stack);
}

void sort_to_bigger(int *stack_b,int b_elements_nb)
{
	int i;
	int biggest;

	i = 0;
	biggest = stack_b[0];
	while(i < b_elements_nb)
	{
		if(biggest < stack_b[i])
			biggest = stack_b[i];
		i++;
	}
	if (find_closest_biggest(stack_b, b_elements_nb, biggest))
		while(stack_b[0] != biggest)
			rb(stack_b, b_elements_nb);
	else
		while(stack_b[0] != biggest)
			rrb(stack_b, b_elements_nb);
}


void push_back_to_a(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	while(*b_elements_nb)
	{
		sort_to_bigger(stack_b, *b_elements_nb);
		pa(stack, stack_b, elements_nb, b_elements_nb);
	}
}

void sort(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{

	if (*elements_nb < 2)
			return ;
	else if (!(is_sorted(stack, *elements_nb)))
	{
		put_bigger_to_b(stack, stack_b, elements_nb, b_elements_nb);
		push_back_to_a(stack, stack_b, elements_nb, b_elements_nb);
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
	testing(stack, stack_b, &elements_nb, &b_elements_nb);
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
