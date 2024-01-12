/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 12:48:54 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/09 17:42:48 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    put_rect(t_mlx  *mlx)
{
    int x;
    int y;

    y = 0;
    while (y < TILE_SIZE)
    {
        x = 0;
        while (x < TILE_SIZE)
        {
            // if (x == 0 || y == 0)
            //     mlx_put_pixel(mlx->img, (mlx->map.tileX + x) * MINIMAP_SCALE, (mlx->map.tileY + y) * MINIMAP_SCALE, 0x800e34);
            // else
            mlx_put_pixel(mlx->img, (mlx->map.tileX + x) * MINIMAP_SCALE, (mlx->map.tileY + y) * MINIMAP_SCALE, mlx->map.tileColor);
            x++;
        }
        y++;
    }
}

void    put_map(t_mlx *mlx)
{
    int x;
    int y;

    y = 0;
    while (mlx->map.Map[y] != NULL)
    {
        x = 0;
        while (mlx->map.Map[y][x] != '\0')
        {
            mlx->map.tileX = x * TILE_SIZE;
            mlx->map.tileY = y * TILE_SIZE;
            if (mlx->map.Map[y][x] == '1')
                mlx->map.tileColor = 0x000000ff;
            else
                mlx->map.tileColor = 0xfc9e4fff;
            put_rect(mlx);
            x++;
        }
        y++;
    }
}



// r g b a
    //  00000000   00000000      0000000  11111111111
