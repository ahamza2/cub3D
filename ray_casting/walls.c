#include "cube3d.h"

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
    // int textureOffsetX;
	float offset;
    
    i = 0;
    while (i < NUM_RAYS)
    {
        correctedDistance = mlx->rays[i].distance * cos(mlx->rays[i].rayAngle - mlx->player.rotationAngle);
        distanceProjPlane = (WIDTH / 2) / tan(fov / 2);
        projectedWallHeight = (TILE_SIZE / correctedDistance) * distanceProjPlane;
        wallStripHeight = (int) projectedWallHeight;
        wallTopPixel = (HEIGHT / 2) - (wallStripHeight / 2);
        if (wallTopPixel < 0)
            wallTopPixel = 0;
        // wallBottomPixel = (W_HEIGHT / 2) + (wallStripHeight / 2);
        wallBottomPixel = wallTopPixel + projectedWallHeight;
        if (wallBottomPixel > HEIGHT)
            wallBottomPixel = HEIGHT;
        j = 0;
        while (j < wallTopPixel)
        {
            // mlx_put_pixel(mlx->img, i, j, 0x333333ff);//dk
			// mlx_put_pixel(mlx->img, i, j, 0x00ffffff);//dk
			mlx_put_pixel(mlx->img, i, j, 0x000000ff);//dk
            j++;
        }
        // if (mlx->rays[i].wasHitVertical)
        //     textureOffsetX = (int)mlx->rays[i].wallHitY % TILE_SIZE;
        // else
        //     textureOffsetX = (int)mlx->rays[i].wallHitX % TILE_SIZE;
        j = wallTopPixel;
        while (j < wallBottomPixel)
        {
            int distanceFromTop = j + (wallStripHeight / 2) - (HEIGHT / 2);
            if (mlx->rays[i].wasHitVertical)
            {
                if (mlx->rays[i].rayAngle >= (PI / 2) && mlx->rays[i].rayAngle <= 3 * (PI / 2))//west
                {
                    // textureOffsetX = (int)mlx->rays[i].wallHitY % mlx->west->width;
                    offset = mlx->rays[i].wallHitY / TILE_SIZE;
                    offset -= (int)offset;
                    int offsetx = (1 - offset) * mlx->west->width;
                    
                    int textureOffsetY = (1.0 - ((float)distanceFromTop / projectedWallHeight)) * mlx->west->height;
                    textureOffsetY = mlx->west->height - textureOffsetY;
                    u_int32_t color = gen_color(mlx->west, offsetx,textureOffsetY);
                    // u_int32_t color = gen_color(mlx->west, textureOffsetX,textureOffsetY);
                    mlx_put_pixel(mlx->img, i, j, color);
                    
                }
                else//east
                {
                    // if (mlx->rays[i].wasHitVertical)
                    //     textureOffsetX = (int)mlx->rays[i].wallHitY % mlx->east->width;// textureOffsetX = (int)mlx->rays[i].wallHitY % mlx->east->width;
                    // else
                    //     textureOffsetX = (int)mlx->rays[i].wallHitX % mlx->east->width;// textureOffsetX = (int)mlx->rays[i].wallHitX % mlx->east->width;
                    // int textureOffsetY = (1.0 - ((float)distanceFromTop / projectedWallHeight)) * mlx->east->width;// int textureOffsetY = (1.0 - ((float)distanceFromTop / projectedWallHeight)) * mlx->east->height;
                    // u_int32_t color = gen_color(mlx->east, textureOffsetX,textureOffsetY);
                    // mlx_put_pixel(mlx->img, i, j, color);


					offset = mlx->rays[i].wallHitY / TILE_SIZE;
                    offset -= (int)offset;
                    int offsetx = (offset) * mlx->east->width;
                    
                    int textureOffsetY = (1.0 - ((float)distanceFromTop / projectedWallHeight)) * mlx->east->height;
                    textureOffsetY = mlx->east->height - textureOffsetY;
                    u_int32_t color = gen_color(mlx->east, offsetx,textureOffsetY);
                    // u_int32_t color = gen_color(mlx->west, textureOffsetX,textureOffsetY);
                    mlx_put_pixel(mlx->img, i, j, color);
                }
            }
            else//horizontal hit
            {
                if (mlx->rays[i].rayAngle >= 0 && mlx->rays[i].rayAngle <= PI)//north
                {
                    // if (mlx->rays[i].wasHitVertical)
                    //     textureOffsetX = (int)mlx->rays[i].wallHitY % mlx->north->width;
                    // else
                    //     textureOffsetX = (int)mlx->rays[i].wallHitX % mlx->north->width;
                    // int textureOffsetY = (1.0 - ((float)distanceFromTop / projectedWallHeight)) * mlx->north->height;
                    // u_int32_t color = gen_color(mlx->north, textureOffsetX,textureOffsetY);
                    // mlx_put_pixel(mlx->img, i, j, color);

					offset = mlx->rays[i].wallHitX / TILE_SIZE;
                    offset -= (int)offset;
                    int offsetx = (1 - offset) * mlx->north->width;
                    
                    int textureOffsetY = (1.0 - ((float)distanceFromTop / projectedWallHeight)) * mlx->north->height;
                    textureOffsetY = mlx->north->height - textureOffsetY;
                    u_int32_t color = gen_color(mlx->north, offsetx,textureOffsetY);
                    // u_int32_t color = gen_color(mlx->west, textureOffsetX,textureOffsetY);
                    mlx_put_pixel(mlx->img, i, j, color);

                }
                else//south
                {
                    // if (mlx->rays[i].wasHitVertical)
                    //     textureOffsetX = (int)mlx->rays[i].wallHitY % mlx->south->width;
                    // else
                    //     textureOffsetX = (int)mlx->rays[i].wallHitX % mlx->south->width;
                    // int textureOffsetY = (1.0 - ((float)distanceFromTop / projectedWallHeight)) * mlx->south->height;
                    // u_int32_t color = gen_color(mlx->south, textureOffsetX,textureOffsetY);
                    // mlx_put_pixel(mlx->img, i, j, color);

					offset = mlx->rays[i].wallHitX / TILE_SIZE;
                    offset -= (int)offset;
                    int offsetx = (offset) * mlx->south->width;
                    
                    int textureOffsetY = (1.0 - ((float)distanceFromTop / projectedWallHeight)) * mlx->south->height;
                    textureOffsetY = mlx->south->height - textureOffsetY;
                    u_int32_t color = gen_color(mlx->south, offsetx,textureOffsetY);
                    // u_int32_t color = gen_color(mlx->west, textureOffsetX,textureOffsetY);
                    mlx_put_pixel(mlx->img, i, j, color);

                }
            }
            j++;
        }
        while (j < HEIGHT)
        {
            mlx_put_pixel(mlx->img, i, j, 0x2b0001ff);//dk
            j++;
        }
        i++;
    }
}