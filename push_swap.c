/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junesalaberria <junesalaberria@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:47:05 by jsalaber          #+#    #+#             */
/*   Updated: 2024/02/28 12:25:27 by junesalaber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free_array(char **arr)
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

int	main(int argc, char **argv)
{
	t_stack *a;
	
	a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
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
	while (a)
	{
		printf("%i\n", a->num);
		a = a->next;
	}
	swap(&a);
	printf("swap hecho\n");
	while (a)
	{
		printf("dentro del bucle\n");
		printf("%i\n", a->num);
		a = a->next;
	}
}
