/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:49:46 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/23 15:49:47 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

long	ft_atoi(const char *str)
{
	long	sol;
	int		signo;

	signo = 1;
	sol = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signo *= -1;
		++str;
	}
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		sol *= 10;
		sol += *str - '0';
		++str;
	}
	sol *= signo;
	return (sol);
}

// int main()
// {
// 	char *str;
// 	str = " -129834ab567";
// 	int a = ft_atoi(str);

// 	printf("Numero %i", a);
// }
