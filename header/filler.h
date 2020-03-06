/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:17:35 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/06 16:47:34 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

# include "../ft_printf/header/ft_printf.h"
# include <fcntl.h>

# define BUFF_SIZE 1
# define FT_SKIP(s) get_next_line(0, &s), free(s)

typedef	struct s_node	t_node;

struct					s_node
{
	char	*s;
	int		fd;
	t_node	*next;
};

typedef	struct s_pl		t_pl;

struct					s_pl
{
	int	player;
	int **map;
	int m_s_x;
	int m_s_y;
	int **piece;
	int p_s_x;
	int p_s_y;
	int my_pos1[2];
	int en_pos1[2];
};

int						get_next_line(const int fd, char **line);
void					ft_error(void);
void					read_map(t_pl *play);
int						**ft_set_matrix(int size_1, int size_2);
void					del_mem(void);
void					ft_set_struct(t_pl **play);
void					algoritm(t_pl *play);
void					check_correct_input(char *s, int flag);
void					read_map_size(t_pl *play, char *s);
void					read_piece_size(t_pl *play, char *s);
void					read_piece(t_pl * play);
void					first_push(t_pl *play);

#endif
