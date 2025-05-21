/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mov_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:12:26 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/21 13:03:35 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_can_move(t_game *game, int x, int y)
{
	if (game->map->design[y][x] == '1')
		return (0);
	if (game->map->design[y][x] == 'C')
	{
		game->map->is_collect--;
		game->map->design[y][x] = '0';
	}
	if (game->map->design[y][x] == 'X')
	{
		ft_printf(LOSE_MESSAGE);
		return (ft_finish(game), 0);
	}
	if (game->map->design[y][x] == 'E' && !game->map->is_collect)
	{
		game->player->moves++;
		ft_printf(WIN_MESSAGE, game->player->moves);
		return (ft_finish(game), 0);
	}
	if (game->map->design[y][x] == 'E' && game->map->is_collect)
		return (0);
	return (1);
}

int	ft_check_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (!ft_can_move(game, x, y - 1))
		return (0);
	return (1);
}

int	ft_check_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (!ft_can_move(game, x, y + 1))
		return (0);
	return (1);
}

int	ft_check_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (!ft_can_move(game, x - 1, y))
		return (0);
	return (1);
}

int	ft_check_rigth(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (!ft_can_move(game, x + 1, y))
		return (0);
	return (1);
}
