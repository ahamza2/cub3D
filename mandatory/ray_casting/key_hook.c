/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:14:57 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/25 14:08:11 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	keyhook_p1(t_mlx *mlx)
{
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_W))
	{
		mlx->player.new_x = mlx->player.x + cos(mlx->player.rotationangle)
			* mlx->player.movespeed;
		mlx->player.new_y = mlx->player.y + sin(mlx->player.rotationangle)
			* mlx->player.movespeed;
		if (!is_wall(mlx->player.new_y, mlx->player.new_x, mlx->vars.maps, mlx))
		{
			mlx->player.x = mlx->player.new_x;
			mlx->player.y = mlx->player.new_y;
		}
	}
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_S))
	{
		mlx->player.new_x = mlx->player.x - cos(mlx->player.rotationangle)
			* mlx->player.movespeed;
		mlx->player.new_y = mlx->player.y - sin(mlx->player.rotationangle)
			* mlx->player.movespeed;
		if (!is_wall(mlx->player.new_y, mlx->player.new_x, mlx->vars.maps, mlx))
		{
			mlx->player.x = mlx->player.new_x;
			mlx->player.y = mlx->player.new_y;
		}
	}
}

void	keyhook_p2(t_mlx *mlx)
{
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_D))
	{
		mlx->player.new_x = mlx->player.x - mlx->player.movespeed
			* cos(mlx->player.rotationangle - (PI / 2));
		mlx->player.new_y = mlx->player.y - mlx->player.movespeed
			* sin(mlx->player.rotationangle - (PI / 2));
		if (!is_wall(mlx->player.new_y, mlx->player.new_x, mlx->vars.maps, mlx))
		{
			mlx->player.x = mlx->player.new_x;
			mlx->player.y = mlx->player.new_y;
		}
	}
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_A))
	{
		mlx->player.new_x = mlx->player.x + mlx->player.movespeed
			* cos(mlx->player.rotationangle - (PI / 2));
		mlx->player.new_y = mlx->player.y + mlx->player.movespeed
			* sin(mlx->player.rotationangle - (PI / 2));
		if (!is_wall(mlx->player.new_y, mlx->player.new_x, mlx->vars.maps, mlx))
		{
			mlx->player.x = mlx->player.new_x;
			mlx->player.y = mlx->player.new_y;
		}
	}
}

void	keyhook_p3(t_mlx *mlx)
{
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT))
		mlx->player.turndirection += 0.3;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT))
		mlx->player.turndirection -= 0.3;
	mlx->player.rotationangle += mlx->player.turndirection
		* mlx->player.rotationspeed;
	reset_angle(mlx);
	castallrays(mlx);
	generate3dprojection(mlx);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT))
		mlx->player.turndirection = 0;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT))
		mlx->player.turndirection = 0;
}

void	keyhook(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_ESCAPE))
	{
		free_allocate(mlx);
		printf("See You Soon!!\n");
		exit(0);
	}
	keyhook_p1(mlx);
	keyhook_p2(mlx);
	keyhook_p3(mlx);
}
