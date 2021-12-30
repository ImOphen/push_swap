/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:13:02 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/30 11:13:03 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_bigger_to_b(int *stack, int *stack_b,
	int *elements_nb, int *b_elements_nb)
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
