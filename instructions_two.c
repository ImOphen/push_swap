#include "push_swap.h"

void sa(int *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void sb(int *stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void ra(int *stack, int elements_nb)
{
	rotate(stack, elements_nb);
	write(1, "ra\n", 3);
}

void rb(int *stack_b, int b_elements_nb)
{
	rotate(stack_b, b_elements_nb);
	write(1, "rb\n", 3);
}

void rra(int *stack, int elements_nb)
{
	reverse_rotate(stack, elements_nb);
	write(1, "rra\n", 4);
}
