/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:48:52 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/21 19:20:55 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_selec_img(int x, int y, t_map *map)
{
	if (x == 0 || y == 0)
		return (WALL);
	if (x == (map->width - 1))
		return (WALL);
	if (y == (map->height - 1))
		return (WALL);
	if (map->design[y][x] == 'P')
		return (NARUTO);
	if (map->design[y][x] == '1')
		return (WALL);
	if (map->design[y][x] == 'C')
		return (HAT);
	if (map->design[y][x] == 'E')
	{
		map->exit_x = x;
		map->exit_y = y;
		return (HINATA_BACK);
	}
	if (map->design[y][x] == 'X')
		return (SAKURA);
	return (FLOOR);
}

int	ft_put_img_in_window(t_game *game, int x, int y, t_map *map)
{
	int		img_width;
	int		img_height;
	char	*relative_path;

	if (game->pos >= (game->map->height * game->map->width))
		return (ft_printf("Error\ngame->pos exceeds size for game->img\n"), 1);
	relative_path = NULL;
	relative_path = ft_selec_img(x, y, map);
	if (!relative_path)
		return (ft_printf("Error\nFailed to select image for x, y\n", x, y), 0);
	img_width = SIZE;
	img_height = SIZE;
	game->img[game->pos].img = mlx_xpm_file_to_image(game->mlx,
			relative_path, &img_width, &img_height);
	if (!game->img[game->pos].img)
	{
		ft_printf("Error\nFailed to load image '%s'\n", relative_path);
		return (0);
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->img[game->pos++].img, x * SIZE, y * SIZE);
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
				return (ft_printf("Error\n Missing image"), 0);
			x++;
		}
		y++;
	}
	return (1);
}
