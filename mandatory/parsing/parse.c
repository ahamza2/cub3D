/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:56:43 by haarab            #+#    #+#             */
/*   Updated: 2024/01/25 12:58:15 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_first_stringmap(char **str, int first, t_mlx *mlx)
{
	int	i;

	while (first < mlx->vars.lines_map)
	{
		i = 0;
		while (str[first][i] != '\n')
		{
			if (str[first][i] == '1')
			{
				return (first);
			}
			i++;
		}
		first++;
	}
	return (first);
}

int	check_last_stringmap(char **str, int first, t_mlx *mlx)
{
	int	i;
	int	last;

	last = mlx->vars.lines_map - 1;
	while (first < last)
	{
		i = 0;
		while (str[last][i] != '\n' && str[last][i] != '\0')
		{
			if (str[last][i] == '1')
			{
				return (last);
			}
			i++;
		}
		last--;
	}
	return (last);
}

int	ft_get(char *str)
{
	int		fd;
	int		i;
	char	*s;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		exit(1);
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		i++;
		free(s);
	}
	close(fd);
	return (i);
}

char	**ft_map(char *av)
{
	int		fd;
	char	**str;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit(1);
	str = malloc((ft_get(av) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (1)
	{
		str[i] = get_next_line(fd);
		if (str[i] == NULL && i == 0)
			write_error();
		if (str[i] == NULL)
			break ;
		i++;
	}
	str[i] = NULL;
	close(fd);
	return (str);
}

void	parsing(t_mlx *mlx, char **str)
{
	check_tab_in_maps(str);
	initialization_variable(mlx);
	check_type_of_map(mlx, str);
	save_map(mlx, str);
	check_type_file_is_correct(mlx);
	free_path_first(mlx);
	check_path_is_correct(mlx, str);
	free_2d(str);
	c_rgb(mlx);
	f_rgb(mlx);
}
