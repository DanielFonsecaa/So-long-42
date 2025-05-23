/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:41:18 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/23 10:25:35 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_enemy_animation(t_game *game)
{
	int	x;
	int	y;

	x = game->map->e_start_x;
	y = game->map->e_start_y;
	game->frame_counter_enemy++;
	game->animation_speed_enemy = 40000;
	if (game->frame_counter_enemy >= game->animation_speed_enemy)
	{
		game->frame_counter_enemy = 0;
		game->current_sprite_enemy = (game->current_sprite_enemy + 1) % 3;
		if (game->current_sprite_enemy == 0)
			ft_destroy_create_image(game, SAKURA, x, y);
		else if (game->current_sprite_enemy == 1)
			ft_destroy_create_image(game, SAKURA1, x, y);
		else
			ft_destroy_create_image(game, SAKURA2, x, y);
	}
	return (0);
}

int	ft_exit_2_animation(t_game *game)
{
	int	x;
	int	y;

	x = game->map->exit_x;
	y = game->map->exit_y;
	game->frame_counter++;
	game->animation_speed = 40000;
	if (game->frame_counter >= game->animation_speed)
	{
		game->frame_counter = 0;
		game->current_sprite = (game->current_sprite + 1) % 3;
		if (game->current_sprite == 0)
			ft_destroy_create_image(game, HINATA, x, y);
		else if (game->current_sprite == 1)
			ft_destroy_create_image(game, HINATA2, x, y);
		else
			ft_destroy_create_image(game, HINATA3, x, y);
	}
	return (0);
}

int	ft_exit_animation(t_game *game)
{
	int	x;
	int	y;

	x = game->map->exit_x;
	y = game->map->exit_y;
	game->frame_counter++;
	game->animation_speed = 40000;
	if (game->frame_counter >= game->animation_speed)
	{
		game->frame_counter = 0;
		game->current_sprite = (game->current_sprite + 1) % 3;
		if (game->current_sprite == 0)
			ft_destroy_create_image(game, HINATA_BACK, x, y);
		else if (game->current_sprite == 1)
			ft_destroy_create_image(game, HINATA_BACK2, x, y);
		else
			ft_destroy_create_image(game, HINATA_BACK3, x, y);
	}
	return (0);
}

void	ft_change_exit(t_game *game)
{
	int	res;
	int	x;
	int	y;

	x = game->map->exit_x;
	y = game->map->exit_y;
	res = 64;
	mlx_destroy_image(game->mlx, game->img[x + y].img);
	game->img[x + y].img = mlx_xpm_file_to_image(game->mlx,
			HINATA, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img[x + y].img, x * res, y * res);
}

int	ft_animation(t_game *game)
{
	static int	flag = 1;

	if (flag && game->map->is_collect == 0)
	{
		ft_change_exit(game);
		flag = 0;
	}
	if (flag)
		ft_exit_animation(game);
	else
		ft_exit_2_animation(game);
	ft_enemy_animation(game);
	ft_player_animation(game);
	return (0);
}
