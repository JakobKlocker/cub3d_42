#include "../includes/cub3d.h"

void openWindow(t_mapInfo *mapInfo)
{
    mapInfo->screen.height = ScreenHeight;
    mapInfo->screen.width = ScreenWidth;
	mapInfo->mlx.mlx = mlx_init();
    if(!mapInfo->mlx.mlx)
        error("mlx", mapInfo);
	mapInfo->mlx.win = mlx_new_window(mapInfo->mlx.mlx, mapInfo->screen.width, mapInfo->screen.height, "cube3d plz");
    if(!mapInfo->mlx.win)
        error("mlx", mapInfo);
	mapInfo->img.img = mlx_new_image(mapInfo->mlx.mlx, ScreenWidth, ScreenHeight);
	mapInfo->img.addr = mlx_get_data_addr(mapInfo->img.img, &mapInfo->img.bpp, &mapInfo->img.size_line,
								&mapInfo->img.endian);
}

int	move_hook(int key, t_mapInfo *mapInfo)
{
	t_rayInfo *rayInfo = &mapInfo->rayInfo;
	if (key == XK_Left || key == XK_a)
	{
		rayInfo->oldDirX = rayInfo->dirX;
		rayInfo->dirX = rayInfo->dirX * cos(-0.1) - rayInfo->dirY * sin(-0.1);
		rayInfo->dirY = rayInfo->oldDirX * sin(-0.1) + rayInfo->dirY * cos(-0.1);
		rayInfo->oldPlaneX = rayInfo->planeX;
		rayInfo->planeX = rayInfo->planeX * cos(-0.1) - rayInfo->planeY * sin(-0.1);
		rayInfo->planeY = rayInfo->oldPlaneX * sin(-0.1) + rayInfo->planeY * cos(-0.1);
		rayCasting(mapInfo);
	}
	if (key ==  XK_Right|| key == XK_d)
	{
		rayInfo->oldDirX = rayInfo->dirX;
		rayInfo->dirX = rayInfo->dirX * cos(0.1) - rayInfo->dirY * sin(0.1);
		rayInfo->dirY = rayInfo->oldDirX * sin(0.1) + rayInfo->dirY * cos(0.1);
		rayInfo->oldPlaneX = rayInfo->planeX;
		rayInfo->planeX = rayInfo->planeX * cos(0.1) - rayInfo->planeY * sin(0.1);
		rayInfo->planeY = rayInfo->oldPlaneX * sin(0.1) + rayInfo->planeY * cos(0.1);
		rayCasting(mapInfo);
	}
	if (key == XK_Up || key == XK_w)
    {
		mapInfo->player.posX += mapInfo->rayInfo.dirX * 0.1;
        mapInfo->player.posY += mapInfo->rayInfo.dirY * 0.1;
		rayCasting(mapInfo);
    }
	if(key == XK_Down || key == XK_s)
    {   
		mapInfo->player.posX -= mapInfo->rayInfo.dirX * 0.1;
        mapInfo->player.posY -= mapInfo->rayInfo.dirY * 0.1;
		rayCasting(mapInfo);
    }
	// if (key == XK_Escape)
	// 	close_game(map_info);
	return (0);
}

void mlxLoop(t_mapInfo *mapInfo)
{
    mlx_key_hook(mapInfo->mlx.win, &move_hook, mapInfo);
	mlx_loop(mapInfo->mlx.mlx);
}