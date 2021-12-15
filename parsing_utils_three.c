#include "push_swap.h"

void	check_for_duplicates(int *stack, int elements_nb)
{
	int i;
	int j;

	i = 0;
	while(i < elements_nb)
	{
		j = 0;
		while (j < elements_nb)
		{
			if (stack[i] == stack[j] && i != j)
			{
				free(stack);
				printf("8"),exit_error();
			}
			j++;
		}
		i++;
	}
}

int *handle_arguments(int argc, char *argv[], int *elements_nb)
{
	int *stack;

	if (argc < 2)
		printf("4"),exit_error();
	check_for_numbers(argv);
	stack = fill_stack(argv, elements_nb);
	check_for_duplicates(stack, *elements_nb);
	return(stack);
}

int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long	count;

	i = 0;
	sign = 1;
	count = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = count * 10 + str[i] - 48;
		i++;
	}
	if ((count * sign) > INT_MAX || (count * sign < INT_MIN))
		printf("9"),exit_error();
	return (count * sign);
}
