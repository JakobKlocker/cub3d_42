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
    char *map1D;
    char **map2D;
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

//mallocMap.c
char *malloc1D(t_mapInfo *mapInfo);
char **malloc2D(t_mapInfo *mapInfo);
void copy2DMap(t_mapInfo *mapInfo);
int getLenTillChar(char* line, char c);
void print2DMap(t_mapInfo *mapInfo);

//mapChecks.c
int validCharacters(t_mapInfo *mapInfo);
void validMapExtention(char *mapName);

//mapInfos.c
int openMap(char *mapName);
void initMapInfo(t_mapInfo *info, char *mapName);
int getMapInfo(t_mapInfo *mapInfo);
void addMapInfos(char **split, t_mapInfo *mapInfo);
int getMapInfo(t_mapInfo *mapInfo);


#endif