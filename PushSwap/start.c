/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:35:41 by anamarqu          #+#    #+#             */
/*   Updated: 2023/02/19 11:35:43 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//START///
void	initialize(int *a, t_stack *stackA, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stackA[i].value = a[i];
		stackA[i].index = INT_MAX;
		stackA[i].pos = -1;
		stackA[i].target_pos = -1;
		stackA[i].cost_a = 0;
		stackA[i].cost_b = 0;
		++i;
	}
}

void	sort_index(t_stack *stackA, int cnt, int may, int size)
{
	int	i;
	int	menor;

	i = 0;
	menor = may;
	while (i < size)
	{
		if ((stackA[i].value < stackA[menor].value) && stackA[i].index > cnt)
			menor = i;
		++i;
	}
	stackA[menor].index = cnt + 1;
}

void	set_index(t_stack *stackA, int size)
{
	int	i;
	int	idx_mayor;

	i = 0;
	idx_mayor = 0;
	while (i < size)
	{
		if (stackA[i].value > stackA[idx_mayor].value)
			idx_mayor = i;
		++i;
	}
	i = 0;
	while (i < size)
	{
		sort_index(stackA, i, idx_mayor, size);
		++i;
	}
}
///END start///
