/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:17:35 by ctelma            #+#    #+#             */
/*   Updated: 2020/03/09 14:42:37 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

# include "../ft_printf/header/ft_printf.h"
# include <fcntl.h>

# define BUFF_SIZE 1
# define FT_SKIP(s) get_next_line(0, &s), free(s)
# define ME -1
# define EN -2

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
	int		player;
	char	player_c;
	int		**m;
	int		m_s_x;
	int		m_s_y;
	int		**piece;
	int		p_s_x;
	int		p_s_y;
	int 	i;
	int 	j;
	int		x;
	int 	y;
	int 	score;
	int 	tempx;
	int 	tempy;
	int 	score2;
	int 	tempx2;
	int		tempy2;
	int 	is_zero;
	int 	startx;
	int 	starty;
	int 	tempi;
	int 	tempj;
	int		flag_star;
};

int						get_next_line(const int fd, char **line);
void					choose_player(t_pl *play, char *s);
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
void					make_map(t_pl *p);
void					choose_player(t_pl *play, char *s);
void					check_1_line(t_pl *p, int i, int j, int c);
void					check_last_line(t_pl *p, int i, int j, int c);
void					check_mid_lines(t_pl *p, int i, int j, int c);
int						ft_min(int *arr, int size);
int						search_next_star(t_pl *p, int *i, int *j);
void					solve(t_pl *p);
int						count_score(t_pl *p, int i, int j, int *score);
int						count_before(t_pl *p, int j, int i, int *score);
int						count_after(t_pl *p, int j, int i, int *score);
#endif
