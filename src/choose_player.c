/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 18:56:32 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/17 11:53:22 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void	choose_player(t_pl *play, char *s)
{
	play->player = ft_atoi(s + 10);
	if (play->player == 1)
	{
		play->player_c[0] = 'O';
		play->player_c[1] = 'o';
		play->en_c[0] = 'X';
		play->en_c[1] = 'x';
	}
	else if (play->player == 2)
	{
		play->player_c[0] = 'X';
		play->player_c[1] = 'x';
		play->en_c[0] = 'O';
		play->en_c[1] = 'o';
	}
}
