/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:44:58 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/29 10:45:01 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(int *stack, int *stack_b, int elements_nb, int b_elements_nb)
{
	reverse_rotate(stack_b, b_elements_nb);
	reverse_rotate(stack, elements_nb);
	write(1, "rrr\n", 4);
}

void	rr(int *stack, int *stack_b, int elements_nb, int b_elements_nb)
{
	rotate(stack_b, b_elements_nb);
	rotate(stack, elements_nb);
	write(1, "rr\n", 3);
}

void	ss(int *stack, int *stack_b)
{
	swap(stack_b);
	swap(stack);
	write(1, "ss\n", 3);
}

void	pa(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	push(stack_b, stack, b_elements_nb, elements_nb);
	write(1, "pa\n", 3);
}

void	pb(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	push(stack, stack_b, elements_nb, b_elements_nb);
	write(1, "pb\n", 3);
}
