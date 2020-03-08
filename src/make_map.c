/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:15:33 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/08 18:47:01 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

static void	reverse_cicle(t_pl *p, int i, int j)
{
	while (i >= 0)
	{
		j = p->m_s_x - 1;
		while (j >= 0)
		{
			if (i != 0 && i != p->m_s_y - 1)
				check_mid_lines(p, i, j, -2);
			else if (i == 0)
				check_1_line(p, i, j, -2);
			else if (i == p->m_s_y - 1)
				check_last_line(p, i, j, -2);
			j--;
		}
		i--;
	}
}

void	make_map(t_pl *p)
{
	int i;
	int j;

	i = 0;
	while (i < p->m_s_y)
	{
		j = 0;
		while (j < p->m_s_x)
		{
			if (i != 0 && i != p->m_s_y - 1)
				check_mid_lines(p, i, j, -2);
			else if (i == 0)
				check_1_line(p, i, j, -2);
			else if (i == p->m_s_y - 1)
				check_last_line(p, i, j, -2);
			j++;
		}
		i++;
	}
	reverse_cicle(p, i - 1, j - 1);
}