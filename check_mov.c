/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:12:26 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/16 16:13:15 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_printf("You Win");
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
		ft_printf("You Win");
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
		ft_printf("You Win");
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
	{
		ft_printf("nao posso andar direita 'e parede");
		return (0);
	}	
	if (game->map->design[y][x + 1] == 'C')
	{
		game->map->is_collect--;
		game->map->design[y][x + 1] = '0';
	}
	if (game->map->design[y][x + 1] == 'E' && !game->map->is_collect)
	{
		ft_printf("You Win");
	}
	if (game->map->design[y][x + 1] == 'E' && game->map->is_collect)
	{
		ft_printf("nao andar direita");
		return (0);
	}
	ft_printf("posso andar direita");
	return (1);
}