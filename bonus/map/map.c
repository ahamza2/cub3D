/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 12:48:54 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/25 11:41:26 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	put_rect(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_put_pixel(mlx->img, (mlx->map.tilex + x) * MINIMAP_SCALE,
				(mlx->map.tiley + y) * MINIMAP_SCALE, mlx->map.tilecolor);
			x++;
		}
		y++;
	}
}

void	put_map_p0(t_mlx *mlx, int y)
{
	int	x;

	x = 0;
	while (mlx->vars.maps[y][x] != '\0')
	{
		mlx->map.tilex = x * TILE_SIZE;
		mlx->map.tiley = y * TILE_SIZE;
		if (mlx->vars.maps[y][x] == '1')
			mlx->map.tilecolor = 0x6C4363ff;
		else if (mlx->vars.maps[y][x] == '0' || mlx->vars.maps[y][x] == 'N'
			|| mlx->vars.maps[y][x] == 'S' || mlx->vars.maps[y][x] == 'E'
			|| mlx->vars.maps[y][x] == 'W')
			mlx->map.tilecolor = 0x6FAFBBff;
		else
		{
			x++;
			continue ;
		}
		put_rect(mlx);
		x++;
	}
}

void	put_map(t_mlx *mlx)
{
	int	y;

	y = 0;
	while (mlx->vars.maps[y] != NULL)
	{
		put_map_p0(mlx, y);
		y++;
	}
}
