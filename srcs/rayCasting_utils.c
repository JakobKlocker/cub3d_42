#include "../includes/cub3d.h"

void initRayInfo(t_rayInfo *rayInfo, t_player *player, t_mapInfo *mapInfo)
{
    rayInfo->dirX = 1;
    rayInfo->dirY = 0;
    rayInfo->planeX = 0;
    rayInfo->planeY = 0.66;
}

void initRayInfoLoop(int x, t_rayInfo *rayInfo, t_player *player, t_mapInfo *mapInfo)
{
    rayInfo->posX = player->posX + 0.5;
    rayInfo->posY = player->posY + 0.5;
    rayInfo->camera = 2 * x / (double)mapInfo->screen.width - 1;
    rayInfo->rayDirX = rayInfo->dirX + rayInfo->planeX * rayInfo->camera;
    rayInfo->rayDirY = rayInfo->dirY + rayInfo->planeY * rayInfo->camera;
    rayInfo->mapX = (int)rayInfo->posX;
    rayInfo->mapY = (int)rayInfo->posY;
    if(rayInfo->rayDirX == 0)
        rayInfo->deltaDistX = 1e30;
    else
        rayInfo->deltaDistX = fabs(1 / rayInfo->rayDirX);
    if(rayInfo->rayDirY == 0)
        rayInfo->deltaDistY = 1e30;
    else
        rayInfo->deltaDistY = fabs(1 / rayInfo->rayDirY);
    rayInfo->hit = 0;
}

void drawLine(t_mapInfo *mapInfo, int x, int drawStart, int drawEnd)
{
    while(drawStart != drawEnd)
    {
        img_pxl_put(&mapInfo->img, x, drawStart, 0xAA0000);
        drawStart++;
    }
}

void    img_pxl_put(t_img *img, int x, int y, int color)
{
    char    *pxl;

    if (((x >= 0) && (y >= 0)) && ((x < ScreenWidth) && (y < ScreenHeight)))
    {
        pxl = img->addr + (y * img->size_line + x * (img->bpp / 8));
        *(int *)pxl = color;
    }
}