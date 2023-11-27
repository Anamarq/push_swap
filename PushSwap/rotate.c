/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:00:33 by anamarqu          #+#    #+#             */
/*   Updated: 2023/01/29 13:00:34 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ROTATE //
void	rotate(t_stack *stack, int size, int aob)
{
	int		i;
	t_stack	aux;

	i = 1;
	aux = stack[0];
	while (i < size)
	{
		stack[i - 1] = stack[i];
		++i;
	}
	stack[i - 1] = aux;
	if (aob == 0)
		write(1, "ra\n", 3);
	else if (aob == 1)
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack *stack, int size, int aob)
{
	int		i;
	t_stack	aux;

	i = size - 1;
	aux = stack[size - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		--i;
	}
	stack[0] = aux;
	if (aob == 0)
		write(1, "rra\n", 4);
	else if (aob == 1)
		write(1, "rrb\n", 4);
}

void	rotate_rotate(t_stack *stackA, t_stack *stackB, t_info *info, int aob)
{
	rotate(stackA, info->size_a, -1);
	rotate(stackB, info->size_b, -1);
	if (aob != 3)
		write(1, "rr\n", 3);
}

void	reverse_reverse(t_stack *stackA, t_stack *stackB, t_info *info, int b)
{
	reverse_rotate(stackA, info->size_a, -1);
	reverse_rotate(stackB, info->size_b, -1);
	if (b != 3)
		write(1, "rrr\n", 4);
}
// END ROTATE //
