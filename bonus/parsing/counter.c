/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 01:04:08 by haarab            #+#    #+#             */
/*   Updated: 2024/01/25 11:41:26 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	line_of_map(t_mlx *mlx, char **str)
{
	mlx->vars.lines_map = 0;
	while (str[mlx->vars.lines_map])
		mlx->vars.lines_map++;
}

int	ft_strlene(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

int	ft_maxline(char **str, int i, int k)
{
	int	len;

	len = ft_strlene(str[i]);
	k -= 1;
	while (i < k)
	{
		if (len < ft_strlene(str[i]))
		{
			len = ft_strlene(str[i]);
		}
		i++;
	}
	return (len);
}

int	ft_startline(char **str, int i, int k)
{
	int	len;
	int	j;

	len = ft_strlene(str[i]);
	while (i < k)
	{
		j = ft_strlene(str[i]);
		while (j >= 0)
		{
			if (str[i][j] == '1')
			{
				if (j < len)
				{
					len = j;
				}
			}
			j--;
		}
		i++;
	}
	return (len);
}

int	count_str(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != '\n')
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}
