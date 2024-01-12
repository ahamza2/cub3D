/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:03:31 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/12 20:08:05 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    generate3dProjection(t_mlx *mlx)
{
    float   distanceProjPlane;
    float   projectedWallHeight;
    int     wallStripHeight;
    int     wallTopPixel;
    int     wallBottomPixel;
    float   correctedDistance;
    int     i;
    int     j;
    float fov = (float)FOV_ANGLE;
    
    i = 0;
    while (i < NUM_RAYS)
    {
        correctedDistance = mlx->rays[i].distance * cos(mlx->rays[i].rayAngle - mlx->player.rotationAngle);
        distanceProjPlane = (W_WIDTH / 2) / tan(fov / 2);
        projectedWallHeight = (TILE_SIZE / correctedDistance) * distanceProjPlane;
        wallStripHeight = (int) projectedWallHeight;
        wallTopPixel = (W_HEIGHT / 2) - (wallStripHeight / 2);
        if (wallTopPixel < 0)
            wallTopPixel = 0;
        wallBottomPixel = (W_HEIGHT / 2) + (wallStripHeight / 2);
        if (wallBottomPixel > W_HEIGHT)
            wallBottomPixel = W_HEIGHT;
        j = 0;
        while (j < wallTopPixel)
        {
            mlx_put_pixel(mlx->img, i, j, 0x00ffffff);//dk
            j++;
        }
        j = wallTopPixel;
        while (j < wallBottomPixel)
        {
            if (mlx->rays[i].wasHitVertical)
            {
                if (mlx->rays[i].rayAngle >= (PI / 2) && mlx->rays[i].rayAngle <= 3 * (PI / 2))//west
                    mlx_put_pixel(mlx->img, i, j, 0xff0000ff);//red
                else//east
                    mlx_put_pixel(mlx->img, i, j, 0x00ff00ff);//green
                
            }
            else//horizontal hit
            {
                if (mlx->rays[i].rayAngle >= 0 && mlx->rays[i].rayAngle <= PI)//north
                    mlx_put_pixel(mlx->img, i, j, 0x0000ffff);//blue
                else//south
                    mlx_put_pixel(mlx->img, i, j, 0xffa500ff);//kherwi
            }
            j++;
        }
        while (j < W_HEIGHT)
        {
            mlx_put_pixel(mlx->img, i, j, 0x00aaffff);//dk
            j++;
        }
        i++;
    }
}