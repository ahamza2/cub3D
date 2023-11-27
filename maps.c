/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:53:57 by haarab            #+#    #+#             */
/*   Updated: 2023/11/27 21:30:06 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void line_of_map(t_vars *vars, char **str)
{
	vars->lines_map = 0;
	while (str[vars->lines_map])
		vars->lines_map++;
	// return (vars->lines_map);
}

void check_persone(char **str , t_vars *vars, int first)
{
	int i;
	int j = 0;
	while (first < vars->lines_map)
	{
		i = 0;
		while (str[first][i] != '\n' && str[first][i])
		{
			if (str[first][i] == 'N')
			{
				printf ("%d == %d\n", first , i);
				j++;
			}
			i++;
		}
		first++;
	}
	if (j < 1)
	{
		printf ("N not found\n");
		exit (1);
	}
	if (j > 1)
	{
		printf ("More N\n");
		exit (1);
	}
}


void check_path(char **str ,t_vars *vars,int first)
{
	int i;

	while (first < vars->lines_map)
	{
		i = 0;
		// printf ("%s", str[first]);
		// printf ("hamza\n");
		while (str[first][i] != '\n' && str[first][i])
		{
			if (str[first][i] != '0' && str[first][i] != 'N' && str[first][i] != '1'
				&& str[first][i] != ' ' && str[first][i] != '\0')
			{
				printf ("problime in the map caracter\n");
				exit (1);
			}	
			if (str[first][i] == '0' || str[first][i] == 'N')
			{	
				if (i == 0) {
					printf ("NOT\n");
					exit (1);
				}
				// printf ("%d, %d, %c\n", first, i, str[first][i]);
				// printf ("%c", str[first][i]);
				if (first  - 1  >= 0 && ft_strlen(str[first - 1]) < (size_t)i)
				{
					printf ("NOT\n");
					exit (1);
				}
				if (first  - 1  >= 0 && str[first - 1][i] != '1' && str[first - 1][i] != 'N' && str[first - 1][i] != '0')
				{
					printf ("NOT\n");
					exit (1);
				}
				if (str[first][i + 1]  && str[first][i + 1] != '1' && str[first][i + 1] != 'N' && str[first][i + 1] != '0')
				{
					printf ("MAP \n");
					exit (1);
				}
				if (i - 1 >= 0  && str[first][i - 1] != '1' && str[first][i - 1] != 'N' && str[first][i - 1] != '0')
				{
					printf ("SI\n");
					exit (1);
				}
				if (str[first + 1] && str[first + 1][i] != '1' && str[first + 1][i] != 'N' && str[first + 1][i] != '0')
				{
					printf ("ERR\n");
					exit (1);
				}else if (!str[first + 1]) {
					printf ("NOT\n");
					exit (1);
				}
			}
			i++;
		}
		first++;
	}
}


void check_map_is_correct(char **str, t_vars *vars, int first)
{
	check_persone(str , vars, first);
	check_path(str , vars, first);
}

void save_map(t_vars *vars, char **str)
{
	int j = 0;
	line_of_map(vars, str);
	int first = vars->last;
	printf ("first ==== %d\n", first);
	check_map_is_correct(str, vars, first);
	while (first < vars->lines_map)
	{
		if (str[first][0] != '\n')
			j++;
		first++;
	}
	vars->maps = malloc((j) * sizeof(char *) + 1);
	first = vars->last;
	j = 0;
	while (first < vars->lines_map)
	{
		if (str[first][0] != '\n')
		{
			vars->maps[j] = ft_strdup(str[first]);
			j++;
		}
		first++;
	}
}


void check_type_of_map(t_vars *vars, char **str)
{
	vars->NO = NULL;
	vars->SO = NULL;
	vars->WE = NULL;
	vars->EA = NULL;
	vars->F = NULL;
	vars->C = NULL;
	char *ptr = NULL;
	int i;

	i = 0;
	while (str[i])
	{
		ptr = ft_strtrim(str[i], " ");
		// printf ("ptr === %s\n", ptr);
		if (ft_strncmp (ptr, "NO", 2) == 0)
			vars->NO = ft_strdup (ptr);
		if (ft_strncmp (ptr, "SO", 2) == 0)
			vars->SO = ft_strdup (ptr);
		if (ft_strncmp (ptr, "WE", 2) == 0)
		{
			// printf ("%s", ft_strtrim((ptr), " "));
			vars->WE = ft_strdup (ptr);
		}
		if (ft_strncmp (ptr, "EA", 2) == 0)
			vars->EA = ft_strdup (ptr);
		if (ft_strncmp (ptr, "F", 1) == 0)
			vars->F = ft_strdup (ptr);
		if (ft_strncmp (ptr, "C", 1) == 0)
			vars->C = ft_strdup (ptr);
		if (vars->NO != NULL && vars->SO != NULL && vars->WE != NULL
			&& vars->EA != NULL && vars->F != NULL && vars->C != NULL)
		{
			free (ptr);
			vars->last = i + 1;
			printf ("last ==== %d\n", vars->last);
			return ;
		}
		free (ptr);
		i++;
	}
}

void check_type_file_is_correct(t_vars *vars, __unused char **str)
{
	if (vars->NO == NULL || vars->SO == NULL || vars->WE == NULL
		|| vars->EA == NULL || vars->F == NULL || vars->C == NULL)
	{
		write_error();
	}
	// int i = 0;
	// while (i < vars->last)
	// {
	// 	if (ft_strcmp(str[i] , "NO") != 0 && ft_strcmp(str[i], "SO") != 0
	// 		&& ft_strcmp(str[i], "WE") != 0 && ft_strcmp(str[i], "EA") != 0
	// 			&& ft_strcmp(str[i], "F") != 0 && ft_strcmp(str[i], "C") != 0
	// 				&& ft_strcmp(str[i], "\n") != 0)
	// 	{
	// 		printf ("ERROR PATH of file === %d\n", i);
	// 		write_error();
	// 	}
	// 	i++;
	// }
};

int	count_str(char **str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}



void check_path_is_correct(t_vars *vars, __unused char **str)
{
	int i;
	vars->path_NO = NULL;
	vars->path_SO = NULL;
	vars->path_WE = NULL;
	vars->path_EA = NULL;
	// printf ("hamza === %s\n", ft_strdup(ptr[0]));
	vars->path_F = NULL;
	vars->path_C = NULL;
	char **ptr;
	i = 0;
	while (i < vars->last)
	{
		ptr = NULL;
		ptr = ft_split(str[i], ' ');
		if (ft_strlen(ptr[0]) == 2)
		{
			if (ft_strcmp(ptr[0] , "NO") == 0)
				vars->path_NO = ft_strdup(ptr[1]);
			if (ft_strcmp(ptr[0] , "SO") == 0)
				vars->path_SO = ft_strdup(ptr[1]);
			if (ft_strcmp(ptr[0] , "WE") == 0)
				vars->path_WE = ft_strdup(ptr[1]);
			if (ft_strcmp(ptr[0] , "EA") == 0)
				vars->path_EA = ft_strdup(ptr[1]);
		}
		if (ft_strlen(ptr[0]) == 1)
		{
			if (ft_strcmp(ptr[0] ,"F") == 0)
				vars->path_F = ft_strdup(ptr[1]);
			if (ft_strcmp(ptr[0] ,"C") == 0)
				vars->path_C = ft_strdup(ptr[1]);
		}
		// if (count_str(ptr) > 2 || count_str(ptr) == 1)
		// {
		// 	printf ("%d\n", count_str(ptr));
		// 	printf ("path not correct\n");
		// 	exit (1);
		// }
		// if (str[i][0] != '\n')
		
		int j = 0;
		while (ptr[j])
		{
			free (ptr[j]);
			j++;
		}
		free (ptr);
		i++;
	}
	if (vars->path_NO == NULL || vars->path_SO == NULL || vars->path_WE == NULL
		|| vars->path_EA == NULL || vars->path_F == NULL || vars->path_C == NULL)
	{
		printf ("problime path\n");
		exit (1);
	}
	// printf ("%s", vars->path_NO);
	// printf ("%s", vars->path_SO);
	// printf ("%s", vars->path_WE);
	// printf ("%s", vars->path_EA);
	// // printf ("problime \n");
	// printf ("%s", vars->path_F);
	// printf ("%s", vars->path_C);
}

void check_tab_in_maps(char **str, __unused t_vars *vars)
{
	int i = 0;
	int j;
	
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == '\t')
			{
				printf ("ERROR TAB\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
}

