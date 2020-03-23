/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:38:16 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/17 11:53:22 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

static int	flag_star(t_pl *p, int *i, int *j)
{
	if (p->flag_star == 1)
	{
		p->flag_star = 0;
		if (*i + 1 < p->p_s_x)
			(*i)++;
		else if (*j + 1 < p->p_s_y)
		{
			*i = 0;
			(*j)++;
		}
		else
			return (0);
	}
	return (1);
}

int			search_next_star(t_pl *p, int *i, int *j)
{
	if (flag_star(p, i, j) == 0)
		return (0);
	if (*i == 0 && *j == 0 && p->piece && p->piece[*j][*i] == 1)
	{
		p->flag_star = 1;
		return (1);
	}
	else
	{
		while (*j < p->p_s_y)
		{
			while (*i < p->p_s_x)
			{
				if (p->piece && p->piece[*j][*i] == 1)
				{
					p->flag_star = 1;
					return (1);
				}
				(*i)++;
			}
			*i = 0;
			(*j)++;
		}
	}
	return (0);
}
