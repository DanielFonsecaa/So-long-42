/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:12:26 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/16 16:13:15 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_goals(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if (map->design[y][x] == 'C')
				map->is_collect++;
			else if (map->design[y][x] == 'E')
				map->is_exit++;
			else if (map->design[y][x] == 'P')
				map->is_player++;
			x++;
		}
		y++;
	}
	if (map->is_collect < 1 || map->is_exit != 1 || map->is_player != 1)
		return (0);
	return (1);
}

int	ft_check_walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width -1)
		{
			if (map->design[0][x] != '1')
				return (0);
			if (map->design[y][0] != '1')
				return (0);
			if (map->design[y][map->width - 1] != '1')
				return (0);
			if (map->design[map->height - 1][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_bad_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width -1)
		{
			if (map->design[y][x] != '1' && map->design[y][x] != 'E' && map->design[y][x] != 'C' && map->design[y][x] != 'P' && map->design[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_all(t_map *map, char *file)
{
	if (!ft_check_bad_map(map))
		return (ft_printf("Error, bad map .ber"), 0);
	ft_printf("passei bad map");
	if (!ft_check_walls(map))
		return (ft_printf("Error, wrong walls"), 0);
	ft_printf("passei wrong walls");
	if (!ft_check_map_goals(map))
		return (ft_printf("Error, wrong goals"), 0);
	ft_printf("passei wrong goals");
	if (!ft_check_path(map, file))
		return (ft_printf("Error, no path to conclude map"), 0);
	ft_printf("passei");
	return (1);
}