/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:10:02 by cpillay           #+#    #+#             */
/*   Updated: 2018/09/01 16:13:22 by cpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	store_player(t_game *set_player)
{
	char	*line;

	get_next_line(0, &line);
	set_player->player_num = ft_atoi(10 + line);
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

int		dynamic_info(t_game *holder)
{
	get_map_dim(holder);
	get_piece_dim(holder);
	return (0);
}
