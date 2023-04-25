#include "../includes/cub3d.h"

void drawLine(t_mapInfo *mapInfo, int x, int drawStart, int drawEnd);

void initRayInfo(int x, t_rayCamInfo *rayInfo, t_player *player, t_mapInfo *mapInfo)
{
    rayInfo->dirX = -1;
    rayInfo->dirY = 0;

    rayInfo->planeX = 0;
    rayInfo->planeY = 0.66;
    rayInfo->posX = player->posX;
    rayInfo->posY = player->posY;
    rayInfo->camera = 2 * x / (double)mapInfo->screen.width - 1;
    rayInfo->rayDirX = rayInfo->dirX + rayInfo->planeX * rayInfo->camera;
    rayInfo->rayDirY = rayInfo->dirY + rayInfo->planeY * rayInfo->camera;
    rayInfo->mapX = (int)rayInfo->posX;
    rayInfo->mapY = (int)rayInfo->posY;
    rayInfo->deltaDistX = fabs(1 / rayInfo->rayDirX);
    rayInfo->deltaDistY = fabs(1 / rayInfo->rayDirY);
    rayInfo->hit = 0;
}

void calcSteps(t_rayCamInfo *rayInfo)
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

void rayDist(t_mapInfo *mapInfo, t_player *player, t_rayCamInfo *rayInfo)
{

    if(rayInfo->side == 0)
        rayInfo->perpWallDist = rayInfo->sideDistX - rayInfo->deltaDistX;
    else
        rayInfo->perpWallDist = rayInfo->sideDistY - rayInfo->deltaDistY;
    
    rayInfo->lineHeight = (int)(mapInfo->screen.height / rayInfo->perpWallDist);
    if(rayInfo->perpWallDist == 0)
        rayInfo->lineHeight = 1240;
    rayInfo->drawStart = -rayInfo->lineHeight / 2 + mapInfo->screen.height / 2;
    rayInfo->drawEnd = rayInfo->lineHeight / 2 + mapInfo->screen.height / 2;

    if(rayInfo->drawStart < 0)
        rayInfo->drawStart = 0;
    if (rayInfo->drawStart > mapInfo->screen.height)
        rayInfo->drawStart = mapInfo->screen.height;
    if(rayInfo->drawEnd > mapInfo->screen.height)
        rayInfo->drawEnd = mapInfo->screen.height - 1;
    if(rayInfo->drawEnd < 0)
        rayInfo->drawEnd = 0;
}

void execDDA(t_mapInfo *mapInfo, t_player *player, t_rayCamInfo *rayInfo)
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
        ft_printf("%c", mapInfo->map2D[rayInfo->mapY][rayInfo->mapX]);
        if(mapInfo->map2D[rayInfo->mapY][rayInfo->mapX] == '1')
            rayInfo->hit = 1;
    }
}

void DDA(t_mapInfo *mapInfo, t_player *player)
{
    int x;
    t_rayCamInfo rayInfo;

    x = 0;
    while(x < mapInfo->screen.width)
    {
        initRayInfo(x, &rayInfo, player, mapInfo);
        calcSteps(&rayInfo);
        execDDA(mapInfo, player, &rayInfo);
        rayDist(mapInfo, player, &rayInfo);
        drawLine(mapInfo, x, rayInfo.drawStart, rayInfo.drawEnd);
        x++;
    }
} 


void drawLine(t_mapInfo *mapInfo, int x, int drawStart, int drawEnd)
{
    while(drawStart != drawEnd)
    {
        mlx_pixel_put(mapInfo->mlx.mlx, mapInfo->mlx.win, x, drawStart, 0xFF0000);
        drawStart++;
    }
}


      




//Test to understand
// void prepDDA(t_mapInfo *mapInfo, t_player *player)
// {
//     int x;
//     t_rayCamInfo rayInfo;

//     initRayInfo(&rayInfo, player);

//     x = 0;
//     while(x < mapInfo->screen.width)
//     {
//         rayInfo.cameraX = 2 * x / (double)mapInfo->screen.width - 1;
//         rayInfo.rayDirX = rayInfo.dirX + rayInfo.planeX * rayInfo.cameraX;
//         rayInfo.rayDirY = rayInfo.dirY + rayInfo.planeY * rayInfo.cameraX;
//         rayInfo.mapX = (int)rayInfo.posX;
//         rayInfo.mapY = (int)rayInfo.posY;
//         if(rayInfo.rayDirX == 0)
//             rayInfo.deltaDistX = 1e30;
//         else
//             rayInfo.deltaDistX = abs(1 / rayInfo.rayDirX);
//         if(rayInfo.rayDirY == 0)
//             rayInfo.deltaDistY = 1e30;
//         else
//             rayInfo.deltaDistY = abs(1 / rayInfo.rayDirY);
//         rayInfo.hit = 0;
//         if(rayInfo.rayDirX < 0)
//         {
//             rayInfo.stepX = -1;
//             rayInfo.sideDistX = (rayInfo.posX - rayInfo.mapX) * rayInfo.deltaDistX;
//         }
//         else
//         {
//             rayInfo.stepX = 1;
//             rayInfo.sideDistX = (rayInfo.mapX + 1.0 - rayInfo.posX) * rayInfo.deltaDistX;
//         }
//         if(rayInfo.rayDirY < 0)
//         {
//             rayInfo.stepY = -1;
//             rayInfo.sideDistY = (rayInfo.posY - rayInfo.mapY) * rayInfo.deltaDistY;
//         }
//         else
//         {
//             rayInfo.stepY = 1;
//             rayInfo.sideDistY = (rayInfo.mapY + 1.0 - rayInfo.posY) * rayInfo.deltaDistY;
//         }


//         //main loop
//         while(rayInfo.hit == 0)
//         {
//             if(rayInfo.sideDistX < rayInfo.sideDistY)
//             {
//                 rayInfo.sideDistX += rayInfo.deltaDistX;
//                 rayInfo.mapX += rayInfo.stepX;
//                 rayInfo.side = 0;
//             }
//             else
//             {
//                 rayInfo.sideDistY += rayInfo.deltaDistY;
//                 rayInfo.mapY += rayInfo.stepY;
//                 rayInfo.side = 1;
//             }
//             ft_printf("%c",mapInfo->map2D[rayInfo.mapY][rayInfo.mapX]);
//             if(mapInfo->map2D[rayInfo.mapY][rayInfo.mapX] == '1')
//                 rayInfo.hit = 1;
//         }

//         if(rayInfo.side == 0)
//             rayInfo.perpWallDist = rayInfo.sideDistX - rayInfo.deltaDistX;
//         else
//             rayInfo.perpWallDist = rayInfo.sideDistY - rayInfo.deltaDistY;


//         rayInfo.lineHeight = (int)mapInfo->screen.height / rayInfo.perpWallDist;

//         rayInfo.drawStart = -rayInfo.lineHeight / 2 + mapInfo->height / 2 + 100;
        
//         if(rayInfo.drawStart < 0)
//             rayInfo.drawStart = 0;
//         rayInfo.drawEnd = rayInfo.lineHeight / 2 + mapInfo->height / 2 + 100;
//         if(rayInfo.drawEnd >= mapInfo->height)
//             rayInfo.drawEnd = mapInfo->height - 1;
//         drawLine(mapInfo, x, rayInfo.drawStart, rayInfo.drawEnd);
//         x++;
//     }
// }