/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:47:37 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/25 15:13:26 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	close_keyhook(void *param)
{
	free_allocate(param);
	printf("See You Soon!!\n");
	exit(0);
}

void	main_p2(t_mlx *mlx)
{
	ft_colors(mlx);
	mlx->fov_angle = 60 * (PI / 180);
	mlx->num_rays = WIDTH / WALL_STRIP_WIDTH;
	mlx->w_wid = mlx->vars.map_width * TILE_SIZE;
	mlx->w_hei = mlx->vars.map_height * TILE_SIZE;
	mlx->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
	player_init(mlx, &mlx->player);
	put_map(mlx);
	put_player(mlx);
	draw_line(mlx, 30);
	mlx->rays = malloc(sizeof(t_ray) * mlx->num_rays);
	load_textures(mlx);
	mlx_loop_hook(mlx->mlx, &keyhook, mlx);
	mlx_close_hook(mlx->mlx, &close_keyhook, mlx);
	mlx_loop(mlx->mlx);
	mlx_delete_image(mlx->mlx, mlx->draw);
	mlx_terminate(mlx->mlx);
	free_allocate(mlx);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	char	**str;

	if (ac != 2)
		return (0);
	if (check_format_av(av[1]) == 0)
		write_error();
	str = ft_map(av[1]);
	parsing(&mlx, str);
	main_p2(&mlx);
	return (0);
}
