/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:43:45 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/29 10:43:49 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
	}
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}

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

void read_from_pushswap(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!ft_strcmp(line, "pa\n"))
			pa(stack, stack_b, elements_nb, b_elements_nb);
		else if (!ft_strcmp(line, "pb\n"))
			pb(stack, stack_b, elements_nb, b_elements_nb);
		else if (!ft_strcmp(line, "ss\n"))
			ss(stack, stack_b);
		else if (!ft_strcmp(line, "sa\n"))
			sa(stack);
		else if (!ft_strcmp(line, "sb\n"))
			sb(stack_b);
		else if (!ft_strcmp(line, "ra\n"))
			ra(stack, *elements_nb);
		else if (!ft_strcmp(line, "rb\n"))
			rb(stack_b, *b_elements_nb);
		else if (!ft_strcmp(line, "rr\n"))
			rr(stack, stack_b, *elements_nb, *b_elements_nb);
		else if (!ft_strcmp(line, "rrr\n"))
			rrr(stack, stack_b, *elements_nb, *b_elements_nb);
		else if (!ft_strcmp(line, "rrb\n"))
			rrb(stack_b, *b_elements_nb);
		else if (!ft_strcmp(line, "rra\n"))
			rra(stack, *elements_nb);
		else
			exit_error();
		free(line);
		line = get_next_line(0);
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
	read_from_pushswap(stack, stack_b, &elements_nb, &b_elements_nb);
	if (is_sorted(stack, elements_nb))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
