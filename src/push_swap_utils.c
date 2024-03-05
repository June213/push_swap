/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:03:57 by jsalaber          #+#    #+#             */
/*   Updated: 2024/03/05 12:29:59 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	stack_len(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

bool	sorted_stack(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*find_min(t_stack *stack)
{
	long	smallest;
	t_stack	*smallest_node;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->num < smallest)
		{
			smallest = stack->num;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*find_max(t_stack *stack)
{
	long	biggest;
	t_stack	*biggest_node;

	if (!stack)
		return (NULL);
	biggest = LONG_MIN;
	while (stack)
	{
		if (stack->num > biggest)
		{
			biggest = stack->num;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}
