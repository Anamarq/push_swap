/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/02/22 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/////check parameters /////
//Primero: comprobar si los argumentos son correctos
//No puede haber duplicados! Comprobar
int	is_number(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-' || c[i] == '+')
		++i;
	if (c[i] == '\0')
		return (-1);
	while (c[i] != '\0')
	{
		if (c[i] < '0' || c[i] > '9')
		{
			return (-1);
		}
		++i;
	}
	if (ft_no_words(c, ' ') == 0)
		return (-1);
	return (1);
}

int	check_duplicates(int *array, int size)
{
	int	i;
	int	j;
	int	n;

	i = 1;
	j = 0;
	while (j < size)
	{
		n = array[j];
		while (i < size)
		{
			if (n == array[i])
				return (-1);
			++i;
		}
		++j;
		i = j + 1;
	}
	return (1);
}

//Comprobar que sean número, puede ser negativo
//Pasar a int y guardar en array
int	check_parameters2(char **param, int *array, t_info *info)
{
	int		i;
	long	n;

	i = 0;
	while (param[i])
	{
		if (is_number(param[i]) == -1)
			return (-1);
		n = ft_atoi(param[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (-1);
		array[i] = n;
		++i;
	}
	if (check_duplicates(array, i) == -1)
		return (-1);
	info->size_a = i;
	info->total_size = i;
	return (1);
}

int	check_parameters(char **param, int *array, int size)
{
	int		i;
	long	n;

	i = 1;
	while (param[i])
	{
		if (is_number(param[i]) == -1)
			return (-1);
		n = ft_atoi(param[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (-1);
		array[i - 1] = n;
		++i;
	}
	if (check_duplicates(array, size) == -1)
		return (-1);
	return (1);
}
//////////////END check parameters
