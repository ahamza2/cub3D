/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:28:20 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/25 08:19:15 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_player(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->player.height)
	{
		x = 0;
		while (x < mlx->player.width)
		{
			mlx_put_pixel(mlx->img, (mlx->player.x + x) * MINIMAP_SCALE, \
			(mlx->player.y + y) * MINIMAP_SCALE, 0x0000ffff);
			x++;
		}
		y++;
	}
}

t_pos	find_player(char **map)
{
	t_pos	player;
	int		x;
	int		y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || \
				map[y][x] == 'E' || map[y][x] == 'W')
			{
				player.x = x * TILE_SIZE + (TILE_SIZE / 2);
				player.y = y * TILE_SIZE + (TILE_SIZE / 2);
				player.dir = map[y][x];
			}
			x++;
		}
		y++;
	}
	return (player);
}
