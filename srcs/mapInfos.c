#include "../includes/cub3d.h"

int openMap(char *mapName)
{
    int Fd = 0;
    Fd = open(mapName, O_RDONLY);
    if(Fd == 0)
    {
        ft_printf("Couldn't open File\n");
        exit(1);
    }
    return Fd;
}

int getMapInfo(t_mapInfo *mapInfo)
{
    
}

void initMapInfo(t_mapInfo *mapInfo, char *mapName)
{
    mapInfo->mapName = mapName;
    mapInfo->Fd = 0;
    mapInfo->height = 0;;
    mapInfo->map  = NULL;
    mapInfo->NTexture = NULL;;
    mapInfo->ETexture = NULL;;
    mapInfo->STexture = NULL;;
    mapInfo->WTexture = NULL;;
    mapInfo->FColor = NULL;;
    mapInfo->CColor = NULL;;
}