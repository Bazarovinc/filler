/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:29:17 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/17 11:53:22 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

int		count_score(t_pl *p, int i, int j, int *score)
{
	if (p->y + j - p->tempj < 0 || p->y + j - p->tempj >= p->m_s_y ||
		p->x + i - p->tempi < 0 || p->x + i - p->tempi >= p->m_s_x)
		return (1);
	if (p->m[p->y + j - p->tempj][p->x + i - p->tempi] == ME ||
		p->m[p->y + j - p->tempj][p->x + i - p->tempi] == EN)
	{
		if (i != p->tempi || j != p->tempj)
			return (1);
	}
	if (p->m[p->y + j - p->tempj][p->x + i - p->tempi] != ME)
		*score += p->m[p->y + j - p->tempj][p->x + i - p->tempi];
	return (0);
}

int		count_before(t_pl *p, int j, int i, int *score)
{
	p->tempj = j;
	p->tempi = i;
	while (j >= 0)
	{
		while (i >= 0)
		{
			if (p->piece[j][i] == 1)
			{
				if (count_score(p, i, j, score) == 1)
					return (1);
			}
			i--;
		}
		i = p->p_s_x - 1;
		j--;
	}
	return (0);
}

int		count_after(t_pl *p, int j, int i, int *score)
{
	p->tempj = j;
	p->tempi = i;
	while (j < p->p_s_y)
	{
		while (i < p->p_s_x)
		{
			if (p->piece[j][i] == 1)
			{
				if (count_score(p, i, j, score) == 1)
					return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
