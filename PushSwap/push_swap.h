/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:29:01 by anamarqu          #+#    #+#             */
/*   Updated: 2023/01/27 12:29:03 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
//value: valor a ordenar
//index: its index in the list of all values that must be sorted,
//pos: its current position in its stack,
//target_pos: for elements in stack B, the target position in 
//stack A where it should be,
//cost_a: how many actions it would cost to rotate stack A so that 
//the element at the target position gets to the top of stack A,
//cost_b: how many actions it would cost to rotate stack B so that 
//this element gets to the top of stack B,
//next: pointer to the next element in the list.

typedef struct s_stack
{
	int	value;
	int	index;
	int	pos;
	int	target_pos;
	int	cost_a;
	int	cost_b;
}	t_stack;

typedef struct s_info
{
	int	size_a;
	int	size_b;
	int	total_size;
}	t_info;

void	calculate_target(t_stack *stackA, t_stack *stackB, t_info *info);
int		check_parameters(char **param, int *array, int size);
int		check_parameters2(char **param, int *array, t_info *info);
void	execute_actions(t_stack *stackA, t_stack *stackB, t_info *info);
long	ft_atoi(const char *str);
void	sort3(t_stack *stack, int size);
void	sort2(t_stack *stack);
void	sort(t_stack *stackA, t_stack *stackB, t_info *info);
char	**ft_split(char const *s, char c);
size_t	ft_count_words(char const *s, char c);
void	set_index(t_stack *stackA, int size);
void	initialize(int *a, t_stack *stackA, int size);
void	push_a(t_stack *stackA, t_stack *stackB, t_info *info, int aob);
void	push_b(t_stack *stackB, t_stack *stackA, t_info *info, int aob);
void	rotate(t_stack *stack, int size, int aob);
void	reverse_rotate(t_stack *stack, int size, int aob);
void	rotate_rotate(t_stack *stackA, t_stack *stackB, t_info *info, int aob);
void	reverse_reverse(t_stack *stackA, t_stack *stackB, t_info *info, int b);
void	swap(t_stack *stack, int aob);
void	swap_swap(t_stack *stackA, t_stack *stackB, int aob);
int		abs(int a);
//Bonus:
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(char *s1, char *s2);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *string);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_no_words(char const *s, char c);

#endif