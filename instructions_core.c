/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_core.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:44:46 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/29 10:44:49 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	rotate(int *stack, int elements_nb)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = malloc(elements_nb * sizeof(int));
	if (!tmp)
		exit(1);
	while (i < elements_nb - 1)
	{
		tmp[i] = stack[i + 1];
		i++;
	}
	tmp[elements_nb - 1] = stack[0];
	ft_memmove_int(stack, tmp, elements_nb);
	free(tmp);
}

void	reverse_rotate(int *stack, int elements_nb)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = malloc(elements_nb * sizeof(int));
	if (!tmp)
		exit(1);
	while (i < elements_nb - 1)
	{
		tmp[i + 1] = stack[i];
		i++;
	}
	tmp[0] = stack[elements_nb - 1];
	ft_memmove_int(stack, tmp, elements_nb);
	free(tmp);
}

void	push(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb)
{
	if (*elements_nb == 0)
		return ;
	stack_b[*b_elements_nb] = stack[0];
	*b_elements_nb += 1;
	reverse_rotate(stack_b, *b_elements_nb);
	rotate(stack, *elements_nb);
	*elements_nb -= 1;
}

void	ft_memmove_int(void *dest, const void *src, size_t n)
{
	size_t	i;
	int		*psrc;
	int		*pdest;

	psrc = (int *)src;
	pdest = (int *)dest;
	if (!dest || !src)
		return ;
	if (dest > src)
		while (n-- > 0)
			pdest[n] = psrc[n];
	else if (dest < src)
	{
		i = 0;
		while (n--)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
}
