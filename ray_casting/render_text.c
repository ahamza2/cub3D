/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:05:49 by haarab            #+#    #+#             */
/*   Updated: 2024/01/14 23:22:21 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	get_color_from_pos(mlx_texture_t *walli, int y, int x)
{
	int	index;

	if (x >= 0 && x < (int)walli->width && y >= 0 && y < (int)walli->height)
	{
		index = (walli->width * y + x) * walli->bytes_per_pixel;
		return (ft_pixel(walli->pixels[index], walli->pixels[index + 1],
				walli->pixels[index + 2], 255));
	}
	return (ft_pixel(0, 0, 0, 0));
}

// void	n_texture(t_mlx  *mlx, int x, int y, float dist_top)
// {
// 	int	color;
// 	int	offse_x;
// 	int	offse_y;

// 	offse_y = dist_top * p->fac / 2;
// 	offse_x = (int)p->ray_ax % p->north->width;
// 	color = get_color_from_pos(p->north, offse_y, offse_x);
// 	mlx_put_pixel(p->angle, x, y, color);
// }

void	e_texture(t_mlx  *mlx, int x, int y, float dist_top)
{
	int	color;
	int	offse_x;
	int	offse_y;
	
	offse_y = dist_top * mlx->rays->factur / 2;
	offse_x = (int)mlx->rays[x].wallHitY % mlx->text->width;
	color = get_color_from_pos(mlx->text, offse_y, offse_x);
	mlx_put_pixel(mlx->img, x, y, color);
}

// void	s_texture(t_mlx  *mlx, int x, int y, float dist_top)
// {
// 	int	color;
// 	int	offse_x;
// 	int	offse_y;

// 	offse_y = dist_top * p->fac / 2;
// 	offse_x = (int)p->ray_ax % p->south->width;
// 	color = get_color_from_pos(p->south, offse_y, offse_x);
// 	mlx_put_pixel(p->angle, x, y, color);
// }

// void	w_texture(t_mlx  *mlx, int x, int y, float dist_top)
// {
// 	int	color;
// 	int	offse_x;
// 	int	offse_y;

// 	offse_y = dist_top * p->fac / 2;
// 	offse_x = (int)p->ray_ay % p->west->width;
// 	color = get_color_from_pos(p->west, offse_y, offse_x);
// 	mlx_put_pixel(p->angle, x, y, color);
// }