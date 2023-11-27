/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:58:32 by anamarqu          #+#    #+#             */
/*   Updated: 2023/02/19 12:58:33 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct data_target
{
	int	i;
	int	dif_min;
	int	dif_index;
	int	pos_obj;
	int	pos_id_min_a;
}	t_data_target;

//Para cada elemento del stack B, miro su índice y busco su superior 
//o el más cercano superior en el stack A. 
//Guardo la pos del stack A en la target pos de la B.
//Si un elemento del stack B ya es superior, 
//buscar el índice más bajo y guardar la pos.
void	calculate_target2(t_stack *stackA, t_stack *stackB, t_info *info,
	t_data_target *dt)
{
	int	j;

	j = 0;
	while (j < info->size_a)
	{
		if (stackA[j].index < stackA[dt->pos_id_min_a].index)
			dt->pos_id_min_a = j;
		dt->dif_index = stackA[j].index - stackB[dt->i].index;
		if (dt->dif_index < dt->dif_min && dt->dif_index > 0)
		{
			dt->dif_min = dt->dif_index;
			dt->pos_obj = stackA[j].pos;
		}
		++j;
	}
}

void	calculate_target(t_stack *stackA, t_stack *stackB, t_info *info)
{
	t_data_target	dt;

	dt.dif_min = INT_MAX;
	dt.i = 0;
	dt.pos_obj = -1;
	dt.pos_id_min_a = 0;
	while (dt.i < info->size_b)
	{
		calculate_target2(stackA, stackB, info, &dt);
		if (dt.pos_obj == -1)
			dt.pos_obj = dt.pos_id_min_a;
		dt.dif_min = INT_MAX;
		stackB[dt.i].target_pos = dt.pos_obj;
		++dt.i;
		dt.pos_obj = -1;
	}
}
