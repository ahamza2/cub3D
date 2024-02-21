/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:14:36 by haarab            #+#    #+#             */
/*   Updated: 2024/01/25 10:50:20 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	persone_error(int j)
{
	if (j < 1)
	{
		printf ("Player not found\n");
		exit (1);
	}
	if (j > 1)
	{
		printf ("Multiplayer mode not available\n");
		exit (1);
	}
}

void	check_persone(char **str, t_mlx *mlx, int first)
{
	int	i;
	int	j;

	j = 0;
	while (first < mlx->vars.lines_map)
	{
		i = 0;
		while (str[first][i] != '\n' && str[first][i])
		{
			if (str[first][i] == 'N' || str[first][i] == 'S'
				|| str[first][i] == 'E' || str[first][i] == 'W')
				j++;
			i++;
		}
		first++;
	}
	persone_error(j);
}

char	derection_player(char **str, t_mlx *mlx, int first)
{
	int		i;
	char	derection;

	while (first < mlx->vars.lines_map)
	{
		i = 0;
		while (str[first][i] != '\n' && str[first][i])
		{
			if (str[first][i] == 'N')
				derection = str[first][i];
			else if (str[first][i] == 'W')
				derection = str[first][i];
			else if (str[first][i] == 'S')
				derection = str[first][i];
			else if (str[first][i] == 'E')
				derection = str[first][i];
			i++;
		}
		first++;
	}
	return (derection);
}
