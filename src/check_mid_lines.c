/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mid_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:11:20 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/08 18:04:06 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

static void	check_left_corner(t_pl *p, int i, int j, int c)
{
	int arr[5];

	if ((p->m[i - 1][j] == c || p->m[i - 1][j + 1] == c || p->m[i][j + 1] == c
		|| p->m[i + 1][j + 1] == c || p->m[i + 1][j] == c) && p->m[i][j] == 0)
		p->m[i][j] = 1;
	else if ((p->m[i - 1][j] > 0 || p->m[i - 1][j + 1] > 0 ||
		p->m[i][j + 1] > 0 || p->m[i + 1][j + 1] > 0 || p->m[i + 1][j] > 0)
		&& p->m[i][j] >= 0)
	{
		arr[0] = p->m[i - 1][j];
		arr[1] = p->m[i - 1][j + 1];
		arr[2] = p->m[i][j + 1];
		arr[3] = p->m[i + 1][j + 1];
		arr[4] = p->m[i + 1][j];
		p->m[i][j] = ft_min(arr, 5) + 1;
	}
}

static void	check_mid(t_pl *p, int i, int j, int c)
{
	int  arr[8];

	if ((p->m[i - 1][j - 1] == c || p->m[i - 1][j] == c || p->m[i][j + 1] == c
		 || p->m[i - 1][j + 1] == c || p->m[i + 1][j + 1] == c ||
			p->m[i + 1][j] == c || p->m[i + 1][j - 1] == c ||
			p->m[i][j - 1] == c) && p->m[i][j] >= 0)
		p->m[i][j] = 1;
	else if ((p->m[i - 1][j - 1] > 0 || p->m[i - 1][j] > 0 ||
		p->m[i][j + 1] > 0 || p->m[i - 1][j + 1] > 0 || p->m[i + 1][j + 1] > 0
		|| p->m[i + 1][j] > 0 || p->m[i + 1][j - 1] > 0 || p->m[i][j - 1] > 0)
		&& p->m[i][j] >= 0)
	{
		arr[0] = p->m[i - 1][j - 1];
		arr[1] = p->m[i - 1][j];
		arr[2] = p->m[i - 1][j + 1];
		arr[3] = p->m[i + 1][j + 1];
		arr[4] = p->m[i + 1][j];
		arr[5] = p->m[i][j + 1];
		arr[6] = p->m[i + 1][j - 1];
		arr[7] = p->m[i][j - 1];
		p->m[i][j] = ft_min(arr, 8) + 1;
	}
}

static void	check_right_corner(t_pl *p, int i, int j, int c)
{
	int arr[5];

	if ((p->m[i - 1][j] == c || p->m[i - 1][j - 1] == c || p->m[i][j - 1] == c
		|| p->m[i + 1][j - 1] == c || p->m[i + 1][j] == c) && p->m[i][j] >= 0)
		p->m[i][j] = 1;
	else if ((p->m[i - 1][j] > 0 || p->m[i - 1][j - 1] > 0 ||
		p->m[i][j - 1] > 0 || p->m[i + 1][j - 1] > 0 || p->m[i + 1][j] > 0)
		&& p->m[i][j] >= 0)
	{
		arr[0] = p->m[i - 1][j];
		arr[1] = p->m[i - 1][j - 1];
		arr[2] = p->m[i][j - 1];
		arr[3] = p->m[i + 1][j - 1];
		arr[4] = p->m[i + 1][j];
		p->m[i][j] = ft_min(arr, 5) + 1;
	}
}

void	check_mid_lines(t_pl *p, int i, int j, int c)
{
	if (j == 0)
		check_left_corner(p, i, j, c);
	else if (j != 0 && j != p->m_s_x - 1)
		check_mid(p, i, j, c);
	else if (j == p->m_s_x - 1)
		check_right_corner(p, i, j, c);
}
