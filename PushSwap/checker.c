/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:28:05 by anamarqu          #+#    #+#             */
/*   Updated: 2023/02/25 11:28:06 by anamarqu         ###   ########.fr       */
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

int	actions_checker(t_stack *stackA, t_stack *stackB, t_info *info, char *car)
{
	if (ft_strcmp(car, "pa\n"))
		push_a(stackA, stackB, info, 3);
	else if (ft_strcmp(car, "pb\n"))
		push_b(stackB, stackA, info, 3);
	else if (ft_strcmp(car, "sa\n"))
		swap(stackA, 3);
	else if (ft_strcmp(car, "sb\n"))
		swap(stackB, 3);
	else if (ft_strcmp(car, "ss\n"))
		swap_swap(stackA, stackB, 3);
	else if (ft_strcmp(car, "rb\n"))
		rotate(stackB, info->size_b, 3);
	else if (ft_strcmp(car, "ra\n"))
		rotate(stackA, info->size_a, 3);
	else if (ft_strcmp(car, "rr\n"))
		rotate_rotate(stackA, stackB, info, 3);
	else if (ft_strcmp(car, "rra\n"))
		reverse_rotate(stackA, info->size_a, 3);
	else if (ft_strcmp(car, "rrb\n"))
		reverse_rotate(stackB, info->size_b, 3);
	else if (ft_strcmp(car, "rrr\n"))
		reverse_reverse(stackA, stackB, info, 3);
	else
		return (-1);
	return (1);
}

void	start_sort2(t_stack *stackA, t_stack *stackB, t_info *info, t_main *dt)
{
	int		i;
	char	*car;

	set_index(stackA, info->size_a);
	car = get_next_line(1);
	while (!ft_strcmp(car, "exit\n"))
	{
		if (actions_checker(stackA, stackB, info, car) == -1)
		{
			write(2, "Error\n", 6);
			return ;
		}
		car = get_next_line(1);
	}
	i = 0;
	while (i < info->size_a)
	{
		if (stackA[i].index != i + 1)
			dt->is_sorted = -1;
		++i;
	}
	if (dt->is_sorted == -1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
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
		initialize(data.array, stack_a, info.size_a);
		start_sort2(stack_a, stack_b, &info, &data);
		free(data.array);
		free(stack_a);
		free(stack_b);
	}
	else if (argc != 1)
		write(2, "Error\n", 6);
}
