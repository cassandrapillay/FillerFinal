/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:45:11 by cpillay           #+#    #+#             */
/*   Updated: 2018/09/01 15:23:12 by cpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void		get_player(t_game *set_player)
{
	if (set_player->player_num == 1)
	{
		set_player->indicator[0] = 'o';
		set_player->indicator[1] = 'O';
		set_player->enemy[0] = 'x';
		set_player->enemy[1] = 'X';
	}
	else
	{
		set_player->indicator[0] = 'x';
		set_player->indicator[1] = 'X';
		set_player->enemy[0] = 'o';
		set_player->enemy[1] = 'O';
	}
}

void		get_map_dim(t_game *set_map)
{
	int i;

	get_next_line(set_map->fd, &(set_map->line));
	i = 0;
	if (set_map->turn == 0)
	{
		set_map->map_height = ft_atoi(ft_strchr(set_map->line, ' '));
		set_map->map_width = ft_atoi(ft_strrchr(set_map->line, ' '));
		set_map->map = (char**)malloc(sizeof(char *) * set_map->map_height + 1);
	}
	get_next_line(set_map->fd, &(set_map->line));
	while (i < set_map->map_height)
	{
		get_next_line(set_map->fd, &(set_map->line));
		set_map->map[i] = ft_strdup(4 + set_map->line);
		i++;
	}
}

void		get_piece_dim(t_game *set_piece)
{
	int i;

	get_next_line(set_piece->fd, &(set_piece->line));
	i = 0;
	set_piece->piece_height = ft_atoi(ft_strsplit(set_piece->line, ' ')[1]);
	set_piece->piece_width = ft_atoi(ft_strsplit(set_piece->line, ' ')[2]);
	set_piece->piece = (char**)malloc(sizeof(char *)
			* set_piece->piece_height + 1);
	while (i < set_piece->piece_height)
	{
		get_next_line(set_piece->fd, &(set_piece->line));
		set_piece->piece[i] = ft_strdup(set_piece->line);
		i++;
	}
	set_piece->piece[set_piece->piece_height] = 0;
}

char		**malloc_stuff(int width, int height)
{
	char	**stuff;
	int		i;

	i = 0;
	width = 0;
	if (!(stuff = (char**)malloc(sizeof(char*) * (height + 1))))
		return (NULL);
	i++;
	return (stuff);
}
