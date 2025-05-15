/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:22:46 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/15 13:23:21 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		ft_free(game);
		exit(1);
	}
	else 
		ft_printf("keycode -- %d\n", keysym);
	return (0);
}
void	ft_start(t_map *map, t_player *player, t_game game)
{
	game.map = map;
	game.player = player;
	game.player->x = map->start_x;
	game.player->y = map->start_y;
	game.img = malloc(sizeof(t_data) * (game.map->height * game.map->width));
	if (!game.img)
	{
		ft_printf("Failed to allocate memory for game.img");
		return ;
	}
	game.pos = 0;
	game.win = mlx_new_window(game.mlx, map->width * SIZE, map->height * SIZE, "rui sucks");
	if (!ft_render_map(&game))
	{
		ft_printf("something went wrong rendering the game");
		ft_free(&game);
	}
	mlx_key_hook(game.win, handle_input, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	exit (0);
}
