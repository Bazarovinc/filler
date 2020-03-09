/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:31:32 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/06 13:40:37 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void	check_correct_input(char *s, int flag)
{
	if (flag == 0)
	{
		if (ft_strnequ(s, "$$$ ", 4) == 0)
			exit(1);
		if (ft_strnequ(s + 4, "exec ", 5) == 0)
			exit(1);
		if (ft_strnequ(s + 9, "p1 : ", 5) == 0 &&
			ft_strnequ(s + 9, "p2 : ", 5) == 0)
			exit(1);
		if (ft_strnequ(s + 14, "[./ctelma.filler]", 16) == 0)
			exit(1);
	}
	else if (flag == 1)
	{
		if (ft_strnequ(s, "Plateau", 7) ==  0)
			exit(1);
	}
	else if (flag == 2)
	{
		if (ft_strnequ(s, "Piece ", 6) ==  0)
			exit(1);
	}
}