/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:43 by anamarqu          #+#    #+#             */
/*   Updated: 2023/02/22 13:03:44 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///SPLIT
#include "push_swap.h"

//split
typedef struct s_data
{
	char	**table;
	int		w;
	int		p;
	int		start;
}	t_data;

size_t	ft_strlen(const char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] != '\0')
	{
		++ cont;
	}
	return (cont);
}

char	*ft_strdup(const char *string)
{
	char	*copy;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(string);
	copy = (char *) malloc((size + 1) * sizeof(char));
	if (!copy)
	{
		free(copy);
		return (NULL);
	}
	if (string != NULL)
	{
		while (string[i] != '\0')
		{
			copy[i] = string[i];
			++i;
		}
		copy[i] = '\0';
		return (copy);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start,
size_t len)
{
	char			*sub;
	size_t			i;

	i = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (sub)
	{
		while (i < len && s[i + start] != '\0')
		{
			sub[i] = s[i + start];
			++i;
		}
		sub[i] = '\0';
		return (sub);
	}
	free(sub);
	return (NULL);
}

size_t	ft_count_words(char const *s, char c)
{
	size_t	p;
	size_t	w;

	w = 0;
	p = 0;
	while (s[p] && s[p] == c)
		p++;
	while (s[p])
	{
		if (s[p] == c && s[p + 1] != c && s[p + 1] != '\0')
			w++;
		p++;
	}
	return (w + 1);
}

char	**ft_split(char const *s, char c)
{
	t_data	d;

	d.w = 0;
	d.p = 0;
	d.start = 0;
	if (s == NULL)
		return (NULL);
	d.table = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (d.table == NULL)
	{
		free(d.table);
		return (NULL);
	}
	while (s[d.p] && d.w < (int)ft_count_words(s, c))
	{
		while (s[d.p] && s[d.p] == c)
			d.p++;
		d.start = d.p;
		while (s[d.p] && s[d.p] != c)
			d.p++;
		if (d.start != d.p)
			d.table[d.w++] = ft_substr(s, d.start, d.p - d.start);
	}
	d.table[d.w] = NULL;
	return (d.table);
}
///END SPLIT
