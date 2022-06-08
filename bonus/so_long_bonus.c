/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:47:10 by iayni             #+#    #+#             */
/*   Updated: 2022/05/24 22:45:16 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_player(t_assets *as, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < as->map_height)
	{
		j = -1;
		while (++j < as->map_width)
		{
			if (as->map[i][j] == 'P')
			{
				if (as->map[i + y][j + x] == '0' ||
						as->map[i + y][j + x] == 'C' ||
						as->map[i + y][j + x] == 'O')
					as->map[i][j] = ((as->move_count++,
								as->map[i + y][j + x] = 'P'), '0');
				else if (as->map[i + y][j + x] == 'N' ||
						as->map[i + y][j + x] == 'Y')
					return (1);
				return (0);
			}
		}
	}
	return (0);
}

void	check_win(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mlx->assets->map_height)
	{
		j = 0;
		while (j < mlx->assets->map_width)
		{
			if (mlx->assets->map[i][j] == 'E' || mlx->assets->map[i][j] == 'O')
				return ;
			j++;
		}
	}
	close_window(mlx);
}

int	key_hook(int key, t_mlx *mlx)
{
	int		lost;

	if (key == 53)
		lost = close_window(mlx);
	if (key == 1)
		lost = move_player(mlx->assets, 0, 1);
	if (key == 13)
		lost = move_player(mlx->assets, 0, -1);
	if (key == 0)
		lost = move_player(mlx->assets, -1, 0);
	if (key == 2)
		lost = move_player(mlx->assets, 1, 0);
	if (lost == 1)
		close_window(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	open_close(mlx->assets);
	check_win(mlx);
	check_enemies(mlx->assets);
	render_assets(mlx);
	mlx->assets->t = ((free(mlx->assets->t)), ft_itoa(mlx->assets->move_count));
	mlx_string_put(mlx->mlx, mlx->win, 20, 20, 0x0000, mlx->assets->t);
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->assets->wall.img);
	mlx_destroy_image(mlx->mlx, mlx->assets->coin.img);
	mlx_destroy_image(mlx->mlx, mlx->assets->player.img);
	mlx_destroy_image(mlx->mlx, mlx->assets->door_closed.img);
	mlx_destroy_image(mlx->mlx, mlx->assets->door_open.img);
	mlx_destroy_image(mlx->mlx, mlx->assets->enemy_1.img);
	mlx_destroy_image(mlx->mlx, mlx->assets->enemy_2.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	while (mlx->assets->map_height--)
		free(mlx->assets->map[mlx->assets->map_height]);
	free(mlx->assets->map);
	free(mlx->assets->t);
	free(mlx->assets);
	free(mlx->mlx);
	exit(0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (ft_putstr("No Map Found"), 0);
	mlx.mlx = mlx_init();
	if (!validate_map(av[1], &mlx))
		return (ft_putstr("Invalid Map"), 0);
	mlx.win = mlx_new_window(mlx.mlx, 56 * mlx.assets->map_width,
			56 * mlx.assets->map_height, "So_long");
	load_assets(&mlx);
	render_assets(&mlx);
	mlx_hook(mlx.win, 2, 0, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx.assets->t = ft_strdup("0");
	mlx_string_put(mlx.mlx, mlx.win, 20, 20, 0x0000, mlx.assets->t);
	mlx_loop(mlx.mlx);
	return (0);
}
