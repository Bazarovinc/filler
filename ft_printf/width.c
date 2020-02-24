/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:51:21 by ctelma            #+#    #+#             */
/*   Updated: 2020/02/06 19:55:43 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

void	width(const char *s)
{
	if (s[g_pstr.i] >= '0' && s[g_pstr.i] <= '9')
	{
		g_pstr.width = ft_atoi(s + g_pstr.i);
		while (s[g_pstr.i] >= '0' && s[g_pstr.i] <= '9')
		{
			g_pstr.i++;
			g_pstr.non_print++;
		}
	}
	else if (s[g_pstr.i] == '*')
	{
		g_pstr.width = va_arg(g_pstr.args, int);
		g_pstr.i++;
		g_pstr.non_print++;
	}
}
