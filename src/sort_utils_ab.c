/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:33:45 by jsalaber          #+#    #+#             */
/*   Updated: 2024/03/05 13:00:51 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->idx = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	b_target(t_stack *a, t_stack *b)
{
	t_stack	*b_temp;
	long	smallest_near;
	t_stack	*target_node;

	while (a)
	{
		smallest_near = LONG_MIN;
		b_temp = b;
		while (b_temp)
		{
			if (b_temp->num > smallest_near && b_temp->num < a->num)
			{
				smallest_near = b_temp->num;
				target_node = b_temp;
			}
			b_temp = b_temp->next;
		}
		if (smallest_near == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	ab_move_cost(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (a)
	{
		a->move_cost = a->idx;
		if (!(a->above_median))
			a->move_cost = a_len - (a->idx);
		if (a->target_node->above_median)
			a->move_cost = a->move_cost + a->target_node->idx;
		else
			a->move_cost += b_len - (a->move_cost + a->target_node->idx);
		a = a->next;
	}
}

static void	cheapest_cost(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->move_cost < cheapest_value)
		{
			cheapest_value = stack->move_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	move_values_ab(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	b_target(a, b);
	ab_move_cost(a, b);
	cheapest_cost(a);
}
