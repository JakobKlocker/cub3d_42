#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/ft_printf.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define ScreenHeight 720
# define ScreenWidth 1280

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_time
{
	double		time;
	double		oldTime;
}				t_time;

typedef struct s_mimap
{
	int			x;
	int			y;
	int			a_x;
	int			a_y;
	int			x_i;
	int			y_i;
	int			s_w;
	int			s_h;
	int			color_w;
	int			color_g;
	int			color_r;
	int			color;
	int			u_size;
	int			offset_x;
	int			offset_y;
	int			player_drawn;
	t_img		img;
}				t_mimap;

typedef struct s_player
{
	double		posX;
	double		posY;
	char		spawnDir;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
}				t_player;

typedef struct s_screen
{
	int			width;
	int			height;
}				t_screen;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_rayInfo
{
	double		posX;
	double		posY;
	double		camera;
	double		dirX;
	double		dirY;
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	double		planeX;
	double		planeY;
	double		oldDirX;
	double		oldPlaneX;
	int			mapX;
	int			mapY;
	int			hit;
	int			side;
	int			stepX;
	int			stepY;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
}				t_rayInfo;

typedef struct s_mapInfo
{
	int			Fd;
	int			height;
	char		*map1D;
	char		**map2D;
	char		*mapName;
	char		*NTexture;
	char		*ETexture;
	char		*STexture;
	char		*WTexture;
	char		**FColor;
	char		**CColor;
	t_screen	screen;
	t_player	player;
	t_rayInfo	rayInfo;
	t_mlx		mlx;
	t_img		img;
	t_mimap		minimap;
}				t_mapInfo;

typedef struct s_index
{
	int			i;
	int			j;
	int			k;
}				t_index;

//mallocMap.c
char			*malloc1D(t_mapInfo *mapInfo);
char			**malloc2D(t_mapInfo *mapInfo);
void			copy2DMap(t_mapInfo *mapInfo);
int				getLenTillChar(char *line, char c);
void			print2DMap(t_mapInfo *mapInfo);

//mapChecks.c
void			validCharacters(t_mapInfo *mapInfo);
void			validMapExtention(char *mapName, t_mapInfo *mapInfo);
void			wallTopBottom(t_mapInfo *mapInfo);
void			wallCheck(t_mapInfo *mapInfo);
void			wallCheckSurrounding(char **map2D, t_index *index,
					t_mapInfo *mapInfo);

//mapChecks_1.c
void			colorCheck(t_mapInfo *mapInfo);
void			isRGB(char *str, t_mapInfo *mapInfo);
void			allMapChecks(t_mapInfo *mapInfo);

//mapInfos.c
int				openMap(char *mapName, t_mapInfo *mapInfo);
void			addMapInfos(char **split, t_mapInfo *mapInfo);
void			addMap(t_mapInfo *mapInfo);
int				getMapInfo(t_mapInfo *mapInfo);
void			initMapInfo(t_mapInfo *mapInfo, char *mapName);

//mapInfos_1.c
void			getPlayerCordinates(t_mapInfo *mapInfo, t_player *player);

//mlxCalls.c
void			openWindow(t_mapInfo *mapInfo);
void			mlxLoop(t_mapInfo *mapInfo);

//rayCasting.C
void			rayCasting(t_mapInfo *mapInfo);
void			calcStep(t_rayInfo *rayInfo);
void			calcDist(t_mapInfo *mapInfo, t_player *player,
					t_rayInfo *rayInfo);
void			DDAExec(t_mapInfo *mapInfo, t_player *player,
					t_rayInfo *rayInfo);

//rayCasting_1.c
void			initRayInfo(t_rayInfo *rayInfo, t_player *player,
					t_mapInfo *mapInfo);
void			initRayInfoLoop(int x, t_rayInfo *rayInfo, t_player *player,
					t_mapInfo *mapInfo);
void			drawLine(t_mapInfo *mapInfo, int x, int drawStart, int drawEnd);
void			img_pxl_put(t_img *img, int x, int y, int color);

//createBG.c
int				encodeRGB(unsigned char red, unsigned char green,
					unsigned char blue);
void			createFloor(t_mapInfo *mapInfo);
void			createSky(t_mapInfo *mapInfo);
void			createBG(t_mapInfo *mapInfo);

//errorFree.c
void			free2D(char **str);
void			error(char *error, t_mapInfo *mapInfo);
void			freeMlx(t_mapInfo *mapInfo);
void			freeExit(t_mapInfo *mapInfo);

/*
    minimap.c
*/
void			ft_minimapBG(t_mapInfo *mapInfo, t_mimap *m);

#endif