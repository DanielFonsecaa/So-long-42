/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:48:52 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/14 18:37:45 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_selec_img(int x, int y, t_map *map)
{
	if (x == 0 || y == 0)
		return (WALL_TREE);
	if (x == (map->width - 1))
		return (WALL_TREE);
	if (y == (map->height - 1))
		return (WALL_TREE);
	if (map->design[y][x] == 'P')
		return (NARUTO);
	if (map->design[y][x] == '1')
		return (WALL_TREE);
	if (map->design[y][x] == 'C')
		return (HAT);
	if (map->design[y][x] == 'E')
		return (HINATA);
	return (FLOOR);
}

int	ft_put_img_in_window(t_game *game, int x, int y, t_map *map)
{
	int		img_width;
	int		img_height;
	char	*relative_path;

	if (game->pos >= (game->map->height * game->map->width))
	{
		ft_printf("Error: game->pos exceeds allocated size for game->img\n");
		return (1);
	}
	relative_path = NULL;
	relative_path = ft_selec_img(x, y, map);
	if (!relative_path)
	{
		ft_printf("Error: Failed to select image for x=%d, y=%d\n", x, y);
		return (0);
	}
	img_width = SIZE;
	img_height = SIZE;
	game->img[game->pos].img = mlx_xpm_file_to_image(game->mlx, relative_path, &img_width, &img_height);
	if (!game->img[game->pos].img)
	{
		ft_printf("Error: Failed to load image '%s'\n", relative_path);
		return (0);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img[game->pos++].img, x * SIZE, y * SIZE);
	return (1);
}

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;
	int	image;

	y = 0;
	while (y < (game->map->height))
	{
		x = 0;
		while (x < (game->map->width))
		{
			image = ft_put_img_in_window(game, x, y, game->map);
			if (!image)
				return (ft_printf("Error\nMissing image\n"), 0);
			x++;
		}
		y++;
	}
	return (1);
}
