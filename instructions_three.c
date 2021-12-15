#include "push_swap.h"

void rrb(int *stack_b, int b_elements_nb)
{
	reverse_rotate(stack_b, b_elements_nb);
	write(1, "rrb\n", 4);
}
