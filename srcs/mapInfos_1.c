#include "../includes/cub3d.h"

void getPlayerCordinates(t_mapInfo *mapInfo, t_player *player)
{
    t_index index;
    index.i = 0;
    index.k = 0;
    while(index.i < mapInfo->height)
    {
        index.j = 0;
        while(mapInfo->map2D[index.i][index.j])
        {
            char c = mapInfo->map2D[index.i][index.j];
            if(c == 'N' || c == 'E' || c == 'S' || c == 'W')
            {
                if(index.k != 0)
                    error("invChar", mapInfo);
                player->posY = index.i;
                player->posX = index.j;
                player->spawnDir = c;
                index.k++;
            }
            index.j++;
        }
        index.i++;
    }
}

void setSpawnDir(t_player *player, t_rayInfo *rayInfo)
{
    rayInfo->dirX = 0;
    rayInfo->dirY = 0;
    rayInfo->planeX = 0;
    rayInfo->planeY = 0;
    if(player->spawnDir == 'N')
    {
        rayInfo->dirY = -1;
        rayInfo->planeX = 0.66;
    }
    else if(player->spawnDir == 'S')
    {
        rayInfo->dirY = 1;
        rayInfo->planeX = -0.66;
    }
    else if(player->spawnDir == 'E')
    {
        rayInfo->dirX = 1;
        rayInfo->planeY = 0.66;
    }
    else if(player->spawnDir == 'W')
    {
        rayInfo->dirX = -1; //player->dirX;
        rayInfo->planeY = -0.66;
    }
}