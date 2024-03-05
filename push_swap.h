/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:47:19 by jsalaber          #+#    #+#             */
/*   Updated: 2024/03/05 12:43:26 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				num;
	int				idx;
	bool			above_median;
	int				move_cost;
	bool			cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
	struct s_stack	*cheapest_node;
}	t_stack;

int		input_error(char *argv);
void	ft_free_stack(t_stack **a);
void	ft_error(t_stack **a);
int		is_duplicate(t_stack *a, int value);
void	add_value(t_stack **a, int value);
void	init_stack(t_stack **a, char **argv);
void	ft_free_array(char **arr);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
bool	sorted_stack(t_stack *stack);
t_stack	*ft_stacklast(t_stack *a);
int		stack_len(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
void	three_num(t_stack **a);
void	set_index(t_stack *stack);
void	move_values_ab(t_stack *a, t_stack *b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	top_for_push(t_stack **stack, t_stack *node_move, char stack_name);
void	move_ab(t_stack **a, t_stack **b);
void	move_values_ba(t_stack *a, t_stack *b);
void	move_ba(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);

#endif