/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:47:50 by ctelma            #+#    #+#             */
/*   Updated: 2020/02/07 10:57:38 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	initialization(0);
	va_start(g_pstr.args, format);
	while (format[g_pstr.i] != '\0')
	{
		if (format[g_pstr.i] == '%')
			validation(format);
		else if (format[g_pstr.i] == '\''
			&& format[g_pstr.i + 1] >= '0' && format[g_pstr.i + 1] <= '9')
			print_symb(format);
		else if (format[g_pstr.i] == '{')
			make_color(format);
		else
			ft_putchar(format[g_pstr.i]);
		if (format[g_pstr.i] != '\0')
			g_pstr.i++;
	}
	va_end(g_pstr.args);
	g_pstr.size += g_pstr.i - g_pstr.non_print;
	return (g_pstr.size);
}
