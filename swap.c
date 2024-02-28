/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junesalaberria <junesalaberria@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:04:10 by junesalaber       #+#    #+#             */
/*   Updated: 2024/02/28 12:29:50 by junesalaber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack *temp;

	// if (*head == NULL || (*head)->next == NULL)
	// 	return ;
	printf("Antes del intercambio:\n");
    printf("head: %p\n", (void *)*head);
    printf("(*head)->num: %d\n", (*head)->num);
    printf("(*head)->next: %p\n", (void *)(*head)->next);
    printf("(*head)->prev: %p\n", (void *)(*head)->prev);
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	(*head)->prev = temp;
	if ((*head)->next != NULL)
		(*head)->next->prev = *head;
	*head = temp;
	(*head)->prev = NULL;
	printf("Después del intercambio:\n");
    printf("head: %p\n", (void *)*head);
    printf("(*head)->num: %d\n", (*head)->num);
    printf("(*head)->next: %p\n", (void *)(*head)->next);
    printf("(*head)->prev: %p\n", (void *)(*head)->prev);
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