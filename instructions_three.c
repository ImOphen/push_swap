/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:45:09 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/29 10:45:12 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrb(int *stack_b, int b_elements_nb)
{
	reverse_rotate(stack_b, b_elements_nb);
	write(1, "rrb\n", 4);
}
