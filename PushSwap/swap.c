/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:59:51 by anamarqu          #+#    #+#             */
/*   Updated: 2023/01/29 12:59:52 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///Swap///
void	swap(t_stack *stack, int aob)
{
	t_stack	aux;

	aux = stack[0];
	stack[0] = stack[1];
	stack[1] = aux;
	if (aob == 0)
		write(1, "sa\n", 3);
	else if (aob == 1)
		write(1, "sb\n", 3);
}

void	swap_swap(t_stack *stackA, t_stack *stackB, int aob)
{
	swap(stackA, -1);
	swap(stackB, -1);
	if (aob != 3)
		write(1, "ss\n", 3);
}
//END swap
