/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:28:20 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/14 16:41:04 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    player_init(t_mlx *mlx, t_player *player)
{
    t_pos Player = find_player(mlx->map.Map);
    // mlx->player.x = Player.x;
    // mlx->player.y = Player.y;
    player->x = Player.x * MINIMAP_SCALE;
    player->y = Player.y * MINIMAP_SCALE;
    player->width = 5 ;
    player->height = 5;
    player->turnDirection = 0; // -1 for left, +1 for right
    player->walkDirection = 0; // -1 for back, +1 for front
    player->rotationAngle = PI / 2;
    player->moveSpeed = 4;
    player->rotationSpeed = 4 * (PI / 180);
}

void    put_player(t_mlx  *mlx)
{
    int x;
    int y;

    y = 0;
	
    while (y < mlx->player.height)
    {
        x = 0;
        while (x < mlx->player.width)
        {
            mlx_put_pixel(mlx->img, (mlx->player.x + x) * MINIMAP_SCALE, (mlx->player.y + y) * MINIMAP_SCALE, 0xffffff);
            x++;
        }
        y++;
    }

}

t_pos   find_player(char **map)
{
    t_pos   player;
    int     x;
    int     y;

    y = 0;
    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
            {
                player.x = x * TILE_SIZE + (TILE_SIZE / 2);
                player.y = y * TILE_SIZE + (TILE_SIZE / 2);
                player.dir = map[y][x];
            }
            x++;   
        }
        y++;
    }
    return (player);
}
