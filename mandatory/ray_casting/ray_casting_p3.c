/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_p3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:09:59 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/25 10:40:03 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cast_ray_p4(t_mlx *mlx)
{
	if (mlx->foundhorzwallhit)
		mlx->horzhitdistance = distancebetweenpoints(mlx->player.x,
				mlx->player.y, mlx->horzwallhitx, mlx->horzwallhity);
	else
		mlx->horzhitdistance = INT_MAX;
	if (mlx->foundvertwallhit)
		mlx->verthitdistance = distancebetweenpoints(mlx->player.x,
				mlx->player.y, mlx->vertwallhitx, mlx->vertwallhity);
	else
		mlx->verthitdistance = INT_MAX;
}

void	cast_ray_p5(t_mlx *mlx, double ray_angle, int i)
{
	if (mlx->verthitdistance < mlx->horzhitdistance)
	{
		mlx->rays[i].distance = mlx->verthitdistance;
		mlx->rays[i].wallhitx = mlx->vertwallhitx;
		mlx->rays[i].wallhity = mlx->vertwallhity;
		mlx->rays[i].wallhitcontent = mlx->vertwallcontent;
		mlx->rays[i].washitvertical = TRUE;
	}
	else
	{
		mlx->rays[i].distance = mlx->horzhitdistance;
		mlx->rays[i].wallhitx = mlx->horzwallhitx;
		mlx->rays[i].wallhity = mlx->horzwallhity;
		mlx->rays[i].wallhitcontent = mlx->horzwallcontent;
		mlx->rays[i].washitvertical = FALSE;
	}
	mlx->rays[i].ray_angle = ray_angle;
	mlx->rays[i].israyfacingdown = mlx->israyfacingdown;
	mlx->rays[i].israyfacingup = mlx->israyfacingup;
	mlx->rays[i].israyfacingleft = mlx->israyfacingleft;
	mlx->rays[i].israyfacingright = mlx->israyfacingright;
}

bool	is_wall(double y, double x, char **map, t_mlx *mlx)
{
	int	xx;
	int	yy;

	if (x < 0 || x > mlx->w_wid || y < 0 || y > mlx->w_hei)
		return (TRUE);
	yy = floor(y / TILE_SIZE);
	xx = floor(x / TILE_SIZE);
	if (yy < 0 || yy >= mlx->vars.map_height || xx < 0
		|| xx >= mlx->vars.map_width)
		return (TRUE);
	if (map[yy][xx] == '\0' || map[yy][xx] == '1' || map[yy][xx] == ' ')
		return (TRUE);
	return (FALSE);
}
