/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:56:43 by haarab            #+#    #+#             */
/*   Updated: 2023/11/06 18:46:17 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void write_error(){
	write (1, "ERROR MAPS", 10);
	exit (1);
}


int ft_get(char *str)
{
	int	fd;
	int i;
	char *s;
	
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		exit (1);
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		i++;
		free (s);
	}
	close (fd);
	return (i);
}

char **ft_map(t_vars *vars, char *av)
{
	int	fd;
	int	i;
	
	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit(1);
	vars->move = malloc((ft_get(av)) * sizeof(char *) + 1);
	if (!vars->move)
		return (NULL);
	while (1)
	{
		vars->move[i] = get_next_line(fd);
		if (vars->move[i] == NULL && i == 0)
			write_error();
		if (vars->move[i] == NULL)
			break ;
		i++;
	}
	vars->move[i] = 0;
	close (fd);
	return (vars->move);
}

int check_format_av(char *str)
{
	if (str[ft_strlen(str) - 1] == 'b' && str[ft_strlen(str) - 2] == 'u' 
		&& str[ft_strlen(str) - 3] == 'c' && str[ft_strlen(str) - 4] == '.')
	{
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	char	**maps;
	
	if (ac != 2)
		return (0);
	if (check_format_av(av[1]) == 0)
		write_error();
	maps = ft_map(&vars, av[1]);
	// check_map_is_correct(maps);
	check_type_of_map(&vars, maps);
	// printf ("hamza\n");
}
