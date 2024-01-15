/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:14:57 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/15 20:24:24 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool isWall(float y, float x, char **map)
{
    int Y;
    int X;
    
    if (x < 0 || x > W_WIDTH || y < 0 || y > W_HEIGHT)
        return (true);
    Y = floor(y / TILE_SIZE);
    X = floor(x / TILE_SIZE);
    if (map[Y][X] == '1')
        return (true);
    return (false);
}

void    keyhook(void* param)
{
    t_mlx *mlx;
    // float moveStep;
    
    mlx = (t_mlx *)param;
    //escape_key
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_ESCAPE))
        exit (0);

    if (mlx_is_key_down(mlx->mlx, MLX_KEY_W))
	{
		mlx->player.newX = mlx->player.x + cos(mlx->player.rotationAngle) * mlx->player.moveSpeed;
		mlx->player.newY = mlx->player.y + sin(mlx->player.rotationAngle) * mlx->player.moveSpeed;
		if (!isWall(mlx->player.newY, mlx->player.newX, mlx->map.Map))
		{
			mlx->player.x = mlx->player.newX;
			mlx->player.y = mlx->player.newY;
		}
	}
    if (mlx_is_key_down(mlx->mlx, MLX_KEY_S))
	{
		mlx->player.newX = mlx->player.x - cos(mlx->player.rotationAngle) * mlx->player.moveSpeed;
		mlx->player.newY = mlx->player.y - sin(mlx->player.rotationAngle) * mlx->player.moveSpeed;
		if (!isWall(mlx->player.newY, mlx->player.newX, mlx->map.Map))
		{
			mlx->player.x = mlx->player.newX;
			mlx->player.y = mlx->player.newY;
		}
	}
    if (mlx_is_key_down(mlx->mlx, MLX_KEY_D))
	{
		mlx->player.newX = mlx->player.x - mlx->player.moveSpeed * cos(mlx->player.rotationAngle - (PI / 2));
		mlx->player.newY = mlx->player.y - mlx->player.moveSpeed * sin(mlx->player.rotationAngle - (PI / 2));
		if (!isWall(mlx->player.newY, mlx->player.newX, mlx->map.Map))
		{
			mlx->player.x = mlx->player.newX;
			mlx->player.y = mlx->player.newY;
		}
	}
    if (mlx_is_key_down(mlx->mlx, MLX_KEY_A))
	{
		mlx->player.newX = mlx->player.x + mlx->player.moveSpeed * cos(mlx->player.rotationAngle - (PI / 2));
		mlx->player.newY = mlx->player.y + mlx->player.moveSpeed * sin(mlx->player.rotationAngle - (PI / 2));
		if (!isWall(mlx->player.newY, mlx->player.newX, mlx->map.Map))
		{
			mlx->player.x = mlx->player.newX;
			mlx->player.y = mlx->player.newY;
		}
	}
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT))
		mlx->player.turnDirection += 1;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT))
		mlx->player.turnDirection -= 1;
    //Updating rotation angle
   	mlx->player.rotationAngle += mlx->player.turnDirection * mlx->player.rotationSpeed;
    //reset angle
    reset_angle(mlx);
    //Rendering_things
    // castAllRays(mlx);
    // generate3dProjection(mlx);
    int i = 0;
    int j = 0;
    while (i < WIDTH)
    {
        j = 0;
        while (j < HEIGHT)
        {
            mlx_put_pixel(mlx->img, i, j, 0x000000);
            j++;
        }
        i++;
    }
    load_textures(mlx);
    castAllRays(mlx);
    generate3dProjection(mlx);
    put_map(mlx);
    put_player(mlx);
    // draw_line(mlx, 30);
    renderRays(mlx);
    if (mlx_is_key_down(mlx->mlx,  MLX_KEY_RIGHT))
        mlx->player.turnDirection = 0;
    if (mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT))
        mlx->player.turnDirection = 0;
}
