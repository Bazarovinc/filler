/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:46:53 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/17 12:49:47 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

static int	read_map_str(t_pl *play, char *s, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (s[j] != '\0')
	{
		while ((s[j] >= '0' && s[j] <= '9') || s[j] == ' ')
			j++;
		if ((s[j] == play->player_c[0] || s[j] == play->player_c[1]))
			play->m[i][k] = ME;
		else if ((s[j] == play->en_c[0] || s[j] == play->en_c[1])
			&& s[j] != '.')
			play->m[i][k] = EN;
		else if (s[j] == '.')
			play->m[i][k] = 0;
		else
			return (1);
		j++;
		k++;
	}
	return (0);
}

static int	check_line_number(char *s, int i)
{
	if (ft_atoi(s) != i)
		return (1);
	return (0);
}

static int	read_piece_str(t_pl *play, char *s, int i)
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
		else
			return (1);
		k++;
		j++;
	}
	return (0);
}

int			read_piece(t_pl *play)
{
	char	*s;
	int		i;

	i = 0;
	if (get_next_line(0, &s) == -1 || read_piece_size(play, s))
		return (1);
	free(s);
	play->piece = ft_set_matrix(play->p_s_y, play->p_s_x, &play->freed_p);
	while (i < play->p_s_y)
	{
		if (get_next_line(0, &s) == -1)
			return (1);
		if (s[0] == '\0')
			return (1);
		if (read_piece_str(play, s, i))
			return (1);
		free(s);
		i++;
	}
	return (0);
}

int			read_map(t_pl *play)
{
	char	*s;
	int		i;

	i = 0;
	get_next_line(0, &s);
	if (read_map_size(play, s))
		return (1);
	play->m = ft_set_matrix(play->m_s_y, play->m_s_x, &play->freed_m);
	free(s);
	FT_SKIP(s);
	while (i < play->m_s_y)
	{
		get_next_line(0, &s);
		if (check_line_number(s, i) || read_map_str(play, s, i))
			return (1);
		free(s);
		i++;
	}
	make_map(play);
	return (0);
}
