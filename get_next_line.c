/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:44:36 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/29 10:44:40 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *ft_strdup(char *str)
{
	char *line;
	int i = 0;
	while(str[i])
		i++;
	line = malloc(i + 1);
	i = 0;
	while (str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ps;

	ps = (char *)s;
	i = 0;
	while (n)
	{
		ps[i] = 0;
		i++;
		n--;
	}
}

char *get_next_line(int fd)
{
	char line[100];
	ft_bzero(line, 100);
	int ret = 1;
	char c;
	int i = 0;
	while((ret = read(fd, &c, 1) > 0))
	{
		line[i++] = c;
		if (c == '\n')
			break ;
	}
	if (line[0] == 0)
		return NULL;
	return (ft_strdup(line));
}
