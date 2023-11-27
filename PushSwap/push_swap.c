/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:21:58 by anamarqu          #+#    #+#             */
/*   Updated: 2023/01/29 13:22:01 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct data
{
	int		*array;
	char	**array2d;
	int		correct;
	int		is_sorted;
}	t_main;

int	error_memory(t_stack *stackA, t_stack *stackB)
{
	if (stackA == NULL)
	{
		free(stackA);
		return (-1);
	}
	if (stackB == NULL)
	{
		free(stackB);
		return (-1);
	}
	return (1);
}

void	start_sort(t_stack *stackA, t_stack *stackB, t_info info, t_main *data)
{
	int	i;

	initialize(data->array, stackA, info.size_a);
	set_index(stackA, info.size_a);
	i = 0;
	while (i < info.size_a)
	{
		if (stackA[i].index != i + 1)
			data->is_sorted = -1;
		++i;
	}
	if (data->is_sorted == -1)
	{
		if (info.size_a == 2)
			sort2(stackA);
		else if (info.size_a == 3)
			sort3(stackA, info.size_a);
		else if (info.size_a > 3)
			sort(stackA, stackB, &info);
	}
	free(stackA);
	free(stackB);
}

int	ckeck_args(int argc, char **argv, t_info *info, t_main *data)
{
	if (argc == 2)
	{
		data->array2d = ft_split(argv[1], ' ');
		data->array = (int *)malloc((ft_count_words(argv[1], ' ') + 1)
				* sizeof(int));
		if (data->array == NULL)
		{
			free(data->array);
			return (-1);
		}
		if (check_parameters2(data->array2d, data->array, info) == 1)
			return (1);
	}
	else if (argc > 2)
	{
		data->array = (int *)malloc((info->size_a) * sizeof(int));
		if (data->array == NULL)
		{
			free(data->array);
			return (-1);
		}
		if (check_parameters(argv, data->array, info->size_a) == 1)
			return (1);
	}
	return (-1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	info;
	t_main	data;

	data.is_sorted = 1;
	info.size_a = argc - 1;
	info.size_b = 0;
	info.total_size = info.size_a;
	data.correct = 0;
	if (ckeck_args(argc, argv, &info, &data) == 1)
	{
		stack_a = (t_stack *)malloc((info.size_a) * sizeof(t_stack));
		stack_b = (t_stack *)malloc((info.size_a) * sizeof(t_stack));
		if (error_memory(stack_a, stack_b) == -1)
			return (-1);
		start_sort(stack_a, stack_b, info, &data);
		free(data.array);
	}
	else if (argc != 1)
		write(2, "Error\n", 6);
}
