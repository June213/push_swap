/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:53:13 by jsalaber          #+#    #+#             */
/*   Updated: 2024/03/06 09:09:50 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*moved;

	if (!*src)
		return ;
	moved = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	moved->prev = NULL;
	if (!*dest)
	{
		*dest = moved;
		moved->next = NULL;
	}
	else
	{
		moved->next = *dest;
		moved->next->prev = moved;
		*dest = moved;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_printf("pb\n");
}
