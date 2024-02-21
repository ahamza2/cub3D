/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:49:18 by haarab            #+#    #+#             */
/*   Updated: 2024/01/25 10:54:38 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_rgb(char **ptr)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	double_type_map(char *str)
{
	free(str);
	printf ("Map File Error\n");
	exit(1);
}

void	free_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->vars.maps[i])
	{
		free(mlx->vars.maps[i]);
		i++;
	}
	free(mlx->vars.maps);
}

void	free_path_first(t_mlx *mlx)
{
	free(mlx->vars.no);
	free(mlx->vars.so);
	free(mlx->vars.we);
	free(mlx->vars.ea);
	free(mlx->vars.f);
	free(mlx->vars.c);
}

void	free_path(t_mlx *mlx)
{
	free(mlx->vars.path_no);
	free(mlx->vars.path_so);
	free(mlx->vars.path_we);
	free(mlx->vars.path_ea);
	free(mlx->vars.path_f);
	free(mlx->vars.path_c);
}
