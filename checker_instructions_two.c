/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:44:25 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/29 10:44:28 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrb(int *stack_b, int b_elements_nb)
{
	reverse_rotate(stack_b, b_elements_nb);
}

void sa(int *stack)
{
	swap(stack);
}

void sb(int *stack_b)
{
	swap(stack_b);
}

void ra(int *stack, int elements_nb)
{
	rotate(stack, elements_nb);
}

void rb(int *stack_b, int b_elements_nb)
{
	rotate(stack_b, b_elements_nb);
}
