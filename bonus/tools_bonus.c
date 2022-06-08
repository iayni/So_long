/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:51:39 by iayni             #+#    #+#             */
/*   Updated: 2022/05/24 22:14:35 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img	put_img(t_mlx mlx, char *path)
{
	t_img	ig;

	ig.img = mlx_xpm_file_to_image(mlx.mlx, path, &ig.width, &ig.height);
	return (ig);
}

int	load_assets(t_mlx *mlx)
{
	mlx->assets->wall = put_img(*mlx, "../assets/wall.xpm");
	mlx->assets->coin = put_img(*mlx, "../assets/coin.xpm");
	mlx->assets->player = put_img(*mlx, "../assets/player.xpm");
	mlx->assets->door_open = put_img(*mlx, "../assets/door_open.xpm");
	mlx->assets->door_closed = put_img(*mlx, "../assets/door_closed.xpm");
	mlx->assets->enemy_1 = put_img(*mlx, "../assets/enemy1.xpm");
	mlx->assets->enemy_2 = put_img(*mlx, "../assets/enemy2.xpm");
	mlx->assets->coin_count = 0;
	mlx->assets->move_count = 0;
	return (0);
}

int	check_enemies(t_assets *ass)
{
	int		i;
	int		j;

	i = -1;
	while (++i < ass->map_height)
	{
		j = -1;
		while (++j < ass->map_width)
		{
			if (ass->map[i][j] == 'N')
				ass->map[i][j] = 'Y';
			else if (ass->map[i][j] == 'Y')
				ass->map[i][j] = 'N';
		}
	}
	return (0);
}

void	open_close(t_assets *ass)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ass->map_height)
	{
		if (ft_strrchr(ass->map[i], 'C') != NULL)
			return ;
	}
	i = -1;
	while (++i < ass->map_height)
	{
		j = -1;
		while (++j < ass->map_width)
		{
			if (ass->map[i][j] == 'E')
				ass->map[i][j] = 'O';
		}
	}
}

void	render_assets(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mlx->assets->map_height)
	{
		j = -1;
		while (++j < mlx->assets->map_width)
		{
			if (mlx->assets->map[i][j] == '1')
				mlx_img_put(mlx, mlx->assets->wall, j * 56, i * 56);
			else if (mlx->assets->map[i][j] == 'C')
				mlx_img_put(mlx, mlx->assets->coin, j * 56, i * 56);
			else if (mlx->assets->map[i][j] == 'P')
				mlx_img_put(mlx, mlx->assets->player, j * 56, i * 56);
			else if (mlx->assets->map[i][j] == 'O')
				mlx_img_put(mlx, mlx->assets->door_open, j * 56, i * 56);
			else if (mlx->assets->map[i][j] == 'E')
				mlx_img_put(mlx, mlx->assets->door_closed, j * 56, i * 56);
			else if (mlx->assets->map[i][j] == 'N')
				mlx_img_put(mlx, mlx->assets->enemy_1, j * 56, i * 56);
			else if (mlx->assets->map[i][j] == 'Y')
				mlx_img_put(mlx, mlx->assets->enemy_2, j * 56, i * 56);
		}
	}
}
