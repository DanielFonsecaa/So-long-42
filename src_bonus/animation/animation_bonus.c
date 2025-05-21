/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:16:06 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/21 19:31:30 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_destroy_create_player_image(t_game *game, char *str)
{
    int	res;
    int	x;
    int	y;

    x = game->player->x;
    y = game->player->y * game->map->width;
    res = 64;
    mlx_destroy_image(game->mlx, game->img[x + y].img);
    game->img[x + y].img = mlx_xpm_file_to_image(game->mlx, str, &res, &res);
    mlx_put_image_to_window(game->mlx, game->win, game->img[x + y].img,
        x * res, y / game->map->width * res);
}

void	ft_player_animation(t_game *game)
{
    if (game->player->is_moving == 1)
        return;
    game->player->frame_counter++;
    if (game->player->frame_counter >= 40000)
    {
        game->player->frame_counter = 0;
        game->p_current_sprite = (game->p_current_sprite + 1) % 3;
        
        if (game->p_current_sprite == 0)
            ft_destroy_create_player_image(game, NARUTO);
        else if (game->p_current_sprite == 1)
            ft_destroy_create_player_image(game, NARUTO1);
        else
            ft_destroy_create_player_image(game, NARUTO2);
        if (game->p_current_sprite == 0)
            game->player->is_moving = 0;
    }
}

void	ft_change_exit(t_game *game)
{
    int	res;
    int	x;
    int	y;

    x = game->map->exit_x;
    y = game->map->exit_y;
    res = 64;
    mlx_destroy_image(game->mlx, game->img[x + y].img);
    game->img[x + y].img = mlx_xpm_file_to_image(game->mlx,
        HINATA, &res, &res);
    mlx_put_image_to_window(game->mlx, game->win,
        game->img[x + y].img, x * res, y * res);
}

int	ft_animation(t_game *game)
{
    static int flag = 1;

    if (flag && game->map->is_collect == 0)
    {
        ft_change_exit(game);
        flag = 0;
    }
    
    ft_enemy_animation(game);
    ft_player_animation(game);
    return (0);
}
