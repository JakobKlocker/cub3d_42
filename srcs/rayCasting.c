#include "../includes/cub3d.h"

void rayCasting(t_mapInfo *mapInfo)
{
    int x;

    createBG(mapInfo);
        x = 0;
        while(x < mapInfo->screen.width)
        {
            initRayInfoLoop(x, &mapInfo->rayInfo, &mapInfo->player, mapInfo);
            calcStep(&mapInfo->rayInfo);
            DDAExec(mapInfo, &mapInfo->player, &mapInfo->rayInfo);
            calcDist(mapInfo, &mapInfo->player, &mapInfo->rayInfo);
            drawLine(mapInfo, x, mapInfo->rayInfo.drawStart, mapInfo->rayInfo.drawEnd);
            x++;
        }
        mlx_put_image_to_window(mapInfo->mlx.mlx, mapInfo->mlx.win, mapInfo->img.img, 0, 0);
} 

void calcStep(t_rayInfo *rayInfo)
{
    if(rayInfo->rayDirX < 0)
    {
        rayInfo->stepX = -1;
        rayInfo->sideDistX = (rayInfo->posX - rayInfo->mapX) * rayInfo->deltaDistX;
    }
    else
    {
        rayInfo->stepX = 1;
        rayInfo->sideDistX = (rayInfo->mapX + 1.0 - rayInfo->posX) * rayInfo->deltaDistX; 
    }
    if(rayInfo->rayDirY < 0)
    {
        rayInfo->stepY = -1;
        rayInfo->sideDistY = (rayInfo->posY - rayInfo->mapY) * rayInfo->deltaDistY;
    }
    else
    {
        rayInfo->stepY = 1;
        rayInfo->sideDistY = (rayInfo->mapY + 1.0 - rayInfo->posY) * rayInfo->deltaDistY; 
    }
}

void calcDist(t_mapInfo *mapInfo, t_player *player, t_rayInfo *rayInfo)
{
    if(rayInfo->side == 0)
        rayInfo->perpWallDist = rayInfo->sideDistX - rayInfo->deltaDistX;
    else
        rayInfo->perpWallDist = rayInfo->sideDistY - rayInfo->deltaDistY;
    if(rayInfo->perpWallDist == 0)
        rayInfo->lineHeight = mapInfo->screen.height;
    else
        rayInfo->lineHeight = (int)(mapInfo->screen.height / rayInfo->perpWallDist);
    rayInfo->drawStart = -rayInfo->lineHeight / 2 + mapInfo->screen.height / 2;
    rayInfo->drawEnd = rayInfo->lineHeight / 2 + mapInfo->screen.height / 2;
    if(rayInfo->drawStart < 0)
        rayInfo->drawStart = 0;
    if(rayInfo->drawEnd > mapInfo->screen.height)
        rayInfo->drawEnd = mapInfo->screen.height - 1;
}

void DDAExec(t_mapInfo *mapInfo, t_player *player, t_rayInfo *rayInfo)
{
    while(rayInfo->hit == 0)
    {
        if(rayInfo->sideDistX < rayInfo->sideDistY)
        {
            rayInfo->sideDistX += rayInfo->deltaDistX;
            rayInfo->mapX += rayInfo->stepX;
            rayInfo->side = 0;
        }
        else
        {
            rayInfo->sideDistY += rayInfo->deltaDistY;
            rayInfo->mapY += rayInfo->stepY;
            rayInfo->side = 1;
        }
        if(mapInfo->map2D[rayInfo->mapY][rayInfo->mapX] == '1')
            rayInfo->hit = 1;
    }
}
