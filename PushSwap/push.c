/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:59:04 by anamarqu          #+#    #+#             */
/*   Updated: 2023/01/29 12:59:05 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//destino, origen
void	push_a(t_stack *stackA, t_stack *stackB, t_info *info, int aob)
{
	int	i;

	if (info->size_b > 0)
	{
		i = info->size_a;
		while (i > 0)
		{
			stackA[i] = stackA[i - 1];
			--i;
		}
		++info->size_a;
		stackA[0] = stackB[0];
		i = 1;
		while (i < info->size_b)
		{
			stackB[i - 1] = stackB[i];
			++i;
		}
		--info->size_b;
		if (aob != 3)
			write(1, "pa\n", 3);
	}
}

//destino, origen
void	push_b(t_stack *stackB, t_stack *stackA, t_info *info, int aob)
{
	int	i;

	if (info->size_a > 0)
	{
		i = info->size_b;
		while (i > 0)
		{
			stackB[i] = stackB[i - 1];
			--i;
		}
		++info->size_b;
		stackB[0] = stackA[0];
		i = 1;
		while (i < info->size_a)
		{
			stackA[i - 1] = stackA[i];
			++i;
		}
		--info->size_a;
		if (aob != 3)
			write(1, "pb\n", 3);
	}
}
//// END push ////
