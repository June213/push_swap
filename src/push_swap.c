/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:47:05 by jsalaber          #+#    #+#             */
/*   Updated: 2024/03/05 12:34:05 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*temp;
	t_stack	*now;

	if (!a)
		return ;
	now = *a;
	while (now)
	{
		temp = now->next;
		now->num = 0;
		free(now);
		now = temp;
	}
	free(*a);
	*a = NULL;
}

void	ft_error(t_stack **a)
{
	ft_free_stack(a);
	ft_printf("Error\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	// t_stack	*original;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		ft_putendl_fd("Insert argument", 2);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!*argv)
		{
			ft_putendl_fd("split error", 2);
			ft_free_array(argv);
			exit(1);
		}
		init_stack(&a, argv);
	}
	else
		init_stack(&a, argv + 1);
	// original = a;
	// while (a)
	// {
	// 	ft_printf("%i\n", a->num);
	// 	a = a->next;
	// }
	// ft_printf("\n");
	// a = original;
	if (!sorted_stack(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			three_num(&a);
		else
			sort(&a, &b);
	}
	// while (a)
	// {
	// 	ft_printf("%i\n", a->num);
	// 	a = a->next;
	// }
	//ft_free_stack(&a);
	return (0);
}
