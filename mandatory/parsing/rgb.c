/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:21:11 by haarab            #+#    #+#             */
/*   Updated: 2024/01/25 14:09:59 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_find(char *str, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

void	check_rgbisgood(char **ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		if (ptr[i] == NULL)
			error_color();
		while (ptr[i][j])
		{
			if (ft_isdigit(ptr[i][j]) == 0 && ptr[i][j] != '\n')
			{
				printf ("Map File Error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	c_rgb(t_mlx *mlx)
{
	char	**ptr;
	int		i;

	if (count_find(mlx->vars.path_c, ',') != 2)
		error_color();
	ptr = ft_split (mlx->vars.path_c, ',');
	check_rgbisgood(ptr);
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(ptr[i]) > 255 || ft_atoi(ptr[i]) < 0)
		{
			printf ("Map File Error\n");
			exit (1);
		}
		i++;
	}
	mlx->vars.cr = ft_atoi(ptr[0]);
	mlx->vars.cg = ft_atoi(ptr[1]);
	mlx->vars.cb = ft_atoi(ptr[2]);
	free_rgb(ptr);
}

void	f_rgb(t_mlx *mlx)
{
	char	**ptr;
	int		i;

	if (count_find(mlx->vars.path_f, ',') != 2)
		error_color();
	ptr = ft_split (mlx->vars.path_f, ',');
	check_rgbisgood(ptr);
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(ptr[i]) > 255 || ft_atoi(ptr[i]) < 0)
		{
			printf ("Map File Error\n");
			exit (1);
		}
		i++;
	}
	mlx->vars.fr = ft_atoi(ptr[0]);
	mlx->vars.fg = ft_atoi(ptr[1]);
	mlx->vars.fb = ft_atoi(ptr[2]);
	free_rgb(ptr);
}

void	free_allocate(t_mlx *mlx)
{
	free_map(mlx);
	free_path(mlx);
	free(mlx->rays);
}
