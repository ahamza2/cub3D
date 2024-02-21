/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:18:50 by haarab            #+#    #+#             */
/*   Updated: 2024/01/25 13:39:00 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	alocate_path(t_mlx *mlx, char **ptr)
{
	if (ft_strcmp(ptr[0], "NO") == 0 && ft_strlen(ptr[0]) == 2)
		mlx->vars.path_no = ft_strdup(ptr[1]);
	else if (ft_strcmp(ptr[0], "SO") == 0 && ft_strlen(ptr[0]) == 2)
		mlx->vars.path_so = ft_strdup(ptr[1]);
	else if (ft_strcmp(ptr[0], "WE") == 0 && ft_strlen(ptr[0]) == 2)
		mlx->vars.path_we = ft_strdup(ptr[1]);
	else if (ft_strcmp(ptr[0], "EA") == 0 && ft_strlen(ptr[0]) == 2)
		mlx->vars.path_ea = ft_strdup(ptr[1]);
	else if (ft_strcmp(ptr[0], "F") == 0 && ft_strlen(ptr[0]) == 1)
		mlx->vars.path_f = ft_strdup(ptr[1]);
	else if (ft_strcmp(ptr[0], "C") == 0 && ft_strlen(ptr[0]) == 1)
		mlx->vars.path_c = ft_strdup(ptr[1]);
	else if (check_is_only_space(ptr[0]))
	{
		write(2, "Error\n", 7);
		exit(1);
	}
}

void	check_path_is_correct(t_mlx *mlx, char **str)
{
	int		i;
	int		j;
	char	**ptr;

	i = 0;
	while (i < mlx->vars.last)
	{
		ptr = NULL;
		ptr = ft_split(str[i], ' ');
		alocate_path(mlx, ptr);
		j = 0;
		while (ptr[j])
		{
			free(ptr[j]);
			j++;
		}
		free(ptr);
		i++;
	}
}

void	check_derection(char **str, int first, int i, int derection)
{
	if (i == 0)
		error_maps();
	if (first - 1 >= 0 && ft_strlen(str[first - 1]) < (size_t)i)
		error_maps();
	if (first - 1 >= 0 && str[first - 1][i] != '1' && str[first
		- 1][i] != derection && str[first - 1][i] != '0')
		error_maps();
	if (str[first][i + 1] && str[first][i + 1] != '1' && str[first][i
		+ 1] != derection && str[first][i + 1] != '0')
		error_maps();
	if (i - 1 >= 0 && str[first][i - 1] != '1' && str[first][i - 1] != derection
		&& str[first][i - 1] != '0')
		error_maps();
	if (str[first + 1] && str[first + 1][i] != '1' && str[first
		+ 1][i] != derection && str[first + 1][i] != '0')
		error_maps();
	else if (!str[first + 1])
		error_maps();
}

void	check_path(char **str, t_mlx *mlx, int first)
{
	int		i;
	char	derection;

	derection = derection_player(str, mlx, first);
	while (first < mlx->vars.lines_map)
	{
		i = 0;
		while (str[first][i] != '\n' && str[first][i])
		{
			if (str[first][i] != '0' && str[first][i] != derection
				&& str[first][i] != '1' && str[first][i] != ' '
				&& str[first][i] != '\0')
				error_maps();
			if (str[first][i] == '0' || str[first][i] == derection)
			{
				check_derection(str, first, i, derection);
			}
			i++;
		}
		first++;
	}
}

void	check_map_is_correct(char **str, t_mlx *mlx, int first)
{
	check_persone(str, mlx, first);
	check_path(str, mlx, first);
}
