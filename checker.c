/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:43:45 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/29 18:23:46 by momayaz          ###   ########.fr       */
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

void	ft_check_cmd(char *cmd)
{
	if (ft_strcmp(cmd, "sa\n") && ft_strcmp(cmd, "sb\n")
		&& ft_strcmp(cmd, "ss\n") && ft_strcmp(cmd, "pa\n")
		&& ft_strcmp(cmd, "pb\n") && ft_strcmp(cmd, "ra\n")
		&& ft_strcmp(cmd, "rb\n") && ft_strcmp(cmd, "rr\n")
		&& ft_strcmp(cmd, "rra\n") && ft_strcmp(cmd, "rrb\n")
		&& ft_strcmp(cmd, "rrr\n"))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
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
	line = get_next_line(0);
	while (line)
	{
		if (line[0] != '\n')
			read_from_pushswap(stack, stack_b, &el, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stack, el.elements_nb))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
