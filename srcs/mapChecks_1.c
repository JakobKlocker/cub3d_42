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
        ft_printf("colorChecks Error and free");
    index.i = 0;
    while(index.i < 3)
    {
        isRGB(mapInfo->CColor[index.i]);
        isRGB(mapInfo->FColor[index.i]);
        index.i++;
    }
}

void isRGB(char *str)
{
    int i = 0;

    if(ft_strlen(str) > 3)
        ft_printf("isRGB Error and free");
    while(str[i])
    {
        if(!ft_isdigit(str[i]))
            ft_printf("isRGB Error and free");
        i++;
    }
    i = ft_atoi(str);
    if(i > 255 || i < 0)
        ft_printf("isRGB Error and free");
}

void allMapChecks(t_mapInfo *mapInfo)
{
    wallCheck(mapInfo);
    colorCheck(mapInfo);
    validCharacters(mapInfo);
}
