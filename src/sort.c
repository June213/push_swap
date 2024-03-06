/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:15:38 by jsalaber          #+#    #+#             */
/*   Updated: 2024/03/06 09:34:36 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three_num(t_stack **stack)
{
	t_stack	*biggest;

	biggest = find_max(*stack);
	if (biggest == *stack)
		ra(stack);
	else if ((*stack)->next == biggest)
		rra(stack);
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}

static void	smallest_ontop(t_stack **a)
{
	while ((*a)->num != find_min(*a)->num)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len-- > 3 && !sorted_stack(*a))
		pb(b, a);
	if (len-- > 3 && !sorted_stack(*a))
		pb(b, a);
	while (len-- > 3 && !sorted_stack(*a))
	{
		move_values_ab(*a, *b);
		move_ab(a, b);
	}
	three_num(a);
	while (*b)
	{
		move_values_ba(*a, *b);
		move_ba(a, b);
	}
	set_index(*a);
	smallest_ontop(a);
}
