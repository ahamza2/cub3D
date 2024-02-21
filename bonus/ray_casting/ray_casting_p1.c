/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_p1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:09:59 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/25 11:41:26 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	castallrays(t_mlx *mlx)
{
	double	ray_angle;
	double	nbr_rays;
	double	fov;
	int		i;

	nbr_rays = (double)mlx->num_rays;
	fov = (double)mlx->fov_angle * (180 / PI);
	ray_angle = mlx->player.rotationangle - (mlx->fov_angle / 2);
	i = 0;
	while (i < mlx->num_rays)
	{
		cast_ray(mlx, ray_angle, i);
		ray_angle += ((fov / nbr_rays) * (PI / 180));
		i++;
	}
}

double	normalize_angle(double angle)
{
	angle = remainder(angle, 2 * PI);
	if (angle < 0)
		angle = (2 * PI) + angle;
	return (angle);
}

double	distancebetweenpoints(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	draw_ray(t_mlx *mlx, int xb, int yb)
{
	int		dx;
	int		dy;
	int		steps;
	double	x;
	double	y;

	dx = xb - mlx->player.x;
	dy = yb - mlx->player.y;
	x = mlx->player.x;
	y = mlx->player.y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	mlx->xin = dx / (double)steps;
	mlx->yin = dy / (double)steps;
	mlx->k = 0;
	while (mlx->k < steps)
	{
		mlx_put_pixel(mlx->img, round(x) * MINIMAP_SCALE, round(y)
			* MINIMAP_SCALE, 0xF89D4Eff);
		x = x + mlx->xin;
		y = y + mlx->yin;
		mlx->k++;
	}
}

void	render_rays(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->num_rays)
	{
		draw_ray(mlx, mlx->rays[i].wallhitx, mlx->rays[i].wallhity);
		i++;
	}
}
