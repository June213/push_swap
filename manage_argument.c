/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:48:22 by jsalaber          #+#    #+#             */
/*   Updated: 2024/02/23 09:48:13 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**str_argument(int argc, char **argv)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (argc < 2)
		ft_putendl_fd("Insert argument", 2);
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else
	{
		str = (char **)ft_calloc(argc, sizeof(char *));
		if (!str)
			return (NULL);
		while (j < argc)
		{
			str[i] = ft_strdup(argv[j]);
			i++;
			j++;
		}
	}
	return (str);
}
