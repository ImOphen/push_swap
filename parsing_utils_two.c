#include "push_swap.h"

void exit_error(void)
{
	write(2,"Error\n", 6);
	exit(-1);
}

int next_arg(char *arguments, int j)
{
	j++;
	while(arguments[j])
	{
		if(arguments[j] == ' ' && (ft_isdigit(arguments[j - 1])))
			break ;
		j++;
	}
	return (j);
}

void	fill_stack_with_numbers(int *stack,char *arguments,int count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(count--)
	{
		stack[i++] = ft_atoi(arguments + j);
		j = next_arg(arguments, j);
	}
}

char	*arguments_join(char **argv)
{
	int i;
	char *arguments;
	char *arguments_with_space;

	i = 1;
	arguments = NULL;
	while(argv[i])
	{
		// printf("%s\n",argv[i++]);
		arguments_with_space = ft_strjoin(arguments, " ");
		if (!arguments_with_space)
			exit_error();
		arguments = ft_strjoin(arguments_with_space, argv[i]);
		if (!arguments)
			exit_error();
		i++;
	}
	return(arguments);
}

int *fill_stack(char **argv, int *elements_nb)
{
	char *arguments;
	int count;
	int *stack;

	arguments = arguments_join(argv);
	count = count_words(arguments, ' ');
	stack = malloc(count * sizeof(int));
	if (!stack)
		printf("10"),exit_error();
	fill_stack_with_numbers(stack, arguments, count);
	free(arguments);
	*elements_nb = count;
	return (stack);
}
