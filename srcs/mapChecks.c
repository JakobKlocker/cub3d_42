#include "../includes/cub3d.h"

int validCharacters(t_mapInfo *mapInfo)
{
    t_index index;

    index.i = 0;
    index.j = 0;
    while(index.i < mapInfo->height)
    {
        while(index.j < mapInfo->width)
        {
            char cur = mapInfo->map[index.i][index.j];
            if(cur != '0' && cur != '1' && cur != 'N' 
                && cur != 'E' && cur != 'S' && cur != 'W')
                return 0;
            index.j++;
        }
        index.i++;
        index.j = 0;
    }
    return 1;
}

int validMapExtention(t_mapInfo *mapInfo)
{
    int mapNameLenght = ft_strlen(mapInfo->mapName);
    if(mapNameLenght < 4 || ft_strcmp(mapInfo->mapName[mapNameLenght - 4], ".ber") != 0)
        return 0;
    return 1;
}