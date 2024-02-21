/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:19:16 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/25 13:38:12 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../../../MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PI 3.14159265358979323846264338327950288
# define TILE_SIZE 64

# define WIDTH 1080

# define HEIGHT 720

# define WALL_STRIP_WIDTH 1.0

# define MINIMAP_SCALE 0.1

# define FALSE 0
# define TRUE 1

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_map
{
	int				tilex;
	int				tiley;
	int				tilecolor;
}					t_map;

typedef struct s_player
{
	double			x;
	double			y;
	double			new_x;
	double			new_y;
	double			width;
	double			height;
	double			turndirection;
	int				walkdirection;
	double			rotationangle;
	double			movespeed;
	double			rotationspeed;
}					t_player;

typedef struct s_dda
{
	int				dx;
	int				dy;
	int				steps;
	double			xin;
	double			yin;
	double			x;
	double			y;
}					t_dda;

typedef struct s_ray
{
	double			ray_angle;
	double			wallhitx;
	double			wallhity;
	double			distance;
	int				washitvertical;
	int				israyfacingup;
	int				israyfacingdown;
	int				israyfacingleft;
	int				israyfacingright;
	int				wallhitcontent;
}					t_ray;

typedef struct s_pos
{
	double			x;
	double			y;
	char			dir;
}					t_pos;

typedef struct s_vars
{
	int				map_width;
	int				map_height;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	char			*path_f;
	char			*path_c;
	char			**maps;
	int				lines_map;
	int				last;
	int				start;
	int				maxline;
	int				cr;
	int				cg;
	int				cb;
	int				fr;
	int				fg;
	int				fb;
}					t_vars;

typedef struct s_mlx
{
	double			fov_angle;
	double			num_rays;
	int				w_wid;
	int				w_hei;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*draw;
	t_map			map;
	t_player		player;
	t_ray			*rays;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	u_int32_t		floor_color;
	u_int32_t		ceiling_color;
	t_vars			vars;
	int				x;
	int				y;
	double			distanceprojplane;
	double			projectedwallheight;
	int				wallstripheight;
	int				walltoppixel;
	int				wallbottompixel;
	double			correcteddistance;
	double			fov;
	double			offset;
	int				distancefromtop;
	int				offsetx;
	int				textureoffsety;
	u_int32_t		color;
	int				israyfacingdown;
	int				israyfacingup;
	int				israyfacingright;
	int				israyfacingleft;
	double			xintercept;
	double			yintercept;
	double			xstep;
	double			ystep;
	int				foundhorzwallhit;
	double			horzwallhitx;
	double			horzwallhity;
	int				horzwallcontent;
	double			nexthorztouchx;
	double			nexthorztouchy;
	double			xtocheck;
	double			ytocheck;
	int				foundvertwallhit;
	double			vertwallhitx;
	double			vertwallhity;
	int				vertwallcontent;
	double			nextverttouchx;
	double			nextverttouchy;
	double			horzhitdistance;
	double			verthitdistance;
	int				dx;
	int				dy;
	int				steps;
	int				k;
	double			xin;
	double			yin;
}					t_mlx;

void				put_map(t_mlx *mlx);
void				player_init(t_mlx *mlx, t_player *player);
void				put_player(t_mlx *mlx);
void				keyhook(void *param);
bool				is_wall(double y, double x, char **map, t_mlx *mlx);
void				reset_angle(t_mlx *mlx);
void				draw_line(t_mlx *mlx, int len);
double				normalize_angle(double angle);
double				distancebetweenpoints(double x1, double y1, double x2,
						double y2);
void				draw_ray(t_mlx *mlx, int xb, int yb);
t_pos				find_player(char **map);
void				load_textures(t_mlx *mlx);
void				setplayerangle(t_mlx *mlx);
void				ft_colors(t_mlx *mlx);
void				vertical_hit(t_mlx *mlx, int i, int j);
void				generate3dprojection(t_mlx *mlx);
void				wall_p0(t_mlx *mlx, int i);
void				wall_p1(t_mlx *mlx, int i);
int					gen_color(mlx_texture_t *texture, int x, int y);
void				castallrays(t_mlx *mlx);
void				cast_ray(t_mlx *mlx, double ray_angle, int i);
void				cast_ray_p0(t_mlx *mlx, double ray_angle);
void				cast_ray_p1(t_mlx *mlx);
void				cast_ray_p2(t_mlx *mlx, double ray_angle);
void				cast_ray_p3(t_mlx *mlx);
void				cast_ray_p4(t_mlx *mlx);
void				cast_ray_p5(t_mlx *mlx, double ray_angle, int i);

/////////////////////////////////////////////////////////////////////
//                              parsing                            //
/////////////////////////////////////////////////////////////////////

int					ft_isdigit(int a);
void				save_map(t_mlx *mlx, char **str);
void				check_type_file_is_correct(t_mlx *mlx);
char				**ft_split(char const *s, char c);
void				check_type_of_map(t_mlx *mlx, char **str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *src);
int					ft_atoi(char *str);
char				*ft_strtrim(char const *s1, char const *set);
void				check_tab_in_maps(char **str);
void				c_rgb(t_mlx *mlx);
void				f_rgb(t_mlx *mlx);
int					check_format_av(char *str);
char				**ft_map(char *av);
int					ft_get(char *str);
void				write_error(void);
void				error_color(void);
void				free_rgb(char **ptr);
void				free_2d(char **str);
void				check_persone(char **str, t_mlx *mlx, int first);
char				derection_player(char **str, t_mlx *mlx, int first);
void				error_maps(void);
void				initialization_variable(t_mlx *mlx);
void				double_type_map(char *str);
void				line_of_map(t_mlx *mlx, char **str);
int					ft_maxline(char **str, int i, int k);
int					ft_startline(char **str, int i, int k);
int					ft_strlene(char *str);
int					count_str(char const *str, char c);
void				check_path_is_correct(t_mlx *mlx, char **str);
void				alocate_path(t_mlx *mlx, char **ptr);
void				check_map_is_correct(char **str, t_mlx *mlx, int first);
int					check_last_stringmap(char **str, int first, t_mlx *mlx);
int					check_first_stringmap(char **str, int first, t_mlx *mlx);
void				error_path(void);
void				error_type(char *ptr);
void				parsing(t_mlx *mlx, char **str);
int					ft_strcmp(char *s1, char *s2);
void				alocate_typepath(t_mlx *mlx, char *ptr);
void				alocate_savemap(t_mlx *mlx, char **str, int b);
void				alocate_space(t_mlx *mlx);
void				alocate_typeimage(t_mlx *mlx, char *ptr);
void				alocate_typergb(t_mlx *mlx, char *ptr);
void				free_allocate(t_mlx *mlx);
void				free_path_first(t_mlx *mlx);
void				free_map(t_mlx *mlx);
void				free_path(t_mlx *mlx);
int					check_is_only_space(char *str);

#endif

// gcc main.c $MY_LIB -lglfw -L$GLFW -fsanitize=address