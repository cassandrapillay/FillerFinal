/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:41:01 by cpillay           #+#    #+#             */
/*   Updated: 2018/09/01 15:25:43 by cpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_game
{
	char		*player_name;
	int			topx;
	int			topy;
	int			player_num;
	int			map_width;
	int			map_height;
	int			piece_width;
	int			piece_height;
	char		**map;
	char		**piece;
	char		indicator[2];
	char		enemy[2];
	int			turn;
	int			fd;
	char		*line;
}				t_game;

void			place_piece(t_game *place);
int				absdiff(int a, int b);
void			get_player(t_game *set_player);
void			get_map_dim(t_game *set_map);
void			get_piece_dim(t_game *set_piece);
char			**malloc_stuff(int width, int height);
int				store_map(t_game *game);
void			store_player(t_game *holder);
int				dynamic_info(t_game *holder);
int				store_piece(t_game *game);
int				check_piece(t_game *check);
int				check_move(t_game *check, int i, int j);
int				check_enemy(t_game *check);
#endif
