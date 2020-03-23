/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:19:06 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/17 11:53:22 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

static void	get_score(t_pl *p, int score)
{
	if (p->is_zero == 1)
	{
		if ((score <= p->score && score > 0) || (score > 0 && p->score == 0))
		{
			p->score = score;
			p->tempx = p->x - p->i;
			p->tempy = p->y - p->j;
		}
		else
		{
			p->score2 = score;
			p->tempx2 = p->x - p->i;
			p->tempy2 = p->y - p->j;
		}
	}
	else
	{
		if (score < p->score || p->score == 0)
		{
			p->score = score;
			p->score2 = score;
			p->tempx2 = p->x - p->i;
			p->tempy2 = p->y - p->j;
		}
	}
}

static void	foreach_star(t_pl *p)
{
	int	score;

	score = 0;
	p->i = 0;
	p->j = 0;
	while (search_next_star(p, &p->i, &p->j) == 1)
	{
		score = 0;
		p->startx = p->i;
		p->starty = p->j;
		if (count_before(p, p->j, p->i, &score) == 0 &&
			count_after(p, p->j, p->i, &score) == 0)
		{
			get_score(p, score);
		}
	}
	if (p->score == 0)
	{
		p->score = p->score2;
		p->tempx = p->tempx2;
		p->tempy = p->tempy2;
	}
}

static void	search_after_zero(t_pl *p)
{
	p->is_zero = 0;
	while (p->y < p->m_s_y)
	{
		while (p->x < p->m_s_x)
		{
			if (p->m[p->y][p->x] > 0)
				p->is_zero = 1;
			p->x++;
		}
		p->x = 0;
		p->y++;
	}
	p->x = 0;
	p->y = 0;
}

void		solve(t_pl *p)
{
	p->y = 0;
	p->x = 0;
	p->score = 0;
	p->tempx = 0;
	p->tempy = 0;
	p->score2 = 0;
	p->tempx2 = 0;
	p->tempy2 = 0;
	search_after_zero(p);
	while (p->y < p->m_s_y)
	{
		while (p->x < p->m_s_x)
		{
			if (p->m[p->y][p->x] == ME)
			{
				foreach_star(p);
			}
			p->x++;
		}
		p->x = 0;
		p->y++;
	}
}
