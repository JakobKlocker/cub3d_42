#include "../includes/cub3d.h"

int encodeRGB(unsigned char red, unsigned char green, unsigned char blue)
{
    return (red << 16 | green << 8 | blue);
}

void createSky(t_mapInfo *mapInfo)
{
    t_index index;
    index.i = 0;
    int color;
    color = encodeRGB(ft_atoi(mapInfo->FColor[0]), ft_atoi(mapInfo->FColor[1]), ft_atoi(mapInfo->FColor[2]));
    while(index.i < mapInfo->screen.height / 2)
    {
        index.j = 0;
        while(index.j < mapInfo->screen.width)
        {
            mlx_pixel_put(mapInfo->mlx.mlx, mapInfo->mlx.win, index.j, index.i, color);
            index.j++;
        }
        index.i++;
    }
}

void createFloor(t_mapInfo *mapInfo)
{
    t_index index;
    index.i = 0;
    int color;
    color = encodeRGB(ft_atoi(mapInfo->CColor[0]), ft_atoi(mapInfo->CColor[1]), ft_atoi(mapInfo->CColor[2]));
    index.i = mapInfo->screen.height / 2;
    while(index.i < mapInfo->screen.height)
    {
        index.j = 0;
        while(index.j < mapInfo->screen.width)
        {
            mlx_pixel_put(mapInfo->mlx.mlx, mapInfo->mlx.win, index.j, index.i, color);
            index.j++;
        }
        index.i++;
    }
}

void createBG(t_mapInfo *mapInfo)
{
    createSky(mapInfo);
    createFloor(mapInfo);
}