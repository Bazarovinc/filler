/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:14:58 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/09 16:32:32 by ctelma           ###   ########.fr       */
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
			ft_printf("%3d", m[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	algoritm(t_pl *play)
{
	while (1)
	{
		read_map(play);
		//print_map(play->m, play->m_s_y, play->m_s_x);
		read_piece(play);
		solve(play);
		ft_putnbr(play->tempy);
		ft_putchar(' ');
		ft_putnbr(play->tempx);
		ft_putchar('\n');
		clean_memory(play);
	}
}

static void	first_read(t_pl *play)
{
	char *s;

	get_next_line(0, &s);
	check_correct_input(s, 0);
	choose_player(play, s);
	free(s);
	algoritm(play);
}

int		main(void)
{
	t_pl *play;

	ft_set_struct(&play);
	first_read(play);
	return (0);
}