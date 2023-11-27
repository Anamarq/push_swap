/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:00:07 by anamarqu          #+#    #+#             */
/*   Updated: 2023/02/19 12:00:08 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct cost_inf
{
	int	min_cost;
	int	pos_min;
}	t_cost;

void	minimum_cost(t_cost *mi, t_info *info, t_stack *stackB)
{
	int	i;
	int	cost;

	i = 0;
	while (i < info->size_b)
	{
		cost = abs(stackB[i].cost_a) + abs(stackB[i].cost_b);
		if (cost < mi->min_cost)
		{
			mi->min_cost = cost;
			mi->pos_min = i;
		}
		++i;
	}
}

void	rotate_one_b(t_stack *stackB, t_info *info, t_cost *mi)
{
	if (stackB[mi->pos_min].cost_b < 0)
	{
		++stackB[mi->pos_min].cost_b;
		reverse_rotate(stackB, info->size_b, 1);
		mi->min_cost = mi->min_cost - 1;
		++mi->pos_min;
		if (mi->pos_min >= info->size_b)
			mi->pos_min = 0;
	}
	else if (stackB[mi->pos_min].cost_b > 0)
	{
		--stackB[mi->pos_min].cost_b;
		rotate(stackB, info->size_b, 1);
		mi->min_cost = mi->min_cost - 1;
		--mi->pos_min;
		if (mi->pos_min < 0)
			mi->pos_min = info->size_b - 1;
	}
}

void	rotate_one(t_stack *stackA, t_stack *stackB, t_info *info, t_cost *mi)
{
	if (stackB[mi->pos_min].cost_a < 0)
	{
		reverse_rotate(stackA, info->size_a, 0);
		mi->min_cost = mi->min_cost - 1;
		++stackB[mi->pos_min].cost_a;
	}
	else if (stackB[mi->pos_min].cost_a > 0)
	{
		rotate(stackA, info->size_a, 0);
		mi->min_cost = mi->min_cost - 1;
		--stackB[mi->pos_min].cost_a;
	}
	else
	{
		rotate_one_b(stackB, info, mi);
	}
}

int	rotate_two(t_stack *stackA, t_stack *stackB, t_info *info, t_cost *mi)
{
	if (stackB[mi->pos_min].cost_a > 0 && stackB[mi->pos_min].cost_b > 0)
	{
		--stackB[mi->pos_min].cost_b;
		--stackB[mi->pos_min].cost_a;
		rotate_rotate(stackA, stackB, info, 1);
		mi->min_cost -= 2;
		--mi->pos_min;
		if (mi->pos_min < 0)
			mi->pos_min = info->size_b - 1;
	}
	else if (stackB[mi->pos_min].cost_a < 0 && stackB[mi->pos_min].cost_b < 0)
	{
		++stackB[mi->pos_min].cost_a;
		++stackB[mi->pos_min].cost_b;
		reverse_reverse(stackA, stackB, info, 1);
		mi->min_cost -= 2;
		++mi->pos_min;
		if (mi->pos_min >= info->size_b)
			mi->pos_min = 0;
	}
	else
		return (-1);
	return (1);
}

//Encontrar el elemento con el coste menor y calcular sus rotate
void	execute_actions(t_stack *stackA, t_stack *stackB, t_info *info)
{
	t_cost	mi;

	mi.min_cost = INT_MAX;
	mi.pos_min = -1;
	minimum_cost(&mi, info, stackB);
	while (mi.min_cost > 0)
	{
		if (rotate_two(stackA, stackB, info, &mi) == -1)
			rotate_one(stackA, stackB, info, &mi);
	}
}
