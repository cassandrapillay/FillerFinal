/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:23:55 by cpillay           #+#    #+#             */
/*   Updated: 2018/09/01 16:13:40 by cpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		main(void)
{
	t_game	*holder;

	holder = (t_game *)malloc(sizeof(t_game));
	holder->turn = 0;
	holder->fd = 0;
	store_player(holder);
	while (1)
	{
		dynamic_info(holder);
		check_piece(holder);
		if (holder->turn == -1)
			break ;
		place_piece(holder);
		holder->turn++;
	}
	ft_putnbr(0);
	ft_putstr(" ");
	ft_putnbr(0);
	ft_putstr("\n");
	return (0);
}
