/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:45:29 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/21 11:29:31 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_design(t_map *map)
{
	int	i;

	i = 0;
	if (!map->design)
		return ;
	while (i < map->height)
		free(map->design[i++]);
	free(map->design);
}

void	ft_free_img(t_game *game)
{
	int	i;

	i = 0;
	if (game->img)
	{
		game->pos--;
		while (game->pos >= 0)
		{
			if (game->img[game->pos].img)
				mlx_destroy_image(game->mlx, game->img[game->pos].img);
			game->pos--;
		}
		free(game->img);
	}
}

void	ft_free(t_game *game)
{
	if (game->map)
		ft_free_design(game->map);
	ft_free_img(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
