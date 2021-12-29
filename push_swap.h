/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:46:37 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/29 10:46:42 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

/**** instructions ****/
void	rrr(int *stack, int *stack_b, int elements_nb, int b_elements_nb);
void	rr(int *stack, int *stack_b, int elements_nb, int b_elements_nb);
void	rra(int *stack, int elements_nb);
void	rrb(int *stack_b, int b_elements_nb);
void	ra(int *stack, int elements_nb);
void	rb(int *stack_b, int b_elements_nb);
void	pa(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb);
void	pb(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb);
void	sa(int *stack);
void	sb(int *stack_b);
void	ss(int *stack, int *stack_b);

/**** instructions core ****/
void	swap(int *stack);
void	rotate(int *stack, int elements_nb);
void	reverse_rotate(int *stack, int elements_nb);
void	push(int *stack, int *stack_b, int *elements_nb, int *b_elements_nb);
void	ft_memmove_int(void *dest, const void *src, size_t n);

/**** parsing utils ****/
size_t	ft_strlen(const char *s);
int		ft_isdigit(char c);
int		ft_atoi(const char *str);
void	exit_error(void);
void	ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		count_words(const char *s, char c);
void	check_for_numbers(char **argv);
int		next_arg(char *arguments, int j);
void	fill_stack_with_numbers(int *stack, char *arguments, int count);
char	*arguments_join(char **argv);
int		*fill_stack(char **argv, int *elements_nb);
void	check_for_duplicates(int *stack, int elements_nb);
int		*handle_arguments(int argc, char *argv[], int *elements_nb);

/***** checker utils *****/
char	*get_next_line(int fd);
#endif
