/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:37:03 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/25 11:41:26 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	load_textures(t_mlx *mlx)
{
	mlx->north = mlx_load_png(mlx->vars.path_no);
	mlx->south = mlx_load_png(mlx->vars.path_so);
	mlx->east = mlx_load_png(mlx->vars.path_ea);
	mlx->west = mlx_load_png(mlx->vars.path_we);
	if (!mlx->west || !mlx->east || !mlx->south || !mlx->north)
	{
		printf("Textures path error\n");
		free_allocate(mlx);
		exit(1);
	}
}
