/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:20:45 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/21 14:32:54 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_init_e(t_enemy *enemy)
{
	if (!enemy)
		return (0);
	enemy->x = 0;
	enemy->y = 0;
	return (1);
}

void	ft_get_e(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if (map->design[y][x] == 'X')
			{
				map->e_start_x = x;
				map->e_start_y = y;
			}
			x++;
		}
		y++;
	}
}
