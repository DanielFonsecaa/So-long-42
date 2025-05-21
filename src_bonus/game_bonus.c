/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:22:46 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/21 18:44:24 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_finish(t_game *game)
{
	ft_free(game);
	return ;
}

int	ft_quit(t_game *game)
{
	ft_printf("YOU DID %d MOVES\n", game->player->moves);
	ft_printf(LOSE_MESSAGE);
	ft_free(game);
	return (0);
}

void	is_movement(int keysym, t_game *game)
{
	if (keysym == XK_w)
		ft_up(game);
	if (keysym == XK_a)
		ft_left(game);
	if (keysym == XK_s)
		ft_down(game);
	if (keysym == XK_d)
		ft_rigth(game);
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		ft_quit(game);
		exit(1);
	}
	else
		is_movement(keysym, game);
	return (0);
}

void	ft_start(t_map *map, t_player *player, t_game game)
{
	game.map = map;
	game.player = player;
	game.player->x = map->start_x;
	game.player->y = map->start_y;
	game.enemy->x = map->e_start_x;
	game.enemy->y = map->e_start_y;
	game.p_current_sprite = 0;
	game.img = malloc(sizeof(t_data) * (game.map->height * game.map->width));
	if (!game.img)
	{
		ft_printf("Error\n Failed to allocate memory for the game.img");
		return (ft_finish(&game));
	}
	game.pos = 0;
	game.win = mlx_new_window(game.mlx, map->width * SIZE,
			map->height * SIZE, "Naruto");
	if (!ft_render_map(&game))
	{
		ft_printf("Error\n Could not render the game");
		ft_finish(&game);
	}
	mlx_hook(game.win, KeyPress, KeyPressMask, &handle_input, &game);
	mlx_hook(game.win, DestroyNotify, 0, &ft_quit, &game);
	mlx_loop_hook(game.mlx, &ft_animation, &game);
	mlx_loop(game.mlx);
}
