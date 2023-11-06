/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:58:21 by haarab            #+#    #+#             */
/*   Updated: 2023/11/06 19:48:31 by haarab           ###   ########.fr       */
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
	char	*no;

	char	*so;

	char	*we;

	char	*ea;

	char	*f;
	char	*c;
	int		count;
	
}	t_vars;

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

#endif