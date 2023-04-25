#ifndef CUB3D_H
#define CUB3D_H

#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"
#include "../libft/ft_printf.h"
#include "../libft/get_next_line_bonus.h"
#include "mlx.h"

#define ScreenHeight 1240
#define ScreenWidth 1080


typedef struct s_time
{
    double time;
    double oldTime;
} t_time;

typedef struct s_player{
    double posX;
    double posY;
    char spawnDir;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
} t_player;

typedef struct s_screen
{
    int width;
    int height;
} t_screen;

typedef struct s_mlx{
    void *mlx;
    void *win;
} t_mlx;

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
    char **FColor;
    char **CColor;
    t_screen screen;
    t_player player;
    t_mlx mlx;
} t_mapInfo;

typedef struct s_index{
    int i;
    int j;
    int k;
} t_index;

typedef struct s_rayCamInfo
{
    double posX;
    double posY;
    double camera;
    double dirX;
    double dirY;
    double rayDirX;
    double rayDirY;
    double sideDistX;
    double sideDistY;
    double deltaDistX;
    double deltaDistY;
    double perpWallDist;
    double planeX;
    double planeY;
    int mapX;
    int mapY;
    int hit;
    int side;
    int stepX;
    int stepY;
    int lineHeight;
    int drawStart;
    int drawEnd;
} t_rayCamInfo;

//mallocMap.c
char *malloc1D(t_mapInfo *mapInfo);
char **malloc2D(t_mapInfo *mapInfo);
void copy2DMap(t_mapInfo *mapInfo);
int getLenTillChar(char* line, char c);
void print2DMap(t_mapInfo *mapInfo);

//mapChecks.c
void validCharacters(t_mapInfo *mapInfo);
void validMapExtention(char *mapName);
void wallTopBottom(t_mapInfo *mapInfo);
void wallCheck(t_mapInfo *mapInfo);
void wallCheckSurrounding(char **map2D, t_index *index);

//mapChecks_1.c
void colorCheck(t_mapInfo *mapInfo);
void isRGB(char *str);
void allMapChecks(t_mapInfo *mapInfo);

//mapInfos.c
int openMap(char *mapName);
void addMapInfos(char **split, t_mapInfo *mapInfo);
void addMap(t_mapInfo *mapInfo);
int getMapInfo(t_mapInfo *mapInfo);
void initMapInfo(t_mapInfo *mapInfo, char *mapName);

//mapInfos_1.c
void getPlayerCordinates(t_mapInfo *mapInfo, t_player *player);

//mlxCalls.c
void openWindow(t_mapInfo *mapInfo);

//rayCasting tmp
void initRayInfo(int x, t_rayCamInfo *rayInfo, t_player *player, t_mapInfo *mapInfo);
void prepDDA(t_mapInfo *mapInfo, t_player *player);
void drawLine(t_mapInfo *mapInfo, int x, int drawStart, int drawEnd);


#endif