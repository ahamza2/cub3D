/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 03:57:46 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/25 03:08:11 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	vertical_hit(t_mlx *mlx, int i, int j)
{
	if (mlx->rays[i].ray_angle >= (PI / 2) \
		&& mlx->rays[i].ray_angle <= 3 * (PI / 2))
	{
		mlx->offset = mlx->rays[i].wallhity / TILE_SIZE;
		mlx->offset -= (int)mlx->offset;
		mlx->offsetx = (1 - mlx->offset) * mlx->west->width;
		mlx->textureoffsety = (1.0 - \
		((double)mlx->distancefromtop / mlx->projectedwallheight)) \
		* mlx->west->height;
		mlx->textureoffsety = mlx->west->height - mlx->textureoffsety;
		mlx->color = gen_color(mlx->west, mlx->offsetx, mlx->textureoffsety);
		mlx_put_pixel(mlx->img, i, j, mlx->color); 
	}
	else
	{
		mlx->offset = mlx->rays[i].wallhity / TILE_SIZE;
		mlx->offset -= (int)mlx->offset;
		mlx->offsetx = (mlx->offset) * mlx->east->width;
		mlx->textureoffsety = (1.0 - \
		((double)mlx->distancefromtop / mlx->projectedwallheight)) \
		* mlx->east->height;
		mlx->textureoffsety = mlx->east->height - mlx->textureoffsety;
		mlx->color = gen_color(mlx->east, mlx->offsetx, mlx->textureoffsety);
		mlx_put_pixel(mlx->img, i, j, mlx->color);
	}
}

void	horizontal_hit(t_mlx *mlx, int i, int j)
{
	if (mlx->rays[i].ray_angle >= 0 && mlx->rays[i].ray_angle <= PI)
	{
		mlx->offset = mlx->rays[i].wallhitx / TILE_SIZE;
		mlx->offset -= (int)mlx->offset;
		mlx->offsetx = (1 - mlx->offset) * mlx->north->width;
		mlx->textureoffsety = (1.0 - \
		((double)mlx->distancefromtop / mlx->projectedwallheight)) \
		* mlx->north->height;
		mlx->textureoffsety = mlx->north->height - mlx->textureoffsety;
		mlx->color = gen_color(mlx->north, mlx->offsetx, mlx->textureoffsety);
		mlx_put_pixel(mlx->img, i, j, mlx->color);
	}
	else
	{
		mlx->offset = mlx->rays[i].wallhitx / TILE_SIZE;
		mlx->offset -= (int)mlx->offset;
		mlx->offsetx = (mlx->offset) * mlx->south->width;
		mlx->textureoffsety = (1.0 - \
		((double)mlx->distancefromtop / mlx->projectedwallheight)) \
		* mlx->south->height;
		mlx->textureoffsety = mlx->south->height - mlx->textureoffsety;
		mlx->color = gen_color(mlx->south, mlx->offsetx, mlx->textureoffsety);
		mlx_put_pixel(mlx->img, i, j, mlx->color);
	}
}

void	wall_p0(t_mlx *mlx, int i)
{
	mlx->correcteddistance = mlx->rays[i].distance * \
	cos(mlx->rays[i].ray_angle - mlx->player.rotationangle);
	mlx->distanceprojplane = (WIDTH / 2) / tan(mlx->fov / 2);
	mlx->projectedwallheight = (TILE_SIZE / mlx->correcteddistance) \
	* mlx->distanceprojplane;
	mlx->wallstripheight = (int) mlx->projectedwallheight;
	mlx->walltoppixel = (HEIGHT / 2) - (mlx->wallstripheight / 2);
	if (mlx->walltoppixel < 0)
		mlx->walltoppixel = 0;
	mlx->wallbottompixel = mlx->walltoppixel + mlx->projectedwallheight;
	if (mlx->wallbottompixel > HEIGHT)
		mlx->wallbottompixel = HEIGHT;
}

void	wall_p1(t_mlx *mlx, int i)
{
	int	j;

	j = 0;
	while (j < mlx->walltoppixel)
	{
		mlx_put_pixel(mlx->img, i, j, mlx->ceiling_color);
		j++;
	}
	j = mlx->walltoppixel;
	while (j < mlx->wallbottompixel)
	{
		mlx->distancefromtop = j + (mlx->wallstripheight / 2) - (HEIGHT / 2);
		if (mlx->rays[i].washitvertical)
			vertical_hit(mlx, i, j);
		else
			horizontal_hit(mlx, i, j);
		j++;
	}
	while (j < HEIGHT)
	{
		mlx_put_pixel(mlx->img, i, j, mlx->floor_color);
		j++;
	}
}
