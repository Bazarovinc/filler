/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sizes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:41:52 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/06 13:49:51 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void	read_map_size(t_pl *play, char *s)
{
	check_correct_input(s, 1);
	play->m_s_y = ft_atoi(s + 8);
	if (play->m_s_y == 15 || play->m_s_y == 24)
		play->m_s_x = ft_atoi(s + 11);
	else if (play->m_s_y == 100)
		play->m_s_x = ft_atoi(s + 12);
}

void	read_piece_size(t_pl *play, char *s)
{
	check_correct_input(s, 2);
	play->p_s_y = ft_atoi(s + 6);
	if (play->p_s_y > 9 && play->p_s_y < 100)
		play->p_s_x = ft_atoi(s + 9);
	else if (play->p_s_y < 9)
		play->p_s_x = ft_atoi(s + 8);
	else if (play->p_s_y > 99)
		play->p_s_x = ft_atoi(s + 10);
}