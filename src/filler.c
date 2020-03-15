/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:14:58 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/15 16:26:05 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

static int	algoritm(t_pl *play)
{
	while (1)
	{
		if (read_map(play))
			return (1);
		if (read_piece(play))
			return (1);
		solve(play);
		ft_putnbr(play->tempy);
		ft_putchar(' ');
		ft_putnbr(play->tempx);
		ft_putchar('\n');
		clean_memory(play);
	}
	return (0);
}

static int	first_read(t_pl *play)
{
	char *s;

	get_next_line(0, &s);
	if (check_correct_input(s, 0))
	{
		free(play);
		free(s);
		return (1);
	}
	choose_player(play, s);
	free(s);
	if (algoritm(play))
	{
		clean_memory(play);
		free(play);
		return (1);
	}
	return (0);
}

int		main(void)
{
	t_pl *play;

	ft_set_struct(&play);
	if (first_read(play))
		return (1);
	free(play);
	return (0);
}