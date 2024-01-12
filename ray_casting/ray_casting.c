/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:09:59 by hait-sal          #+#    #+#             */
/*   Updated: 2024/01/12 19:23:20 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    castAllRays(t_mlx *mlx)
{
    float rayAngle;
    float nbr_rays = (float)NUM_RAYS;
    float fov = (float)FOV_ANGLE * (180 / PI);
    int i;
    
    //start first ray subtracting half of the FOV
    rayAngle = mlx->player.rotationAngle - (FOV_ANGLE / 2);
    i = 0;
    // printf ("fov angle ; %f\n", FOV_ANGLE);
    // printf ("NBR OF RAYS : %f\n", NUM_RAYS);
    // printf ("ray angleeeeeeeeeeee : %f\n", rayAngle);
    while (i < NUM_RAYS)
    {
        castRay(mlx, rayAngle, i);
        // printf ("ray Angle : %f\n", rayAngle);
        // draw_ray(mlx, mlx->rays[i].wallHitX, mlx->rays[i].wallHitY);
        rayAngle += ((fov / nbr_rays) * (PI / 180));
        // rayAngle += (0.046 * (PI / 180));
        i++;
    }
    // exit (1);
}

//the ray struct vid 1 9:01

float   normalizeAngle(float angle)
{
    angle = remainder(angle, TWO_PI);
    if (angle < 0)
        angle = TWO_PI + angle;
    return (angle);
}

float   distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))); 
}

void    castRay(t_mlx *mlx, float rayAngle, int i)
{
    rayAngle = normalizeAngle(rayAngle);
    
    int     isRayFacingDown;
    int     isRayFacingUp;
    int     isRayFacingRight;
    int     isRayFacingLeft;
    float   xintercept;
    float   yintercept;
    float   xstep;
    float   ystep;
    int     foundHorzWallHit;
    float   horzWallHitX;
    float   horzWallHitY;
    int     horzWallContent;
    float   nextHorzTouchX;
    float   nextHorzTouchY;
    
    isRayFacingDown = rayAngle > 0 && rayAngle < PI;
    isRayFacingUp = !isRayFacingDown;
    isRayFacingRight = rayAngle < 0.5 * PI || rayAngle > 1.5 * PI;
    isRayFacingLeft = !isRayFacingRight;

    // Horizontal ray-grid intersection
    foundHorzWallHit = FALSE;
    horzWallHitX = 0;
    horzWallHitY = 0;
    horzWallContent = 0;

    //Find the y-coordinate of the closest horizontal grid intersection
    yintercept = floor(mlx->player.y / TILE_SIZE) * TILE_SIZE;
    if (isRayFacingDown)
        yintercept += TILE_SIZE;
    else
        yintercept += 0;
    
    //Find the x-coordinate of the closest horizontal grid intersection
    xintercept = mlx->player.x + (yintercept - mlx->player.y) / tan(rayAngle);

    //Calculate the increment xstep and ystep
    ystep = TILE_SIZE;
    if (isRayFacingUp)
        ystep *= -1;
    
    xstep = TILE_SIZE / tan(rayAngle);
    if (isRayFacingLeft && xstep > 0)
        xstep *= -1;
    if (isRayFacingRight && xstep < 0)
        xstep *= -1;

    nextHorzTouchX = xintercept;
    nextHorzTouchY = yintercept;

    //Increment xstep and ystep until we find a wall
    
    while (nextHorzTouchX >= 0 && nextHorzTouchX <= W_WIDTH && nextHorzTouchY >= 0 && nextHorzTouchY <= W_HEIGHT)
    {
        float xToCheck;
        float yToCheck;
        xToCheck = nextHorzTouchX;
        if (isRayFacingUp)
            yToCheck = nextHorzTouchY - 1;
        else
            yToCheck = nextHorzTouchY;
        // if (mapHasWallAt(xToCheck, yToCheck))
        if (isWall(yToCheck, xToCheck, mlx->map.Map))
        {
            //found a wall hit
            horzWallHitX = nextHorzTouchX;
            horzWallHitY = nextHorzTouchY;
            horzWallContent = mlx->map.Map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
            foundHorzWallHit = TRUE;
            break;
        }
        else
        {
            nextHorzTouchX += xstep;
            nextHorzTouchY += ystep;
        }
    }

    //vertical ray-grid intersection
    
    int    foundVertWallHit;
    float  vertWallHitX;
    float  vertWallHitY;
    int    vertWallContent;
    
    foundVertWallHit = FALSE;
    vertWallHitX = 0;
    vertWallHitY = 0;
    vertWallContent = 0;
    
    //Find the x-coordinate of the closest vertical grid intersection
    xintercept = floor(mlx->player.x / TILE_SIZE) * TILE_SIZE;
    if (isRayFacingRight)
        xintercept += TILE_SIZE;
    //Find the y-coordinate of the closest vertical grid intersection
    yintercept = mlx->player.y + (xintercept - mlx->player.x) * tan(rayAngle);
    
    //Calculate the increment xstep and ystep
    xstep = TILE_SIZE;
    if (isRayFacingLeft)
        xstep *= -1;
    ystep = TILE_SIZE * tan(rayAngle);
    if (isRayFacingUp && ystep > 0)
        ystep *= -1;
    if (isRayFacingDown && ystep < 0)
        ystep *= -1;
        
    float nextVertTouchX = xintercept;
    float nextVertTouchY = yintercept;

    //Increment xstep and ystep until we find a wall
    while (nextVertTouchX >= 0 && nextVertTouchX <= W_WIDTH && nextVertTouchY >= 0 && nextVertTouchY <= W_HEIGHT)
    {
        float xToCheck = nextVertTouchX;
        if (isRayFacingLeft)
            xToCheck = nextVertTouchX - 1;
        float yToCheck = nextVertTouchY;
        
        // if (mapHasWallAt(xToCheck, yToCheck))
        if (isWall(yToCheck, xToCheck, mlx->map.Map))
        {
            //found a wall hit
            vertWallHitX = nextVertTouchX;
            vertWallHitY = nextVertTouchY;
            vertWallContent = mlx->map.Map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
            foundVertWallHit = TRUE;
            break;
        }
        else
        {
            nextVertTouchX += xstep;
            nextVertTouchY += ystep;
        }
    }

    //Calculate both horizontal and vertical distances and choose the smallest value
    float horzHitDistance;
    if (foundHorzWallHit)
        horzHitDistance = distanceBetweenPoints(mlx->player.x, mlx->player.y, horzWallHitX, horzWallHitY);
    else
        horzHitDistance = INT_MAX;
    float vertHitDistance;
    if (foundVertWallHit)
        vertHitDistance = distanceBetweenPoints(mlx->player.x, mlx->player.y, vertWallHitX, vertWallHitY);
    else
        vertHitDistance = INT_MAX;
    
    //only store the smallest of the distances
    
    if (vertHitDistance < horzHitDistance)
    {
        mlx->rays[i].distance = vertHitDistance;
        mlx->rays[i].wallHitX = vertWallHitX;
        mlx->rays[i].wallHitY = vertWallHitY;
        mlx->rays[i].wallHitContent = vertWallContent;
        mlx->rays[i].wasHitVertical = TRUE;
    }
    else
    {
        mlx->rays[i].distance = horzHitDistance;
        mlx->rays[i].wallHitX = horzWallHitX;
        mlx->rays[i].wallHitY = horzWallHitY;
        mlx->rays[i].wallHitContent = horzWallContent;
        mlx->rays[i].wasHitVertical = FALSE;
    }
    mlx->rays[i].rayAngle = rayAngle;
    mlx->rays[i].isRayFacingDown = isRayFacingDown;
    mlx->rays[i].isRayFacingUp = isRayFacingUp;
    mlx->rays[i].isRayFacingLeft = isRayFacingLeft;
    mlx->rays[i].isRayFacingRight = isRayFacingRight;
}

void draw_ray(t_mlx *mlx, int xb, int yb)
{
    int Dx;
    int Dy;
    int steps;
    int k;
    float xin;
    float yin;
    float X;
    float Y;
    
    Dx = xb - mlx->player.x;
    Dy = yb - mlx->player.y;
    X = mlx->player.x;
    Y = mlx->player.y;
    if (abs(Dx) > abs(Dy))
        steps = abs(Dx);
    else
        steps = abs(Dy);
    xin = Dx / (float) steps;
    yin = Dy / (float) steps;
    k = 0;
    while (k < steps)
    {
        mlx_put_pixel(mlx->img, round(X) * MINIMAP_SCALE, round(Y) * MINIMAP_SCALE, 0x6f9d80ff);
        X = X + xin;
        Y = Y + yin;
        k++;
    }
}

void    renderRays(t_mlx *mlx)
{
    int i = 0;
    while (i < NUM_RAYS)
    {
        draw_ray(mlx, mlx->rays[i].wallHitX, mlx->rays[i].wallHitY);
        i++;
    }
}
