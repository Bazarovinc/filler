/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:22:32 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/09 14:42:37 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void	algoritm(t_pl *play)
{
	while (1)
	{
		read_map(play);
		read_piece(play);
		solve(play);
		ft_printf("%d %d\n", play->tempy, play->tempx);
	}
}