/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:53:57 by haarab            #+#    #+#             */
/*   Updated: 2023/11/06 19:59:43 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void check_identifier(char **str, int len)
{
	int i;
	char **range;
	char *ptr;

	if (count_strings(str[len], ',') != 3)
	{
		write_error();
	}
	i = 0;
	ptr = ft_strchr(str[len], ' ') + 1;
	if (check_is_digit(ptr) == 0)
		write_error();
	range = ft_split(ptr, ',');
	while (i < 3)
	{
		if (ft_atoi(range[i]) > 255 || ft_atoi(range[i]) < 0)
			write_error();
		free(range[i]);
		i++;
	}
	free(range);
}

void check_type(__attribute__((unused)) t_vars *vars, char *str)
{
	if (count_strings(str, ' ') != 2)
		write_error();
}

// void chech_line(char *str)
// {
// 	int i = 0; 
// 	char *ptr;


// 	ptr = ft_strchr(str, ' ') + 1;
// 	while (ptr[i])
// 	{
// 		if ((ptr[i] >= '0' && ptr[i] <= '9') || ptr[i] == ',')
// 			printf ("%c", ptr[i]);
// 		else
// 		{
// 			write_error();
// 		}
// 		printf ("\n");
// 		i++;
// 	}
// }

void check_type_of_map(t_vars *vars, char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp("NO", str[i] , 3) == 0)
			check_type(vars, str[i]);
		if (ft_strncmp("SO", str[i] , 3) == 0)
			check_type(vars, str[i]);
		if (ft_strncmp("WE", str[i] , 3) == 0)
			check_type(vars, str[i]);
		if (ft_strncmp("EA", str[i] , 3) == 0)
			check_type(vars, str[i]);
		if (ft_strncmp("F", str[i], 1) == 0)
		{
			check_type(vars, str[i]);
			// chech_line(str[i]);
			check_identifier(str, i);
		}
		if (ft_strncmp("C", str[i] , 1) == 0)
		{
			check_type(vars, str[i]);
			// chech_line(str[i]);
			check_identifier(str, i);
		}
		i++;
	}

}
