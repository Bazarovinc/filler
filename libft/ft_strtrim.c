/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:34:42 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/17 11:53:22 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	char	*ft_new(int size)
{
	char *s;

	if (size <= 0)
		s = ft_strnew(0);
	else
		s = ft_strnew(size + 1);
	return (s);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	size;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	size = ft_strlen(s) - 1;
	i = 0;
	while (ft_iswhitespace(s[size]) != 0)
		size--;
	while (ft_iswhitespace(s[i]) != 0)
	{
		size--;
		i++;
	}
	if (!(str = ft_new(size)))
		return (NULL);
	j = 0;
	size += i;
	while (i < size + 1)
		str[j++] = s[i++];
	return (str);
}
