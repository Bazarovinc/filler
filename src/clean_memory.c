/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memmory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:05:56 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/17 11:53:22 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

static void	clean_map(int **map, int *s1, int *s2)
{
	int i;

	i = 0;
	while (i < *s1)
	{
		free(map[i]);
		i++;
	}
	free(map);
	*s1 = 0;
	*s2 = 0;
}

void		clean_memory(t_pl *play)
{
	if (play)
	{
		if (play->m && play->freed_m == 0)
		{
			clean_map(play->m, &play->m_s_y, &play->m_s_x);
			play->freed_m = 1;
		}
		if (play->piece && play->freed_p == 0)
		{
			clean_map(play->piece, &play->p_s_y, &play->p_s_x);
			play->freed_p = 1;
		}
	}
}
