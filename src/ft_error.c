/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:12:28 by ctelma            #+#    #+#             */
/*   Updated: 2020/02/16 13:04:27 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void	del_mem(void)
{
	exit(0);
}

void	ft_error(void)
{
	ft_putstr_fd(RED_T, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(WHITE_T, 2);
	exit(1);
}
