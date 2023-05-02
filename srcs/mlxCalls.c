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
		rayInfo->dirX = rayInfo->dirX * cos(-0.05) - rayInfo->dirY * sin(-0.05);
		rayInfo->dirY = rayInfo->oldDirX * sin(-0.05) + rayInfo->dirY * cos(-0.05);
		rayInfo->oldPlaneX = rayInfo->planeX;
		rayInfo->planeX = rayInfo->planeX * cos(-0.05) - rayInfo->planeY * sin(-0.05);
		rayInfo->planeY = rayInfo->oldPlaneX * sin(-0.05) + rayInfo->planeY * cos(-0.05);
		rayCasting(mapInfo);
	}
	if (key ==  XK_Right|| key == XK_d)
	{
		rayInfo->oldDirX = rayInfo->dirX;
		rayInfo->dirX = rayInfo->dirX * cos(0.05) - rayInfo->dirY * sin(0.05);
		rayInfo->dirY = rayInfo->oldDirX * sin(0.05) + rayInfo->dirY * cos(0.05);
		rayInfo->oldPlaneX = rayInfo->planeX;
		rayInfo->planeX = rayInfo->planeX * cos(0.05) - rayInfo->planeY * sin(0.05);
		rayInfo->planeY = rayInfo->oldPlaneX * sin(0.05) + rayInfo->planeY * cos(0.05);
		rayCasting(mapInfo);
	}
	if (key == XK_Up || key == XK_w)
    {
		if(mapInfo->map2D[(int)mapInfo->rayInfo.posY][(int)(mapInfo->rayInfo.posX + mapInfo->rayInfo.dirX * 0.3)] != '1')
			mapInfo->player.posX += mapInfo->rayInfo.dirX * 0.2;
		if(mapInfo->map2D[(int)(mapInfo->rayInfo.posY + mapInfo->rayInfo.dirY * 0.3)][(int)mapInfo->rayInfo.posX] != '1')
        	mapInfo->player.posY += mapInfo->rayInfo.dirY * 0.2;
		rayCasting(mapInfo);
    }
	if(key == XK_Down || key == XK_s)
    {   
		if(mapInfo->map2D[(int)mapInfo->rayInfo.posY][(int)(mapInfo->rayInfo.posX - mapInfo->rayInfo.dirX * 0.3)] != '1')
			mapInfo->player.posX -= mapInfo->rayInfo.dirX * 0.2;
		if(mapInfo->map2D[(int)(mapInfo->rayInfo.posY - mapInfo->rayInfo.dirY * 0.3)][(int)mapInfo->rayInfo.posX] != '1')
        	mapInfo->player.posY -= mapInfo->rayInfo.dirY * 0.2;
		rayCasting(mapInfo);
    }
	if (key == XK_Escape)
		freeExit(mapInfo);
	return (0);
}

void mlxLoop(t_mapInfo *mapInfo)
{
    mlx_hook(mapInfo->mlx.win, 2, 1L<<0, &move_hook, mapInfo);
	mlx_hook(mapInfo->mlx.win, 17, 0, &freeExit, mapInfo);
	mlx_loop(mapInfo->mlx.mlx);
}