/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:45:20 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/17 11:53:22 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	sym;
	unsigned char	*str;
	size_t			i;

	i = 0;
	if (n == 0)
		return (NULL);
	sym = (unsigned char)c;
	str = (unsigned char*)s;
	while (i < n)
	{
		if (str[i] == sym)
			return (str + i);
		i++;
	}
	return (NULL);
}
