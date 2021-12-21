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
