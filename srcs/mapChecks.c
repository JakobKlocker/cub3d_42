#include "../includes/cub3d.h"

int validCharacters(t_mapInfo *mapInfo)
{
    t_index index;

    index.i = 0;
    while(index.i < mapInfo->height)
    {
        index.j = 0;
        while(index.j != '\0')
        {
            char cur = mapInfo->map[index.i][index.j];
            if(cur != '0' && cur != '1' && cur != 'N' 
                && cur != 'E' && cur != 'S' && cur != 'W' && cur != ' ')
                return 0;
            index.j++;
        }
        index.i++;
    }
    return 1;
}

void validMapExtention(char *mapName)
{
    int mapNameLenght = ft_strlen(mapName);
    if(mapNameLenght < 4 || ft_strncmp(&mapName[mapNameLenght - 4], ".cub", 4) != 0)
    {
        ft_printf("Map name invalid, must end with .cub\n");
        exit(1);
    }
}
