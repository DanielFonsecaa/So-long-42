/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-fons <dda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:51:18 by dda-fons          #+#    #+#             */
/*   Updated: 2025/05/22 12:25:02 by dda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft/libft.h"
# include <../X11/keysym.h>
# include <stdlib.h>
# include <../X11/X.h>

# define EXTENSION ".ber"
# define WALL "textures/tree.xpm"
# define HAT "textures/hat.xpm"
# define FLOOR "textures/floor.xpm"
# define NARUTO "textures/naruto.xpm"
# define NARUTO1 "textures/naruto2.xpm"
# define NARUTO2 "textures/naruto3.xpm"
# define NARUTOLEFT "textures/naruto_left.xpm"
# define NARUTORIGHT "textures/naruto_right.xpm"
# define NARUTOUP "textures/naruto_up.xpm"
# define HINATA_BACK "textures/hinata_back.xpm"
# define HINATA_BACK2 "textures/hinata_back2.xpm"
# define HINATA_BACK3 "textures/hinata_back3.xpm"
# define HINATA "textures/hinata.xpm"
# define HINATA2 "textures/hinata2.xpm"
# define HINATA3 "textures/hinata3.xpm"
# define SAKURA "textures/sakura.xpm"
# define SAKURA1 "textures/sakura2.xpm"
# define SAKURA2 "textures/sakura3.xpm"
# define SIZE 64
# define WIN_MESSAGE "YOU WON\nYOU DID %d MOVES.\nIS THIS YOUR BEST?\n"
# define LOSE_MESSAGE "YOU LOSE...\nWANNA TRY AGAIN?\n"

typedef struct s_map
{
	int		width;
	int		height;
	int		start_x;
	int		start_y;
	int		exit_x;
	int		exit_y;
	int		e_start_x;
	int		e_start_y;
	int		is_collect;
	int		is_exit;
	int		is_player;
	int		is_enemy;
	int		is_floor;
	char	**design;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
	int	is_moving;
	int	frame_counter;
}	t_player;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	direction;
}	t_enemy;

typedef struct s_data
{
	void	*img;
	char	*add;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*player;
	t_enemy		*enemy;
	t_data		*img;
	int			frame_counter;
	int			current_sprite;
	int			p_current_sprite;
	int			current_sprite_enemy;
	int			frame_counter_enemy;
	int			animation_speed;
	int			animation_speed_enemy;
	int			pos;
}	t_game;

void	ft_put_value(t_map *map);
int		ft_linelen(char *str);
void	ft_fill(t_map *map, char *file);
int		ft_mapsize(t_map *map, char *file);
int		ft_init_map(t_map *map, char *file);
char	*ft_selec_img(int x, int y, t_map *map);
int		ft_put_img_in_window(t_game *game, int x, int y, t_map *map);
int		ft_render_map(t_game *game);
int		handle_input(int keysym, t_game *game);
void	ft_free_design(t_map *map);
void	ft_free_img(t_game *game);
void	ft_free(t_game *game);
void	ft_start(t_map *map, t_player *player, t_game game);
int		ft_init_p(t_player *player);
int		main(int argc, char **argv);
void	ft_up(t_game *game);
void	ft_left(t_game *game);
void	ft_down(t_game *game);
void	ft_rigth(t_game *game);
void	is_movement(int keysym, t_game *game);
int		ft_check_up(t_game *game);
int		ft_check_down(t_game *game);
int		ft_check_left(t_game *game);
int		ft_check_rigth(t_game *game);
int		ft_check_map_goals(t_map *map);
int		ft_check_walls(t_map *map);
int		ft_check_bad_map(t_map *map);
int		ft_check_all(t_map *map, char *file);
int		ft_check_path(t_map *map, char *file);
void	ft_find_path(t_map *map, int x, int y);
int		is_goal(char c);
void	ft_get_p(t_map *map);
void	ft_finish(t_game *game);
int		ft_quit(t_game *game);
int		ft_check_map_name(char *file);
int		ft_can_move(t_game *game, int x, int y);
void	ft_get_e(t_map *map);
int		ft_init_e(t_enemy *enemy);
int		ft_enemy_animation(t_game *game);
void	ft_destroy_create_image(t_game *game, char *str, int x, int y);
void	ft_destroy_create_player_image(t_game *game, char *str);
void	ft_player_animation(t_game *game);
int		ft_animation(t_game *game);
void	ft_change_exit(t_game *game);
int		ft_exit_animation(t_game *game);
int		ft_exit_2_animation(t_game *game);
void	ft_print_moves(t_game *game);

#endif
