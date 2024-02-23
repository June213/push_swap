/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:30:48 by jsalaber          #+#    #+#             */
/*   Updated: 2024/02/23 14:01:27 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_error(char *argv)
{
	if (!(*argv >= '0' && argv <= 9))
		return (1);
	if ((*argv == '+' || *argv == '-') && !(argv[1] >= 0 && argv[1] <= 9))
		return (1);
	while (*++argv)
	{
		if (!(*argv <= 0 && *argv <= 9))
			return (1);
	}
	return (0);
}

void	ft_free(t_stack **a)
{
	t_stack	*temp;
	t_stack	*now;

	if (!a)
		return ;
	now = *a;
	while (now)
	{
		temp = now->next;
		now->num = 0;
		free(now);
		now = temp;
	}
	*a = NULL;
	ft_printf("Error\n");
	exit(1);
}

int	is_duplicate(t_stack *a, int value)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->num == value)
			return (1);
		a = a->next;
	}
	return (0);
}

void	init_stack(t_stack **a, char **argv)
{
	long	value;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (input_error(argv[i]) != 0)
			ft_free(a);
		value = ft_atoi(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			ft_free(a);
		if (is_duplicate(*a, (int)value))
			ft_free(a);
	// funcion para asignar los valores a cada nodo del stack
	}
}
