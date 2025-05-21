/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:20:45 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/21 14:32:54 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_init_e(t_enemy *enemy)
{
	if (!enemy)
		return (0);
	enemy->x = 0;
	enemy->y = 0;
	return (1);
}

void	ft_get_e(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if (map->design[y][x] == 'X')
			{
				map->e_start_x = x;
				map->e_start_y = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_destroy_create_image(t_game *game, char *str)
{
	int	res;
	int	x;
	int	y;

	x = game->enemy->x;
	y = game->enemy->y;
	res = 64;
	mlx_destroy_image(game->mlx, game->img[x + y].img);
	game->img[x + y].img = mlx_xpm_file_to_image(game->mlx, str, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img[x + y].img, x * res, y * res);
}

int	ft_enemy_animation(t_game *game)
{
	game->frame_counter++;
	game->animation_speed = 40000;
	if (game->frame_counter >= game->animation_speed)
	{
		game->frame_counter = 0;
		game->current_sprite = (game->current_sprite + 1) % 3;
		if (game->current_sprite == 0)
			ft_destroy_create_image(game, SAKURA);
		else if (game->current_sprite == 1)
			ft_destroy_create_image(game, SAKURA1);
		else
			ft_destroy_create_image(game, SAKURA2);
	}
	return (0);
}
