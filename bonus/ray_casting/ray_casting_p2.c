/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_p2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:09:59 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/25 11:41:26 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	cast_ray_p0(t_mlx *mlx, double ray_angle)
{
	mlx->israyfacingdown = ray_angle > 0 && ray_angle < PI;
	mlx->israyfacingup = !(mlx->israyfacingdown);
	mlx->israyfacingright = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
	mlx->israyfacingleft = !(mlx->israyfacingright);
	mlx->foundhorzwallhit = FALSE;
	mlx->horzwallhitx = 0;
	mlx->horzwallhity = 0;
	mlx->horzwallcontent = 0;
	mlx->yintercept = floor(mlx->player.y / TILE_SIZE) * TILE_SIZE;
	if (mlx->israyfacingdown)
		mlx->yintercept += TILE_SIZE;
	else
		mlx->yintercept += 0;
	mlx->xintercept = mlx->player.x + (mlx->yintercept - mlx->player.y)
		/ tan(ray_angle);
	mlx->ystep = TILE_SIZE;
	if (mlx->israyfacingup)
		mlx->ystep *= -1;
	mlx->xstep = TILE_SIZE / tan(ray_angle);
	if (mlx->israyfacingleft && mlx->xstep > 0)
		mlx->xstep *= -1;
	if (mlx->israyfacingright && mlx->xstep < 0)
		mlx->xstep *= -1;
	mlx->nexthorztouchx = mlx->xintercept;
	mlx->nexthorztouchy = mlx->yintercept;
}

void	cast_ray_p1(t_mlx *mlx)
{
	while (mlx->nexthorztouchx >= 0 && mlx->nexthorztouchx <= mlx->w_wid
		&& mlx->nexthorztouchy >= 0 && mlx->nexthorztouchy <= mlx->w_hei)
	{
		mlx->xtocheck = mlx->nexthorztouchx;
		if (mlx->israyfacingup)
			mlx->ytocheck = mlx->nexthorztouchy - 1;
		else
			mlx->ytocheck = mlx->nexthorztouchy;
		if (is_wall(mlx->ytocheck, mlx->xtocheck, mlx->vars.maps, mlx))
		{
			mlx->horzwallhitx = mlx->nexthorztouchx;
			mlx->horzwallhity = mlx->nexthorztouchy;
			mlx->horzwallcontent = mlx->vars.maps[(int)floor(mlx->ytocheck
					/ TILE_SIZE)][(int)floor(mlx->xtocheck / TILE_SIZE)];
			mlx->foundhorzwallhit = TRUE;
			break ;
		}
		else
		{
			mlx->nexthorztouchx += mlx->xstep;
			mlx->nexthorztouchy += mlx->ystep;
		}
	}
}

void	cast_ray_p2(t_mlx *mlx, double ray_angle)
{
	mlx->foundvertwallhit = FALSE;
	mlx->vertwallhitx = 0;
	mlx->vertwallhity = 0;
	mlx->vertwallcontent = 0;
	mlx->xintercept = floor(mlx->player.x / TILE_SIZE) * TILE_SIZE;
	if (mlx->israyfacingright)
		mlx->xintercept += TILE_SIZE;
	mlx->yintercept = mlx->player.y + (mlx->xintercept - mlx->player.x)
		* tan(ray_angle);
	mlx->xstep = TILE_SIZE;
	if (mlx->israyfacingleft)
		mlx->xstep *= -1;
	mlx->ystep = TILE_SIZE * tan(ray_angle);
	if (mlx->israyfacingup && mlx->ystep > 0)
		mlx->ystep *= -1;
	if (mlx->israyfacingdown && mlx->ystep < 0)
		mlx->ystep *= -1;
	mlx->nextverttouchx = mlx->xintercept;
	mlx->nextverttouchy = mlx->yintercept;
}

void	cast_ray_p3(t_mlx *mlx)
{
	while (mlx->nextverttouchx >= 0 && mlx->nextverttouchx <= mlx->w_wid
		&& mlx->nextverttouchy >= 0 && mlx->nextverttouchy <= mlx->w_hei)
	{
		mlx->xtocheck = mlx->nextverttouchx;
		if (mlx->israyfacingleft)
			mlx->xtocheck = mlx->nextverttouchx - 1;
		mlx->ytocheck = mlx->nextverttouchy;
		if (is_wall(mlx->ytocheck, mlx->xtocheck, mlx->vars.maps, mlx))
		{
			mlx->vertwallhitx = mlx->nextverttouchx;
			mlx->vertwallhity = mlx->nextverttouchy;
			mlx->vertwallcontent = mlx->vars.maps[(int)floor(mlx->ytocheck
					/ TILE_SIZE)][(int)floor(mlx->xtocheck / TILE_SIZE)];
			mlx->foundvertwallhit = TRUE;
			break ;
		}
		else
		{
			mlx->nextverttouchx += mlx->xstep;
			mlx->nextverttouchy += mlx->ystep;
		}
	}
}

void	cast_ray(t_mlx *mlx, double ray_angle, int i)
{
	ray_angle = normalize_angle(ray_angle);
	cast_ray_p0(mlx, ray_angle);
	cast_ray_p1(mlx);
	cast_ray_p2(mlx, ray_angle);
	cast_ray_p3(mlx);
	cast_ray_p4(mlx);
	cast_ray_p5(mlx, ray_angle, i);
}
