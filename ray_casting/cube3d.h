/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:47:35 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/14 22:24:48 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "../../MLX42/include/MLX42/MLX42.h"

#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 64.0

#define MAP_WIDTH 20
#define MAP_HEIGHT 14.0

#define W_WIDTH MAP_WIDTH * TILE_SIZE
#define W_HEIGHT MAP_HEIGHT * TILE_SIZE

#define FOV_ANGLE (60 * (PI / 180))
#define WALL_STRIP_WIDTH 1.0
#define NUM_RAYS W_WIDTH / WALL_STRIP_WIDTH
 
#define MINIMAP_SCALE 0.2

#define FALSE 0
#define TRUE 1

typedef struct s_map
{
    char    **Map;
    int     tileX;
    int     tileY;
    int     tileColor;
} t_map;

typedef struct s_player
{
    double  x;
    double  y;
    double  newX;
    double  newY;
    double  width;
    double  height;
    int     turnDirection; 
    int     walkDirection; 
    float   rotationAngle;
    float   moveSpeed;
    float   rotationSpeed;
} t_player;


typedef struct s_dda
{
    int     Dx;
    int     Dy;
    int     steps;
    float   xin;
    float   yin;
    float   X;
    float   Y;
} t_dda;

typedef struct s_ray
{
    float   rayAngle;
    float   wallHitX;
    float   wallHitY;
    float   distance;
    int     wasHitVertical;
    int     isRayFacingUp;
    int     isRayFacingDown;
    int     isRayFacingLeft;
    int     isRayFacingRight;
    int     wallHitContent;
	float	horzHitDistance;
	float	vertHitDistance;
	float   projectedWallHeight;
	float factur;
} t_ray;

typedef struct  s_mlx
{
    mlx_t       *mlx;
    mlx_image_t *img;
    t_map       map;
    t_player    player;
    t_ray       *rays;
	mlx_texture_t	*text;
	mlx_image_t *draw;
} t_mlx;

typedef struct s_pos
{
    float   x;//start x axis position of the player
    float   y;//start y axis position of the player 
    char    dir;//player orientation N S E W
} t_pos;

void    put_rect(t_mlx  *mlx);
void    put_map(t_mlx *mlx);
void    player_init(t_mlx *mlx, t_player *player);
void    put_player(t_mlx  *mlx);
void    my_keyhook(void* param);
bool    isWall(float y, float x, char **map);
void    reset_angle(t_mlx *mlx);
void    draw_line(t_mlx *mlx, int len);
void    castAllRays(t_mlx *mlx);
float   normalizeAngle(float angle);
float   distanceBetweenPoints(float x1, float y1, float x2, float y2);
void    castRay(t_mlx *mlx, float rayAngle, int i);
void    draw_ray(t_mlx *mlx, int xb, int yb);
void    renderRays(t_mlx *mlx);
void    generate3dProjection(t_mlx *mlx);
t_pos   find_player(char **map);
// void    my_keyhook(mlx_key_data_t keydata, void* param);
// void    draw_line(t_mlx *mlx, int len);
// void    line_dda(t_mlx *mlx, int steps);

#endif
// gcc main.c $MY_LIB -lglfw -L$GLFW -fsanitize=address




int32_t	get_color_from_pos(mlx_texture_t *walli, int y, int x);
void	n_texture(t_mlx  *mlx, int x, int y, float dist_top);
void	e_texture(t_mlx  *mlx, int x, int y, float dist_top);
void	s_texture(t_mlx  *mlx, int x, int y, float dist_top);
void	w_texture(t_mlx  *mlx, int x, int y, float dist_top);