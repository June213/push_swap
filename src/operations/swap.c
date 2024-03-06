/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:04:10 by junesalaber       #+#    #+#             */
/*   Updated: 2024/03/06 09:28:26 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **top)
{
	t_stack	*temp;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	temp = (*top)->next;
	(*top)->next = temp->next;
	temp->next = *top;
	(*top)->prev = temp;
	if ((*top)->next != NULL)
		(*top)->next->prev = *top;
	*top = temp;
	(*top)->prev = NULL;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
