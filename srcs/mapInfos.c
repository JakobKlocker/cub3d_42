#include "../includes/cub3d.h"

int openMap(char *mapName)
{
    int Fd;
    Fd = open(mapName, O_RDONLY);
    if(Fd == -1)
    {
        ft_printf("Couldn't open File\n");
        exit(1);
    }
    return Fd;
}

// Change Strncmp to strcmp to not overflow if word is below 3 or 2
void addMapInfos(char **split, t_mapInfo *mapInfo)
{
    t_index index;

    index.i = 0;
    while(split[index.i])
        index.i++;
    if(index.i != 2)
    {
        //free, error & exit here
    }
    if(strncmp(split[0], "NO\0", 3) == 0)
        mapInfo->NTexture = ft_strdup(split[1]);
    else if(strncmp(split[0], "SO\0", 3) == 0)
        mapInfo->STexture = ft_strdup(split[1]);
    else if(strncmp(split[0], "WE\0", 3) == 0)
        mapInfo->WTexture = ft_strdup(split[1]);
    else if(strncmp(split[0], "EA\0", 3) == 0)
        mapInfo->ETexture = ft_strdup(split[1]);
    else if(strncmp(split[0], "F\0", 2) == 0)
        mapInfo->FColor = ft_strdup(split[1]);
    else if(strncmp(split[0], "C\0", 2) == 0)
        mapInfo->CColor = ft_strdup(split[1]);
    else
    {
        ft_printf("Error, free & exit here\n");
        exit(1);
    }
    //free split here
}

void addMap(t_mapInfo *mapInfo)
{

}

int getMapInfo(t_mapInfo *mapInfo)
{
    t_index index;
    char **split;

    index.i = 0;
    index.j = 0;
    char *line = get_next_line(mapInfo->Fd);
    while(line && index.j < 6)
    {
        split = ft_split(line, ' ');
        if(split)
        {
            index.j++;
            addMapInfos(split, mapInfo);
        }
        line = get_next_line(mapInfo->Fd);
    }
    while(line && line[0] == '\0')
        line = get_next_line(mapInfo->Fd);
    addMap(mapInfo);
}

void initMapInfo(t_mapInfo *mapInfo, char *mapName)
{
    mapInfo->mapName = mapName;
    mapInfo->Fd = 0;
    mapInfo->height = 0;
    mapInfo->map  = NULL;
    mapInfo->NTexture = NULL;
    mapInfo->ETexture = NULL;
    mapInfo->STexture = NULL;
    mapInfo->WTexture = NULL;
    mapInfo->FColor = NULL;
    mapInfo->CColor = NULL;
}