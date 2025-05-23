/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:02:32 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/23 10:45:08 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_handle_exit_timer(t_game *game, char *str)
{
	int	middle_x;
	int	middle_y;

	middle_x = (SIZE * game->map->width) / 2 - (ft_strlen(str) * 5);
	middle_y = (SIZE * game->map->height) / 2;
	mlx_string_put(game->mlx, game->win, middle_x, middle_y, 0x000000, str);
	mlx_do_sync(game->mlx);
	if (game->is_exiting)
	{
		while (game->exit_timer <= 400000000)
			game->exit_timer++;
	}
	return (0);
}
