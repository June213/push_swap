/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:35:36 by jsalaber          #+#    #+#             */
/*   Updated: 2024/03/06 09:31:55 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
	{
		rr(a, b);
		set_index(*a);
		set_index(*b);
	}
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
	{
		rrr(a, b);
		set_index(*a);
		set_index(*b);
	}
}

void	top_for_push(t_stack **stack, t_stack *node_move, char stack_name)
{
	while (*stack != node_move)
	{
		if (stack_name == 'a')
		{
			if (node_move->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (node_move->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_ab(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	top_for_push(a, cheapest_node, 'a');
	top_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}
