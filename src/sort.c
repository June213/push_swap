/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:15:38 by jsalaber          #+#    #+#             */
/*   Updated: 2024/03/05 12:55:36 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three_num(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_max(*a);
	if (biggest == *a)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
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
		pb(a, b);
	if (len > 3 && !sorted_stack(*a))
	{
		pb(a, b);
		len--;
	}
	while (len-- > 3 && !sorted_stack(*a))
	{
		move_values_ab(*a, *b);
		move_ab(a, b);
		ft_printf("terminar bucle\n");
	}
	ft_printf("antes del three num\n");
	three_num(a);
	ft_printf("antes del segundo bucle\n");
	while (*b)
	{
		move_values_ba(*a, *b);
		move_ba(a, b);
	}
	ft_printf("segundo bucle\n");
	set_index(*a);
	smallest_ontop(a);
}
