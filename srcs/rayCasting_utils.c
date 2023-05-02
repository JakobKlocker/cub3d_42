#include "../includes/cub3d.h"

// void initRayInfo(t_rayInfo *rayInfo, t_player *player, t_mapInfo *mapInfo)
// {
//     //setSpawnDir(player);
//     rayInfo->dirX = -1; //player->dirX;
//     rayInfo->dirY = 0; //player->dirY;
//     rayInfo->planeX = 0;
//     rayInfo->planeY = -0.66;
// }

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

t_texture* selectTexture(t_mapInfo *mapInfo, t_rayInfo *rayInfo)
{
    if(rayInfo->side == 1 &&  rayInfo->rayDirY < 0) 
        return (&mapInfo->N);
    else if(rayInfo->side == 1 &&  rayInfo->rayDirY > 0)
        return (&mapInfo->S);
    else if(rayInfo->side == 0 &&  rayInfo->rayDirX < 0)
        return (&mapInfo->W);
    else
        return (&mapInfo->E);
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