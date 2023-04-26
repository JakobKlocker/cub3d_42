#include "../includes/cub3d.h"

void colorCheck(t_mapInfo *mapInfo)
{
    t_index index;
    
    index.i = 0;
    index.j = 0;
    while(mapInfo->CColor[index.i])
        index.i++;
    while(mapInfo->FColor[index.j])
        index.j++;
    if(index.i != 3 || index.j != 3)
        error("RGB", mapInfo);
    index.i = 0;
    while(index.i < 3)
    {
        isRGB(mapInfo->CColor[index.i], mapInfo);
        isRGB(mapInfo->FColor[index.i], mapInfo);
        index.i++;
    }
}

void isRGB(char *str, t_mapInfo *mapInfo)
{
    int i = 0;

    if(ft_strlen(str) > 3)
        error("RGB", mapInfo);
    while(str[i])
    {
        if(!ft_isdigit(str[i]))
            error("RGB", mapInfo);
        i++;
    }
    i = ft_atoi(str);
    if(i > 255 || i < 0)
        error("RGB", mapInfo);
}

void allMapChecks(t_mapInfo *mapInfo)
{
    wallCheck(mapInfo);
    colorCheck(mapInfo);
    validCharacters(mapInfo);
}
