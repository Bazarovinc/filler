/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 18:56:32 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/08 18:56:32 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void	choose_player(t_pl *play, char *s)
{
	play->player = ft_atoi(s + 10);
	if (play->player == 1)
		play->player_c = 'O';
	else if (play->player == 2)
		play->player_c = 'X';
}