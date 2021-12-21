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

char *get_next_line(int fd)
{
	char line[8000000] = {0};
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
