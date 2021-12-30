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

void	push_back_to_a(int *stack, int *stack_b,
	int *elements_nb, int *b_elements_nb)
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
		if (*elements_nb == 5)
			put_five_to_b(stack, stack_b, elements_nb, b_elements_nb);
		else
			put_bigger_to_b(stack, stack_b, elements_nb, b_elements_nb);
		push_back_to_a(stack, stack_b, elements_nb, b_elements_nb);
	}
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
