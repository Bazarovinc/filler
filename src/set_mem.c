/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:09:58 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/06 12:48:54 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

int		**ft_set_matrix(int size_1, int size_2)
{
	int i;
	int **matrix;

	if ((matrix = (int**)malloc(sizeof(int*) * size_1)))
		;
	i = 0;
	while (i < size_1)
	{
		if ((matrix[i] = (int*)malloc(sizeof(int) * size_2)))
			;
		i++;
	}
	return (matrix);
}

void	ft_set_struct(t_pl **play)
{
	if ((*play = (t_pl*)malloc(sizeof(t_pl))))
		;
	(*play)->m_s_x = 0;
	(*play)->m_s_y = 0;
	(*play)->player = 0;
	(*play)->p_s_x = 0;
	(*play)->p_s_y = 0;
	(*play)->i = 0;
	(*play)->j = 0;
	(*play)->x = 0;
	(*play)->y = 0;
}