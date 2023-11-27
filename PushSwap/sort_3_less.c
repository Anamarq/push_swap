/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_less.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:41:15 by anamarqu          #+#    #+#             */
/*   Updated: 2023/02/19 11:41:17 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
///Sort 3 or less /////////
void	sort2(t_stack *stack)
{
	if (stack[0].value > stack[1].value)
		swap(stack, 0);
}

//If the index of the first number is highest, do ra,
//Otherwise, if the index of the second number is highest, do rra,
//Then, if the index of the first number is bigger 
//than the index of the second number, do sa.
void	sort3(t_stack *stack, int size)
{
	if (stack[0].index > stack[1].index && stack[0].index > stack[2].index)
		rotate(stack, size, 0);
	else if (stack[1].index > stack[0].index && stack[1].index > stack[2].index)
		reverse_rotate(stack, size, 0);
	if (stack[0].index > stack[1].index)
		swap(stack, 0);
}

///END Sort 3 or less /////////
