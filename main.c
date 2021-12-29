/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:45:31 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/29 10:45:34 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define PARTS_DEFINE 9

int	is_sorted(int *stack, int elements_nb)
{
	int	i;

	i = 0;
	while (i < elements_nb - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*sort_array_parts(int *stack, int elements_nb)
{
	int	*tab;
	int	i;
	int	j;
	int	tmp;
	int	*parts;

	i = 0;
	tab = malloc(elements_nb * sizeof(int));
	ft_memmove_int(tab, stack, elements_nb);
	while (i < elements_nb)
	{
		j = 0;
		while (j < elements_nb)
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
	i = 0;
	parts = malloc(PARTS_DEFINE * sizeof(int));
	while (i < PARTS_DEFINE)
	{
		parts[i] = tab[elements_nb / PARTS_DEFINE * i];
		i++;
	}
	free(tab);
	return (parts);
}

int	does_have_smaller(int *stack, int elements_nb, int half)
{
	int	i;

	i = 0;
	while (i < elements_nb)
	{
		if (stack[i] < half)
			return (1);
		i++;
	}
	return (0);
}

int	find_closest_biggest(int *stack, int elements_nb, int biggest)
{
	int	i;
	int	closest;
	int	rev_closest;

	i = 0;
	rev_closest = 1;
	while (i < elements_nb)
	{
		if (stack[i] == biggest)
		{
			closest = i;
			break ;
		}
		i++;
	}
	while (elements_nb--)
	{
		if (stack[elements_nb] == biggest)
			break ;
		rev_closest++;
	}
	if (closest < rev_closest)
		return (1);
	else
		return (0);
}

void put_bigger_to_b(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	int	*parts;
	int	i;

	i = PARTS_DEFINE;
	parts = sort_array_parts(stack, *elements_nb);
	while (i--)
	{
		while ((does_have_smaller(stack, *elements_nb, parts[i])))
		{
			if (stack[0] < parts[i])
				pb(stack, stack_b, elements_nb, b_elements_nb);
			else
				ra(stack, *elements_nb);
		}
	}
	free(parts);
}

void	sort_to_bigger(int *stack_b, int b_elements_nb)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = stack_b[0];
	while (i < b_elements_nb)
	{
		if (biggest < stack_b[i])
			biggest = stack_b[i];
		i++;
	}
	if (find_closest_biggest(stack_b, b_elements_nb, biggest))
		while (stack_b[0] != biggest)
			rb(stack_b, b_elements_nb);
	else
		while (stack_b[0] != biggest)
			rrb(stack_b, b_elements_nb);
}

void	push_back_to_a(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	while (*b_elements_nb)
	{
		sort_to_bigger(stack_b, *b_elements_nb);
		pa(stack, stack_b, elements_nb, b_elements_nb);
	}
}

void	sort(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	if (*elements_nb < 2)
		return ;
	else if (*elements_nb == 2)
	{
		if (stack[0] > stack[1])
			ra(stack, 2);
	}
	else if (*elements_nb == 3)
	{
		if (stack[0] > stack[1])
			sa(stack);
		if (!(is_sorted(stack, *elements_nb)))
			rra(stack, *elements_nb);
		if (stack[0] > stack[1])
			sa(stack);
	}
	else if (!(is_sorted(stack, *elements_nb)))
	{
		put_bigger_to_b(stack, stack_b, elements_nb, b_elements_nb);
		push_back_to_a(stack, stack_b, elements_nb, b_elements_nb);
	}
	else
		return ;
}

int	main(int argc, char *argv[])
{
	int	*stack;
	int	elements_nb;
	int	*stack_b;
	int	b_elements_nb;

	b_elements_nb = 0;
	stack = handle_arguments(argc, argv, &elements_nb);
	stack_b = malloc(elements_nb * sizeof(int));
	sort(stack, stack_b, &elements_nb, &b_elements_nb);
	free(stack);
	free(stack_b);
	return (0);
}
