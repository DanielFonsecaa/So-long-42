/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:20:45 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/15 13:22:11 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_p(t_player *player)
{
	if (!player)
		return (0);
	player->x = 0;
	player->y = 0;
	player->moves = 0;
	return (1);
}
