/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:02:47 by haarab            #+#    #+#             */
/*   Updated: 2024/01/25 11:41:26 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	error_type(char *ptr)
{
	if ((ft_strcmp(ptr, "NO") != 0 && ft_strcmp(ptr, "SO") != 0
			&& ft_strcmp(ptr, "WE") != 0 && ft_strcmp(ptr, "EA") != 0
			&& ft_strcmp(ptr, "F") != 0 && ft_strcmp(ptr, "C") != 0
			&& ft_strcmp(ptr, "\n") != 0))
	{
		printf ("Map File Error\n");
		exit (1);
	}
}

void	check_tab_in_maps(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == '\t')
			{
				printf ("Map File Error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	check_type_file_is_correct(t_mlx *mlx)
{
	if (mlx->vars.no == NULL || mlx->vars.so == NULL || mlx->vars.we == NULL
		|| mlx->vars.ea == NULL || mlx->vars.f == NULL || mlx->vars.c == NULL)
	{
		free_path_first(mlx);
		error_path();
	}
}

int	check_format_av(char *str)
{
	if (str[ft_strlen(str) - 1] == 'b' && str[ft_strlen(str) - 2] == 'u' 
		&& str[ft_strlen(str) - 3] == 'c' && str[ft_strlen(str) - 4] == '.')
	{
		return (1);
	}
	return (0);
}
