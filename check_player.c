/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:12:26 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/16 16:13:15 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_p(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if (map->design[y][x] == 'P')
			{
				map->start_x = x;
				map->start_y = y;
			}
			x++;
		}
		y++;
	}
}

int	is_goal(char c)
{
	if (c == 'C')
		return (1);
	if (c == 'P')
		return (1);
	if (c == 'E')
		return (1);
	if (c == '0')
		return (1);
	return (0);
}

void	ft_find_path(t_map *map, int x, int y)
{
	if (map->design[y][x] == '1' || map->design[y][x] == 'F')
		return ;
	if (is_goal(map->design[y][x]))
	{
		if (map->design[y][x] == 'C')
			map->is_collect--;
		if (map->design[y][x] == 'E' && map->is_exit)
			map->is_exit--;
	}
	if (map->design[y][x] == 'E')
		return ;
	ft_find_path(map, x - 1, y);
	ft_find_path(map, x + 1, y);
	ft_find_path(map, x, y - 1);
	ft_find_path(map, x, y + 1);
}

int	ft_check_path(t_map *map, char *file)
{
	int	n_collect;
	int	x;
	int	y;

	ft_printf("entrei");
	ft_get_p(map);

	ft_printf("passei player \n");
	x = map->start_x;
	y = map->start_y;
	n_collect = map->is_collect;
	//ft_find_path(map, x, y);

	//ft_printf("passei find path \n");
	ft_free_design(map);

	ft_printf("passei free \n");
	ft_fill(map, file);

	ft_printf("passei fill \n");
	//if (n_collect != 0 || map->is_exit)
	//	return (0);
	return (1);
}