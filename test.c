#include "lib/libft/libft/libft.h"
#include "lib/libft/printf/ft_printf.h"
#include "lib/mlx/mlx.h"
#include "so_long.h"


int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		printf("keycode -- %d\n", keysym);
		ft_free(game);
		exit(1);
	}
	else 
		printf("keycode -- %d\n", keysym);
	return (0);
}

int main()
{
	t_game game;
	t_map	map;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1000, 1000 , "daniel");
	ft_init_map(&map, "maps/test_map1.ber");
	game.map = &map;
	game.pos = 0;
	game.img = malloc(sizeof(t_data) * (game.map->height * game.map->width));
	if (!game.img)
	{
		printf("Failed to allocate memory for game.img");
		return(1);
	}
	if(!ft_render_map(&game))
	{
		ft_printf("something went wrong rendering the game");
		ft_free(&game);
	}
	mlx_key_hook(game.win, handle_input, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
	return (0);
}
