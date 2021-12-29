/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:43:56 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/29 10:44:01 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(int *stack, int *stack_b, int elements_nb, int b_elements_nb)
{
	reverse_rotate(stack_b, b_elements_nb);
	reverse_rotate(stack, elements_nb);
}

void	rr(int *stack, int *stack_b, int elements_nb, int b_elements_nb)
{
	rotate(stack_b, b_elements_nb);
	rotate(stack, elements_nb);
}

void	ss(int *stack, int *stack_b)
{
	swap(stack_b);
	swap(stack);
}

void	pa(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	push(stack_b, stack, b_elements_nb, elements_nb);
}

void	pb(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	push(stack, stack_b, elements_nb, b_elements_nb);
}
