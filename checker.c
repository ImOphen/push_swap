/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:48:44 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/30 17:48:48 by atouhami         ###   ########.fr       */
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

void	read_from_pushswap(int *stack, int *stack_b, t_el_nb *el, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		pa(stack, stack_b, &el->elements_nb, &el->b_elements_nb);
	else if (!ft_strcmp(line, "pb\n"))
		pb(stack, stack_b, &el->elements_nb, &el->b_elements_nb);
	else if (!ft_strcmp(line, "ss\n"))
		ss(stack, stack_b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(stack, el->elements_nb);
	else if (!ft_strcmp(line, "rb\n"))
		rb(stack_b, el->b_elements_nb);
	else if (!ft_strcmp(line, "rr\n"))
		rr(stack, stack_b, el->elements_nb, el->b_elements_nb);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(stack, stack_b, el->elements_nb, el->b_elements_nb);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(stack_b, el->b_elements_nb);
	else if (!ft_strcmp(line, "rra\n"))
		rra(stack, el->elements_nb);
	else if (!ft_strcmp(line, "sa\n"))
		sa(stack);
	else if (!ft_strcmp(line, "sb\n"))
		sb(stack_b);
	else
		exit_error();
}

int	main(int argc, char *argv[])
{
	int		*stack;
	int		*stack_b;
	t_el_nb	el;
	char	*line;

	el.b_elements_nb = 0;
	stack = handle_arguments(argc, argv, &(el.elements_nb));
	stack_b = malloc(el.elements_nb * sizeof(int));
	if (!stack_b)
		exit(1);
	line = get_next_line(0);
	while (line && line[0] != '\n')
	{
		read_from_pushswap(stack, stack_b, &el, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stack, el.elements_nb))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack_b);
	free(stack);
}
