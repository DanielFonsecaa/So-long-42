/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:12:26 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/22 13:12:56 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->design[y - 1][x] == '1')
		return (0);
	if (game->map->design[y - 1][x] == 'C')
	{
		game->map->is_collect--;
		game->map->design[y - 1][x] = '0';
	}
	if (game->map->design[y - 1][x] == 'E' && !game->map->is_collect)
	{
		game->player->moves++;
		ft_printf("You Won\n");
		ft_printf("You did %d moves\nThis is the best you can do?\n",
			game->player->moves);
		return (ft_finish(game), 0);
	}
	if (game->map->design[y - 1][x] == 'E' && game->map->is_collect)
		return (0);
	return (1);
}

int	ft_check_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->design[y + 1][x] == '1')
		return (0);
	if (game->map->design[y + 1][x] == 'C')
	{
		game->map->is_collect--;
		game->map->design[y + 1][x] = '0';
	}
	if (game->map->design[y + 1][x] == 'E' && !game->map->is_collect)
	{
		game->player->moves++;
		ft_printf("You Won\n");
		ft_printf("You did %d moves\nThis is the best you can do?\n",
			game->player->moves);
		return (ft_finish(game), 0);
	}
	if (game->map->design[y + 1][x] == 'E' && game->map->is_collect)
		return (0);
	return (1);
}

int	ft_check_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->design[y][x - 1] == '1')
		return (0);
	if (game->map->design[y][x - 1] == 'C')
	{
		game->map->is_collect--;
		game->map->design[y][x - 1] = '0';
	}
	if (game->map->design[y][x - 1] == 'E' && !game->map->is_collect)
	{
		game->player->moves++;
		ft_printf("You Won\n");
		ft_printf("You did %d moves\nThis is the best you can do?\n",
			game->player->moves);
		return (ft_finish(game), 0);
	}
	if (game->map->design[y][x - 1] == 'E' && game->map->is_collect)
		return (0);
	return (1);
}

int	ft_check_rigth(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->design[y][x + 1] == '1')
		return (0);
	if (game->map->design[y][x + 1] == 'C')
	{
		game->map->is_collect--;
		game->map->design[y][x + 1] = '0';
	}
	if (game->map->design[y][x + 1] == 'E' && !game->map->is_collect)
	{
		game->player->moves++;
		ft_printf("You Won\n");
		ft_printf("You did %d moves\nThis is the best you can do?\n",
			game->player->moves);
		return (ft_finish(game), 0);
	}
	else if (game->map->design[y][x + 1] == 'E' && game->map->is_collect)
		return (0);
	return (1);
}
