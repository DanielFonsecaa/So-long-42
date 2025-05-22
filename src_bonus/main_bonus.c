/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:21:29 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/22 11:32:36 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_cancel(t_map *map, t_game *game, char *str)
{
	ft_printf("Error\nFailed to initialize %s\n", str);
	ft_free_design(map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_map		map;
	t_player	player;
	t_enemy		enemy;

	if (argc != 2)
	{
		ft_printf("Error\n Usage: ./so_long <map_file.ber>\n");
		return (0);
	}
	game.mlx = mlx_init();
	if (!ft_init_map(&map, argv[1]))
		return (ft_cancel(&map, &game, "map"), 0);
	if (!ft_init_p(&player))
		return (ft_cancel(&map, &game, "player"), 0);
	if (!ft_init_e(&enemy))
		return (ft_cancel(&map, &game, "enemy"), 0);
	game.enemy = &enemy;
	game.frame_counter_enemy = 0;
	game.current_sprite_enemy = 0;
	game.frame_counter = 0;
	game.current_sprite = 0;
	ft_start(&map, &player, game);
	return (0);
}
