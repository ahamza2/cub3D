/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:23:20 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/04 14:38:57 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// void    draw_line(t_mlx *mlx, int len)
// {
//     float x = mlx->player.x;
//     float y = mlx->player.y;
    
//     float step_x = cos(mlx->player.rotationAngle) / len;
//     float step_y = sin(mlx->player.rotationAngle) / len;

//     // printf("step_x = %f, step_y = %f\n", step_x, step_y);
//     // printf("len = %d\n", len);
//     while (y < len && x < len)
//     {
//         if (mlx->player.x + x > 0 && mlx->player.y + y > 0 &&
//         mlx->player.x + x < mlx->img->width && mlx->player.y + y < mlx->img->height)
//         {
//             mlx_put_pixel(mlx->img, mlx->player.x + x, mlx->player.y + y, 0xffffff);
//             y += step_y;
//             // if (step_x != 0)
//                 x += step_x;
//             // else if (step_x == 0 && y == 0)
//             //     x = 0;
//         }
//         printf("x = %f, y = %f\n", x, y);
//     }
// }

void draw_line(t_mlx *mlx, int len)
{
    int     k;
    t_dda   dda;
    
    dda.Dx = cos(mlx->player.rotationAngle) * len;
    dda.Dy = sin(mlx->player.rotationAngle) * len;
    dda.X = mlx->player.x + mlx->player.height/2;
    dda.Y = mlx->player.y + mlx->player.width/2;
    if (abs(dda.Dx) > abs(dda.Dy))
        dda.steps = abs(dda.Dx);
    else
        dda.steps = abs(dda.Dy);
    dda.xin = dda.Dx / (float) dda.steps;
    dda.yin = dda.Dy / (float) dda.steps;
    k = 0;
    while (k < dda.steps) 
    {
        mlx_put_pixel(mlx->img, round(dda.X) * MINIMAP_SCALE, round(dda.Y) * MINIMAP_SCALE, 0xffffff);
        dda.X = dda.X + dda.xin;
        dda.Y = dda.Y + dda.yin;
        k++;
    }
}

void    reset_angle(t_mlx *mlx)
{
    // printf("I'm in reset angle\n");
    if (mlx->player.rotationAngle > 2 * PI)
        mlx->player.rotationAngle -= 2 * PI;
    if (mlx->player.rotationAngle < 0)
        mlx->player.rotationAngle += 2 * PI;
}