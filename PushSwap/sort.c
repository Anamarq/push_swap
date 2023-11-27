/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:44:43 by anamarqu          #+#    #+#             */
/*   Updated: 2023/02/19 11:44:45 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//SORT MORE OF 3/////
void	update_pos(t_stack *stackA, t_stack *stackB, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->size_a)
	{
		stackA[i].pos = i;
		++i;
	}
	i = 0;
	while (i < info->size_b)
	{
		stackB[i].pos = i;
		++i;
	}
}

//CostA es el número de movimientos que se necesitan para 
//poner el objetivo al inicio del stack A
//costB igual pero del B
//Mirar si está en la mitad superior (rotate, coste +1) 
//o inferior (reverse rotate, -1) del stack
//Cada paso que se de con r o rr suma o resta 1.
//Se puede hacer mirando la pos y target pos.
void	calculate_costs(t_stack *stackB, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->size_b)
	{
		if (stackB[i].pos <= info->size_b / 2)
			stackB[i].cost_b = stackB[i].pos;
		else
			stackB[i].cost_b = stackB[i].pos - info->size_b;
		if (stackB[i].target_pos <= info->size_a / 2)
			stackB[i].cost_a = stackB[i].target_pos;
		else
			stackB[i].cost_a = stackB[i].target_pos - info->size_a;
		++i;
	}
}

void	final_rotation(t_stack *stackA, t_info *info)
{
	int	i;
	int	id0;

	i = 0;
	id0 = 2;
	while (i < info->size_a / 2)
	{
		if (stackA[i].index == 1)
		{
			id0 = 1;
			break ;
		}
		++i;
	}
	while (stackA[0].index != 1)
	{
		if (id0 == 1)
			rotate(stackA, info->size_a, 0);
		if (id0 == 2)
			reverse_rotate(stackA, info->size_a, 0);
	}
}

void	sort(t_stack *stackA, t_stack *stackB, t_info *info)
{
	int	total_mid;
	int	cnt;

	total_mid = info->size_a / 2;
	cnt = total_mid;
	while (info->size_a > 3)
	{
		if (stackA[0].index <= total_mid || cnt <= 0)
		{
			push_b(stackB, stackA, info, 1);
			--cnt;
		}
		else
			rotate(stackA, info->size_a, 0);
	}
	sort3(stackA, info->size_a);
	while (info->size_b > 0)
	{
		update_pos(stackA, stackB, info);
		calculate_target(stackA, stackB, info);
		calculate_costs(stackB, info);
		execute_actions(stackA, stackB, info);
		push_a(stackA, stackB, info, 0);
	}
	final_rotation(stackA, info);
}
//END SORT MORE OF 3/////