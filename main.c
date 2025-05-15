/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:21:29 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/15 18:40:22 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	t_game		game;
	t_map		map;
	t_player	player;
	game.mlx = mlx_init();
	if (!ft_init_map(&map, argv[1]))
	{
		ft_free(&game);
	}
	if (!ft_init_p(&player))
	{
		ft_free(&game);
	}
	ft_start(&map, &player, game);
	return (0);
}
