/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:05:28 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/30 11:05:32 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	bubble_sort(int elements_nb, int *tab)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
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
}

int	*sort_array_parts(int *stack, int elements_nb)
{
	int	*tab;
	int	*parts;
	int	i;

	tab = malloc(elements_nb * sizeof(int));
	ft_memmove_int(tab, stack, elements_nb);
	bubble_sort(elements_nb, tab);
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
