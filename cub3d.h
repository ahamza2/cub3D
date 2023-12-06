/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:58:21 by haarab            #+#    #+#             */
/*   Updated: 2023/12/06 19:37:55 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "./get_next_line/get_next_line.h"




typedef struct s_vars
{
	char	**move;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	char	*path_NO;
	char	*path_SO;
	char	*path_WE;
	char	*path_EA;
	char	*path_F;
	char	*path_C;
	char	**maps;
	int		lines_map;
	int 	first_line_map;
	int		last_line_map;
	int		last;
	int		count_string;
	int		CR;
	int		CG;
	int		CB;
	int		FR;
	int		FG;
	int		FB;
	
}	t_vars;

int	ft_isdigit(int a);
void check_path_is_correct(t_vars *vars, char **str);
void save_map(t_vars *vars, char **str);
void check_last_path(char **str, t_vars *vars);
int	ft_strcmp(char *s1, char *s2);
void check_type_file_is_correct(t_vars *vars, char **str);
char	**ft_split(char const *s, char c);
// int	count_strings(char const *str);
int	count_strings(char const *str, char c);
char *path_map(t_vars *vars, char *str);
void check_type_of_map(t_vars *vars, char **str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void write_error();
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
int	ft_atoi(char *str);
int	check_is_digit(char *str);
char	*ft_strtrim(char const *s1, char const *set);
void check_tab_in_maps(char **str, t_vars *vars);

void C_RGB(t_vars *vars);
void F_RGB(t_vars *vars);
#endif