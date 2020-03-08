/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:46:53 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/08 19:08:34 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

static void	read_map_str(t_pl *play, char *s, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (s[j] != '\0')
	{
		while ((s[j] >= '0' && s[j] <= '9') || s[j] == ' ')
			j++;
		if (s[j] == play->player_c)
			play->m[i][k] = -1;
		else if (s[j] != play->player_c && s[j] != '.')
			play->m[i][k] = -2;
		else if (s[j] == '.')
			play->m[i][k] = 0;
		j++;
		k++;
	}
}

static void	read_piece_str(t_pl *play, char *s, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (s[j] != '\0')
	{
		if (s[j] == '.')
			play->piece[i][k] = 0;
		else if (s[j] == '*')
			play->piece[i][k] = 1;
		k++;
		j++;
	}
}

void		read_piece(t_pl * play)
{
	char	*s;
	int		i;

	i = 0;
	while (i < play->p_s_y)
	{
		get_next_line(0, &s);
		read_piece_str(play, s, i);
		free(s);
		i++;
	}
}

static void	print_map(int **m, int s1, int s2)
{
	int i;
	int j;

	i = 0;
	while (i < s1)
	{
		j = 0;
		while (j < s2)
		{
			ft_printf("%3d", m[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void		read_map(t_pl *play)
{
	char	*s;
	int		i;

	i = 0;
	while (i < play->m_s_y)
	{
		get_next_line(0, &s);
		read_map_str(play, s, i);
		free(s);
		i++;
	}
	print_map(play->m, play->m_s_y, play->m_s_x);
	make_map(play);
}