/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:37:03 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/15 18:53:26 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * Decode/load a PNG file into a buffer.
 * 
 * @param[in] path Path to the PNG file.
 * @return If successful the texture data is returned, else NULL.
 */
// mlx_texture_t* mlx_load_png(const char* path);

// typedef struct mlx_texture
// {
// 	uint32_t	width;
// 	uint32_t	height;
// 	uint8_t		bytes_per_pixel;
// 	uint8_t*	pixels;
// }	mlx_texture_t;

void    load_textures(t_mlx *mlx)
{
    mlx->north = mlx_load_png("haarab.png");
    mlx->south = mlx_load_png("hait-sal.png");
    mlx->east = mlx_load_png("michael.png");
    mlx->west = mlx_load_png("franklin.png");
}