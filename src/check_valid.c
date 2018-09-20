/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:04:44 by cpillay           #+#    #+#             */
/*   Updated: 2018/09/01 16:13:12 by cpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int			absdiff(int a, int b)
{
	if (a < b)
		return (b - a);
	else
		return (a - b);
}

int			score_gen(int x, int y, t_game *check)
{
	int score;

	score = 0;
	if (check->map_height == 15)
	{
		if (check->indicator[1] == 'X')
			score = 200 - (absdiff(x, 7) + absdiff(y, 0));
		else
			score = (check->turn < 3) ? 200 - (absdiff(x, 3) + absdiff(y, 0)) :
				200 - (absdiff(x, 7) + absdiff(y, 16));
	}
	else if (check->map_height == 24 && check->indicator[1] == 'O')
		score = 200 - (absdiff(x, 12) + absdiff(y, 20));
	else if (check->map_height == 24 && check->indicator[1] == 'X')
	{
		if (check->turn > 35)
			score = (absdiff(x, 12) + absdiff(y, 20));
		else if (check->turn % 2 == 0)
			score = 1000 - (absdiff(x, 19) + absdiff(y, 0));
		else
			score = 1000 - (absdiff(y, 32) + absdiff(x, 0));
	}
	else if (check->map_height == 100)
		score = 200 - (absdiff(x, 50) + absdiff(y, 49));
	return (score);
}

int			check_move(t_game *check, int i, int j)
{
	int k;
	int l;
	int checker;

	k = -1;
	l = -1;
	checker = 0;
	while (++k < check->piece_height)
	{
		l = -1;
		while (++l < check->piece_width)
		{
			if (check->piece[k][l] == '*')
			{
				if (check->map[i + k][j + l] == check->indicator[1])
					checker++;
				else if (check->map[i + k][j + l] == check->enemy[1] ||
						check->map[i + k][j + l] == check->enemy[0])
					return (0);
			}
		}
	}
	return (checker);
}

int			check_piece(t_game *check)
{
	int i;
	int j;
	int score;

	i = -1;
	score = 0;
	while (++i < (check->map_height - check->piece_height))
	{
		j = -1;
		while (++j < (check->map_width - check->piece_width))
		{
			if (check_move(check, i, j) == 1)
			{
				if (score < score_gen(i, j, check))
				{
					score = score_gen(i, j, check);
					check->topx = i;
					check->topy = j;
				}
			}
		}
	}
	if (score == 0)
		check->turn = -1;
	return (0);
}

void		place_piece(t_game *place)
{
	int	x;
	int	y;

	x = place->topx;
	y = place->topy;
	ft_putnbr(x);
	ft_putstr(" ");
	ft_putnbr(y);
	ft_putstr("\n");
}
