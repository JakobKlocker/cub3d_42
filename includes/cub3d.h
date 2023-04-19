#ifndef CUB3D_H
#define CUB3D_H

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"
#include "../libft/ft_printf.h"
#include "../libft/get_next_line_bonus.h"

typedef struct s_mapInfo{
    int Fd;
    int height;
    char **map;
    char *mapName;
    char *NTexture;
    char *ETexture;
    char *STexture;
    char *WTexture;
    char *FColor;
    char *CColor;

} t_mapInfo;

typedef struct s_index{
    int i;
    int j;
    int k;
} t_index;

//mapChecks.c
int validCharacters(t_mapInfo *mapInfo);
int validMapExtention(char *mapName);

//mapInfos.c
int openMap(char *mapName);
void initMapInfo(t_mapInfo *info, char *mapName);

#endif