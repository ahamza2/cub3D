/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:53:57 by haarab            #+#    #+#             */
/*   Updated: 2024/01/25 11:41:26 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	save_map(t_mlx *mlx, char **str)
{
	int	k;
	int	first;
	int	i;

	k = 0;
	line_of_map(mlx, str);
	first = mlx->vars.last;
	check_map_is_correct(str, mlx, first);
	i = check_first_stringmap(str, first, mlx);
	k = check_last_stringmap(str, i, mlx) + 1;
	mlx->vars.map_width = ft_maxline(str, i, k);
	mlx->vars.map_height = k - i;
	mlx->vars.maps = malloc(sizeof(char *) * (mlx->vars.map_height + 1));
	mlx->vars.start = ft_startline(str, i, k);
	mlx->vars.maxline = mlx->vars.map_width;
	mlx->vars.map_width -= mlx->vars.start;
	alocate_space(mlx);
	alocate_savemap(mlx, str, i);
}

void	check_type_of_map(t_mlx *mlx, char **str)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	while (str[i])
	{
		ptr = ft_strtrim(str[i], " ");
		if (count_str(ptr, ' ') > 2)
			error_path();
		alocate_typepath(mlx, ptr);
		error_type(ptr);
		if (mlx->vars.no != NULL && mlx->vars.so != NULL && mlx->vars.we != NULL
			&& mlx->vars.ea != NULL && mlx->vars.f != NULL
			&& mlx->vars.c != NULL)
		{
			mlx->vars.last = i + 1;
			free (ptr);
			return ;
		}
		free (ptr);
		i++;
	}
	printf ("Map File Error\n");
	exit (1);
}
