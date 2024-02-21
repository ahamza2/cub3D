/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alocation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:09:45 by haarab            #+#    #+#             */
/*   Updated: 2024/01/25 11:41:26 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	alocate_typergb(t_mlx *mlx, char *ptr)
{
	if (ft_strcmp (ptr, "F") == 0)
	{
		if (mlx->vars.f != NULL)
			double_type_map(ptr);
		mlx->vars.f = ft_strdup (ptr);
	}
	else if (ft_strcmp (ptr, "C") == 0)
	{
		if (mlx->vars.c != NULL)
			double_type_map(ptr);
		mlx->vars.c = ft_strdup (ptr);
	}
}

void	alocate_typeimage(t_mlx *mlx, char *ptr)
{
	if (ft_strcmp (ptr, "NO") == 0)
	{
		if (mlx->vars.no != NULL)
			double_type_map(ptr);
		mlx->vars.no = ft_strdup (ptr);
	}
	else if (ft_strcmp (ptr, "SO") == 0)
	{
		if (mlx->vars.so != NULL)
			double_type_map(ptr);
		mlx->vars.so = ft_strdup (ptr);
	}
	else if (ft_strcmp (ptr, "WE") == 0)
	{
		if (mlx->vars.we != NULL)
			double_type_map(ptr);
		mlx->vars.we = ft_strdup (ptr);
	}
	else if (ft_strcmp (ptr, "EA") == 0)
	{
		if (mlx->vars.ea != NULL)
			double_type_map(ptr);
		mlx->vars.ea = ft_strdup (ptr);
	}
}

void	alocate_space(t_mlx *mlx)
{
	int	j;
	int	c;

	j = 0;
	while (j < mlx->vars.map_height)
	{
		mlx->vars.maps[j] = malloc(sizeof(char) * (mlx->vars.map_width + 1));
		c = 0;
		while (c < mlx->vars.map_width)
		{
			mlx->vars.maps[j][c] = ' ';
			c++;
		}
		mlx->vars.maps[j][c] = '\0';
		j++;
	}
	mlx->vars.maps[j] = NULL;
}

void	alocate_savemap(t_mlx *mlx, char **str, int b)
{
	int	j;
	int	c;
	int	k;

	j = 0;
	while (j < mlx->vars.map_height)
	{
		c = 0;
		k = mlx->vars.start;
		while (k < mlx->vars.maxline && c < mlx->vars.map_width)
		{
			if (k < ft_strlene(str[b]) && str[b][c] != '\0')
			{
				mlx->vars.maps[j][c] = str[b][k];
			}
			else
				mlx->vars.maps[j][c] = ' ';
			c++;
			k++;
		}
		mlx->vars.maps[j][c] = '\0';
		b++;
		j++;
	}
}

void	alocate_typepath(t_mlx *mlx, char *ptr)
{
	alocate_typergb(mlx, ptr);
	alocate_typeimage(mlx, ptr);
}
