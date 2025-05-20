/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:32:38 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/20 16:49:02 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_put_value(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->is_collect = 0;
	map->is_exit = 0;
	map->is_player = 0;
	map->is_wall = 0;
	map->is_floor = 0;
	map->design = NULL;
}

int ft_linelen(char *str)
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
    i = 0;
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

	fd = open(file, O_RDONLY);
	map->height = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		map->height++;
		map->width = ft_linelen(str);
		free(str);
		str = NULL;
	}
	close(fd);
	return (1);
}

int	ft_init_map(t_map *map, char *file)
{
	int fd;
	
	map = ft_memset(map, 0, sizeof(t_map));
	fd = open(file, O_RDONLY);
	close(fd);
	if (fd < 0)
		return (ft_printf("Error\nNo map found\n"), 0);
	ft_put_value(map);
	ft_mapsize(map, file);
	//if (map->invalid)
	//	return (ft_printf("Error\nLines size different\n"), 0);
	ft_fill(map, file);
	if (!ft_check_all(map, file))
		return (0);
	return (1);
}
