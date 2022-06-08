/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:49:29 by iayni             #+#    #+#             */
/*   Updated: 2022/05/24 22:19:56 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map, int i)
{
	int	j;

	j = -1;
	while (++j < i)
		free(map[j]);
	free(map);
}

void	mlx_img_put(t_mlx *mlx, t_img img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, x, y);
}

int	read_to_map(char *map, char ***mp)
{
	int		fd;
	char	tmp;
	int		i;

	fd = ((i = 0), open(map, O_RDONLY));
	if (fd == -1)
		return (0);
	while (read(fd, &tmp, 1) > 0)
	{
		if (tmp == '\n')
		{
			i++;
			*mp = (char **)ft_realloc(*mp, sizeof(char *) * (i + 1));
			if (!*mp)
				return (0);
			(*mp)[i] = (char *)malloc(sizeof(char));
			if (!(*mp)[i])
				return (0);
			(*mp)[i][0] = '\0';
		}
		else
			(*mp)[i] = ft_addchar((*mp)[i], tmp);
	}
	i++;
	return ((close(fd), i));
}
