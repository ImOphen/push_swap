/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:45:42 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/29 10:45:45 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*psrc;
	char	*pdest;

	psrc = (char *)src;
	pdest = (char *)dest;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s;
	size_t		s1len;
	size_t		s2len;

	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	s = malloc((s1len + s2len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_memmove(s, s1, s1len);
	ft_memmove(&s[s1len], s2, s2len);
	s[s1len + s2len] = '\0';
	if (s1)
		free((void *)s1);
	return (s);
}

int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && (s[i - 1] == c)))
			count++;
		i++;
	}
	return (count);
}

void	check_for_numbers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ' && argv[i][j] != '-'
			&& !(ft_isdigit(argv[i][j])))
				exit_error();
			if (argv[i][j] == '-' && !(ft_isdigit(argv[i][j + 1])))
				exit_error();
			if ((argv[i][j] == '-' && argv[i][j + 1] == '-')
					|| (ft_isdigit(argv[i][j]) && argv[i][j + 1] == '-'))
				exit_error();
			j++;
		}
		i++;
	}
}
