/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junesalaberria <junesalaberria@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:30:48 by jsalaber          #+#    #+#             */
/*   Updated: 2024/02/28 12:40:50 by junesalaber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_error(char *argv)
{
	int	i;

	i = 0;

	if (!(argv[i] == '+' || argv[i] == '-'
		|| (argv[i] >= '0' && argv[i] <= '9')))
		return (1);
	if ((argv[i] == '+' || argv[i] == '-') 
		&& !(argv[i + 1] >= '0' && argv[i + 1] <= '9'))
		return (1);
	while (argv[++i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (1);
	}
	return (0);
}

void	ft_free_stack(t_stack **a)
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

t_stack	*ft_stacklast(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next != NULL)
	{
		a = a->next;
	}
	return (a);
}

void	add_value(t_stack **a, int value)
{
	t_stack	*new;
	t_stack	*last;

	if (!a)
		return ;
	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->next = NULL;
	new->num = value;
	if (!(*a))
	{
		*a = new;
		new->prev = NULL;
	}
	else
	{
		last = ft_stacklast(*a);
		if (last)
		{
			last->next = new;
			new->prev = last;
		}
	}
}

void	init_stack(t_stack **a, char **argv)
{
	long	value;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (input_error(argv[i]) != 0)
			ft_free_stack(a);
		value = ft_atoi(argv[i]);
		if (value > 2147483647 || value < -2147483648 || is_duplicate(*a, (int)value) != 0)
			ft_free_stack(a);
		add_value(a, (int)value);
		i++;
	}
}
