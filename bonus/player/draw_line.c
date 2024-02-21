/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:23:20 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/24 02:58:41 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_line(t_mlx *mlx, int len)
{
	int		k;
	t_dda	dda;

	dda.dx = cos(mlx->player.rotationangle) * len;
	dda.dy = sin(mlx->player.rotationangle) * len;
	dda.x = mlx->player.x + mlx->player.height / 2;
	dda.y = mlx->player.y + mlx->player.width / 2;
	if (abs(dda.dx) > abs(dda.dy))
		dda.steps = abs(dda.dx);
	else
		dda.steps = abs(dda.dy);
	dda.xin = dda.dx / (double) dda.steps;
	dda.yin = dda.dy / (double) dda.steps;
	k = 0;
	while (k < dda.steps) 
	{
		mlx_put_pixel(mlx->img, round(dda.x) * \
		MINIMAP_SCALE, round(dda.y) * MINIMAP_SCALE, 0xffffff);
		dda.x = dda.x + dda.xin;
		dda.y = dda.y + dda.yin;
		k++;
	}
}

void	reset_angle(t_mlx *mlx)
{
	if (mlx->player.rotationangle > 2 * PI)
		mlx->player.rotationangle -= 2 * PI;
	if (mlx->player.rotationangle < 0)
		mlx->player.rotationangle += 2 * PI;
}
