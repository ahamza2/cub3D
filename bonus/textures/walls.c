/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 05:16:17 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/25 11:41:26 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	create_trgb(int r, int g, int b, int a)
{
	int	hex_color;

	hex_color = (b << 24 | g << 16 | r << 8 | a);
	return (hex_color);
}

int	gen_color(mlx_texture_t *texture, int x, int y)
{
	int	offset;
	int	colors[4];
	int	hex_color;

	if (x < 0 || x >= (int)texture->width || y < 0 || y >= (int)texture->height)
		return (0);
	offset = (y * texture->width + x) * texture->bytes_per_pixel;
	colors[0] = texture->pixels[offset];
	colors[1] = texture->pixels[offset + 1];
	colors[2] = texture->pixels[offset + 2];
	colors[3] = texture->pixels[offset + 3];
	hex_color = create_trgb(colors[2], colors[1], colors[0], colors[3]);
	return (hex_color);
}

void	generate3dprojection(t_mlx *mlx)
{
	int	i;

	mlx->fov = (double)mlx->fov_angle;
	i = 0;
	while (i < mlx->num_rays)
	{
		wall_p0(mlx, i);
		wall_p1(mlx, i);
		i++;
	}
}
