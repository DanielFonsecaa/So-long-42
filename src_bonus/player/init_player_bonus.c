/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:20:45 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/21 18:46:24 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_init_p(t_player *player)
{
	if (!player)
		return (0);
	player->x = 0;
	player->y = 0;
	player->moves = 0;
	player->is_moving = 0;
	player->frame_counter = 0;
	return (1);
}
