/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:47:37 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/12 19:40:25 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main()
{
    t_mlx   mlx;
    
    char *map[MAP_WIDTH] = 
    {
        "11111111111111111111", 
        "10000000000000000001", 
        "10000000000000000001", 
        "10001010101010101001", 
        "10000000000000000001", 
        "10000000000000001001", 
        "10000000000000001001", 
        "10000000000000001001", 
        "10000000000000001001", 
        "10000000000001111001",
        "10000000000000000001",
        "100000000000000N0001",
        "10000000000000000001", 
        "11111111111111111111"
    };
    
    mlx.map.Map = map;
    mlx.mlx = mlx_init(W_WIDTH, W_HEIGHT, "CUBE", true);
    mlx.img = mlx_new_image(mlx.mlx, W_WIDTH, W_HEIGHT);
    mlx_image_to_window(mlx.mlx, mlx.img, 0, 0);
    player_init(&mlx, &mlx.player);
    put_map(&mlx);
    put_player(&mlx);
    draw_line(&mlx, 30);
    mlx.rays = malloc(sizeof(t_ray) * NUM_RAYS);
    // line_dda(&mlx, 30);
    // draw_line(&mlx, 30);
    // mlx_key_hook(mlx.mlx, &my_keyhook, &mlx);
	mlx_loop_hook(mlx.mlx, &my_keyhook, &mlx);
    // mlx_hook(mlx.mlx, &my_keyhook, &mlx);
    // mlx_delete_image(mlx.mlx, mlx.img);
    // free(mlx.rays);
    mlx_loop(mlx.mlx);

    mlx_terminate(mlx.mlx);
}
