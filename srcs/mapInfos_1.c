#include "../includes/cub3d.h"

void getPlayerCordinates(t_mapInfo *mapInfo, t_player *player)
{
    t_index index;
    index.i = 0;
    while(index.i < mapInfo->height)
    {
        index.j = 0;
        while(mapInfo->map2D[index.i][index.j])
        {
            char c = mapInfo->map2D[index.i][index.j];
            if(c == 'N' || c == 'O' || c == 'S' || c == 'W')
            {
                player->posY = index.i;
                player->posX = index.j;
                player->spawnDir = c;
                return;
            }
            index.j++;
        }
        index.i++;
    }
}
