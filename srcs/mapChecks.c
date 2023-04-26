#include "../includes/cub3d.h"

void validCharacters(t_mapInfo *mapInfo)
{
    t_index index;

    index.i = 0;
    while(index.i < mapInfo->height)
    {
        index.j = 0;
        while(index.j != '\0')
        {
            char cur = mapInfo->map2D[index.i][index.j];
            if(cur != '0' && cur != '1' && cur != 'N' 
                && cur != 'E' && cur != 'S' && cur != 'W' && cur != ' ')
                error("invChar", mapInfo);
            index.j++;
        }
        index.i++;
    }
}

void validMapExtention(char *mapName, t_mapInfo *mapInfo)
{
    int mapNameLenght = ft_strlen(mapName);
    if(mapNameLenght < 4 || ft_strncmp(&mapName[mapNameLenght - 4], ".cub", 4) != 0)
        error(".cub", mapInfo);
}

void wallTopBottom(t_mapInfo *mapInfo)
{
    t_index index;

    index.i = 0;
    while(mapInfo->map2D[0][index.i])
    {
        if(mapInfo->map2D[0][index.i] != '1' && mapInfo->map2D[0][index.i] != ' ')
            error("wall", mapInfo);
        index.i++;
    }
    index.i = 0;
    while(mapInfo->map2D[mapInfo->height - 1][index.i])
    {
        if(mapInfo->map2D[mapInfo->height - 1][index.i] != '1' && mapInfo->map2D[mapInfo->height - 1][index.i] != ' ')
            error("wall", mapInfo);
        index.i++;
    }
}

void wallCheck(t_mapInfo *mapInfo)
{
    char **map2D;
    t_index index;

    wallTopBottom(mapInfo);
    map2D = mapInfo->map2D;
    index.i = 1;
    while(index.i < mapInfo->height - 1)
    {
        index.j = 0;
        if(map2D[index.i][0] == '\0') // Check if theres a NL in the map
            error("wall", mapInfo);
        while(map2D[index.i][index.j])
        {
            if(map2D[index.i][index.j] == '0')
                wallCheckSurrounding(map2D, &index, mapInfo);
            index.j++;
        }
        index.i++;
    }
}

void wallCheckSurrounding(char **map2D, t_index *index, t_mapInfo *mapInfo)
{
    if(map2D[index->i][index->j] == '0' && (index->j == 0 || map2D[index->i][index->j + 1] == '\0')) //check if last or first in row
            error("wall", mapInfo);
    else if(map2D[index->i][index->j - 1] == ' ' || map2D[index->i][index->j + 1] == ' ')   //check if space is left or right next to a 0
            error("wall", mapInfo);
    else if(ft_strlen(map2D[index->i - 1]) < index->j  + 1 || ft_strlen(map2D[index->i + 1]) < index->j + 1) //check if there is nothing malloced above or below the 0
            error("wall", mapInfo);
    else if(map2D[index->i - 1][index->j]  == ' ' || map2D[index->i + 1][index->j]  == ' ') // check if below or above is a space
            error("wall", mapInfo);
}