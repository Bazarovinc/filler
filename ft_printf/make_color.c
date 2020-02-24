/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:48:40 by ctelma            #+#    #+#             */
/*   Updated: 2020/02/07 11:10:59 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

static void	make_background(const char *s)
{
	g_pstr.i += 2;
	g_pstr.non_print += 2;
	if (s[g_pstr.i] == 'r')
		write(1, &RED_B, 5);
	else if (s[g_pstr.i] == 'b' && s[g_pstr.i + 2] == 'u')
		write(1, &BLUE_B, 5);
	else if (s[g_pstr.i] == 'b' && s[g_pstr.i + 2] == 'a')
		write(1, &BLACK_B, 5);
	else if (s[g_pstr.i] == 'w')
		write(1, &WHITE_B, 5);
	else if (s[g_pstr.i] == 'y')
		write(1, &YELLOW_B, 5);
	else if (s[g_pstr.i] == 'g')
		write(1, &GREEN_B, 5);
	while (s[g_pstr.i] != '}')
	{
		g_pstr.i++;
		g_pstr.non_print++;
	}
	g_pstr.i++;
	g_pstr.non_print++;
}

static void	make_text(const char *s)
{
	g_pstr.i++;
	g_pstr.non_print++;
	if (s[g_pstr.i] == 'r')
		write(1, &RED_T, 5);
	else if (s[g_pstr.i] == 'b')
		write(1, &BLUE_T, 5);
	else if (s[g_pstr.i] == 'y')
		write(1, &YELLOW_T, 5);
	else if (s[g_pstr.i] == 'g')
		write(1, &GREEN_T, 5);
	else if (s[g_pstr.i] == 'w')
		write(1, &WHITE_T, 5);
	while (s[g_pstr.i] != '}')
	{
		g_pstr.i++;
		g_pstr.non_print++;
	}
}

void		make_color(const char *s)
{
	if (s[g_pstr.i] == '{' && s[g_pstr.i + 1] == '{')
		make_background(s);
	else if (s[g_pstr.i] == '{' && s[g_pstr.i + 1] != '{')
		make_text(s);
}
