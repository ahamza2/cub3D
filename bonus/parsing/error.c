/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:47:59 by haarab            #+#    #+#             */
/*   Updated: 2024/01/25 11:41:26 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	error_color(void)
{
	printf ("Map File Error\n");
	exit(1);
}

void	write_error(void)
{
	printf ("Map File Error\n");
	exit (1);
}

void	error_maps(void)
{
	printf ("Map File Error\n");
	exit (1);
}

void	error_path(void)
{
	printf ("Map File Error\n");
	exit (1);
}

void	error_size(t_mlx *mlx)
{
	if (mlx->vars.map_height > 30 || mlx->vars.map_width > 100)
	{
		printf ("Map File Error\n");
		exit (1);
	}
}
