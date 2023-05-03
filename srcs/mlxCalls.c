#include "../includes/cub3d.h"

void	open_window(t_mapInfo *mapInfo)
{
	mapInfo->screen.height = SCREENHEIGHT;
	mapInfo->screen.width = SCREENWIDTH;
	mapInfo->mlx.mlx = mlx_init();
	if (!mapInfo->mlx.mlx)
		error("mlx", mapInfo);
	mapInfo->mlx.win = mlx_new_window(mapInfo->mlx.mlx, mapInfo->screen.width,
			mapInfo->screen.height, "cube3d plz");
	if (!mapInfo->mlx.win)
		error("mlx", mapInfo);
	mapInfo->img.img = mlx_new_image(mapInfo->mlx.mlx, SCREENWIDTH,
			SCREENHEIGHT);
	mapInfo->img.addr = mlx_get_data_addr(mapInfo->img.img, &mapInfo->img.bpp,
			&mapInfo->img.size_line, &mapInfo->img.endian);
}

int	move_hook(int key, t_mapInfo *mapInfo)
{
	t_rayinfo	*rayinfo;

	rayinfo = &mapInfo->rayinfo;
	move_hook_left(key, rayinfo, mapInfo);
	move_hook_right(key, rayinfo, mapInfo);
	move_hook_updown(key, rayinfo, mapInfo);
	if (key == XK_Escape)
		free_exit(mapInfo);
	return (0);
}

void	mlx_loop_own(t_mapInfo *mapInfo)
{
	mlx_hook(mapInfo->mlx.win, 2, 1L << 0, &move_hook, mapInfo);
	mlx_hook(mapInfo->mlx.win, 17, 0, &free_exit, mapInfo);
	mlx_loop(mapInfo->mlx.mlx);
}
