/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mov_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:24:24 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/22 12:43:14 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_print_moves(t_game *game)
{
    char    *str;
    char    *moves;
    int     res;
    void    *bg_img;

    res = 64;
    bg_img = mlx_new_image(game->mlx, SIZE, SIZE - 40);
    mlx_put_image_to_window(game->mlx, game->win, bg_img, SIZE - 30, SIZE - 30);
    mlx_destroy_image(game->mlx, bg_img);
    str = ft_itoa(game->player->moves);
    if (!str)
        return;
    moves = ft_strjoin("MOVES: ", str);
    free(str);
    if (!moves)
        return ;
    mlx_string_put(game->mlx, game->win, SIZE - 25, SIZE - 15, 0xFFFFFF, moves);
    free(moves);
}
