/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:14:58 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/06 15:01:49 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

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
			ft_printf("%d", m[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

static void	first_read(t_pl *play)
{
	char *s;

	get_next_line(0, &s);
	check_correct_input(s, 0);
	play->player = s[10] - '0';
	free(s);
	get_next_line(0, &s);
	read_map_size(play, s);
	play->map = ft_set_matrix(play->m_s_y, play->m_s_x);
	FT_SKIP(s);
	read_map(play);
	print_map(play->map, play->m_s_y, play->m_s_x);
	read_piece_size(play, s);
	free(s);
	play->piece = ft_set_matrix(play->p_s_y, play->p_s_x);
	read_piece(play);
	ft_printf("\n");
	print_map(play->piece, play->p_s_y, play->p_s_x);
	algoritm(play);
}

int		main(void)
{
	t_pl *play;

	ft_set_struct(&play);
	first_read(play);
	return (0);
}