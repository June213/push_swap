/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:21:59 by jsalaber          #+#    #+#             */
/*   Updated: 2023/12/15 11:01:12 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		count ++;
		s++;
	}
	return (count);
}

/*
int	main(void)
{
	char	text[] = "hola";

	printf("%zu\n", ft_strlen(text));
	return (0);
}
*/