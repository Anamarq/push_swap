/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:19:20 by anamarqu          #+#    #+#             */
/*   Updated: 2023/02/25 11:19:21 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}
	return (1);
}

//STRJOIN
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if ((s1 != NULL) && (s2 != NULL) && (res))
	{
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			++i;
		}
		while (*s2 != '\0')
		{
			res[i] = *s2;
			++s2;
			++i;
		}
		res[i] = '\0';
		return (res);
	}
	free(res);
	return (NULL);
}

size_t	ft_no_words(char const *s, char c)
{
	size_t	p;
	int		w;

	p = 0;
	w = 0;
	while (s[p])
	{
		if (s[p] != c)
			w = 1;
		p++;
	}
	return (w);
}
