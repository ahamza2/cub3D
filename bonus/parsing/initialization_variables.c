/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_variables.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:54:22 by haarab            #+#    #+#             */
/*   Updated: 2024/01/25 11:41:26 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	initialization_variable(t_mlx *mlx)
{
	mlx->vars.maps = NULL;
	mlx->vars.no = NULL;
	mlx->vars.so = NULL;
	mlx->vars.we = NULL;
	mlx->vars.ea = NULL;
	mlx->vars.f = NULL;
	mlx->vars.c = NULL;
	mlx->vars.path_no = NULL;
	mlx->vars.path_so = NULL;
	mlx->vars.path_we = NULL;
	mlx->vars.path_ea = NULL;
	mlx->vars.path_f = NULL;
	mlx->vars.path_c = NULL;
}
