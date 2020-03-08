/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:26:44 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/06 17:21:04 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

static void	check_position(t_pl *play, int i, int j)
{
	if (play->m[i][j] == 1 || play->m[i][j] == 2)
	{
		if (play->m[i][j] == play->player)
		{
			play->my_pos1[0] = i;
			play->my_pos1[1] = j;
		}
		else if (play->m[i][j] != play->player)
		{
			play->en_pos1[0] = i;
			play->en_pos1[1] = j;
		}
	}
}

static void	from_down(t_pl *play)
{
	int i;
	int j;

	i = play->p_s_y - 1;
	while (i > -1)
	{
		j = play->p_s_x - 1;
		while (j > -1)
		{
			if (play->piece[i][j] == 1)
				break ;
			j--;
		}
		if (play->piece[i][j] == 1)
			break ;
		i--;
	}
	ft_printf("%d %d", play->my_pos1[0] - i, play->my_pos1[1] - j);
}


static void	from_up(t_pl *play)
{
	int i;
	int j;

	i = 0;
	while (i < play->p_s_y)
	{
		j = 0;
		while (j < play->p_s_x)
		{
			if (play->piece[i][j] == 1)
				break ;
			j++;
		}
		if (play->piece[i][j] == 1)
			break ;
		i++;
	}
	ft_printf("%d %d", play->my_pos1[0] - i, play->my_pos1[1] - j);
}

void	first_push(t_pl *play)
{
	int i;
	int j;

	i = 0;
	while (i < play->m_s_y)
	{
		j = 0;
		while (j < play->m_s_x)
		{
			check_position(play, i, j);
			j++;
		}
		i++;
	}
	if (play->my_pos1[0] >= play->en_pos1[0])
		from_down(play);
	else if (play->my_pos1[0] < play->en_pos1[0])
		from_up(play);
}