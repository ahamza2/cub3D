/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:12:46 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/25 11:41:26 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	player_init(t_mlx *mlx, t_player *player)
{
	t_pos	location;

	location = find_player(mlx->vars.maps);
	player->x = location.x;
	player->y = location.y;
	player->width = 8;
	player->height = 8;
	player->turndirection = 0;
	player->walkdirection = 0;
	setplayerangle(mlx);
	player->speed = 10;
	player->movespeed = 5;
	player->rotationspeed = 8 * (PI / 180);
}

void	setplayerangle(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->vars.maps[i])
	{
		j = 0;
		while (mlx->vars.maps[i][j])
		{
			if (mlx->vars.maps[i][j] == 'N')
				mlx->player.rotationangle = (3 * PI) / 2;
			else if (mlx->vars.maps[i][j] == 'S')
				mlx->player.rotationangle = PI / 2;
			else if (mlx->vars.maps[i][j] == 'E')
				mlx->player.rotationangle = 0;
			else if (mlx->vars.maps[i][j] == 'W')
				mlx->player.rotationangle = PI;
			j++;
		}
		i++;
	}
}

void	ft_colors(t_mlx *mlx)
{
	mlx->ceiling_color = (mlx->vars.cr << 24 
			| mlx->vars.cg << 16 | mlx->vars.cb << 8 | 255);
	mlx->floor_color = mlx->vars.fr << 24 
		| mlx->vars.fg << 16 | mlx->vars.fb << 8 | 255;
}
