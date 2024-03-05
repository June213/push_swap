/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_ba.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:10:27 by jsalaber          #+#    #+#             */
/*   Updated: 2024/03/04 14:33:16 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	a_target(t_stack *a, t_stack *b)
{
	t_stack	*a_temp;
	long	biggest_near;
	t_stack	*target_node;

	while (b)
	{
		biggest_near = LONG_MAX;
		a_temp = a;
		while (a_temp)
		{
			if (a_temp->num < biggest_near && a_temp->num > b->num)
			{
				biggest_near = a_temp->num;
				target_node = a_temp;
			}
			a_temp = a_temp->next;
		}
		if (biggest_near == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	move_values_ba(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	a_target(a, b);
}

void	move_ba(t_stack **a, t_stack **b)
{
	top_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}
