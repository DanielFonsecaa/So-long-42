/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:32:38 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/22 12:21:04 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_put_value(t_map *map)
{
	int	i;

	i = 0;
	map->width = 0;
	map->height = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->is_collect = 0;
	map->is_exit = 0;
	map->is_player = 0;
	map->is_enemy = 0;
	map->is_floor = 0;
	map->design = NULL;
	map->e_start_x = 0;
	map->e_start_y = 0;
}

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	ft_fill(t_map *map, char *file)
{
	int	fd;
	int	i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	i = 0;
	map->design = malloc(sizeof(char *) * (map->height));
	if (!map->design)
	{
		close(fd);
		return ;
	}
	while (i < map->height)
		map->design[i++] = get_next_line(fd);
	close(fd);
}

int	ft_mapsize(t_map *map, char *file)
{
	int		fd;
	char	*str;
	int		i;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	map->height = 1;
	i = ft_linelen(str);
	free(str);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		map->height++;
		map->width = ft_linelen(str);
		if (map->width != i)
			return (0);
		free(str);
		str = NULL;
	}
	close(fd);
	return (1);
}

int	ft_init_map(t_map *map, char *file)
{
	int	fd;

	map = ft_memset(map, 0, sizeof(t_map));
	fd = open(file, O_RDONLY);
	close(fd);
	if (fd < 0)
		return (ft_printf("Error\nNo map found\n"), 0);
	ft_put_value(map);
	if (!ft_mapsize(map, file))
		return (ft_printf("Error\nLines size different\n"), 0);
	ft_fill(map, file);
	if (!ft_check_all(map, file))
		return (0);
	return (1);
}
