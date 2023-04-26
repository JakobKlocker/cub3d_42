#include "../includes/cub3d.h"

void openWindow(t_mapInfo *mapInfo)
{
    mapInfo->screen.height = 1080;
    mapInfo->screen.width = 1240;
	mapInfo->mlx.mlx = mlx_init();
    if(!mapInfo->mlx.mlx)
        error("mlx", mapInfo);
	mapInfo->mlx.win = mlx_new_window(mapInfo->mlx.mlx, mapInfo->screen.width, mapInfo->screen.height, "cube3d plz");
    if(!mapInfo->mlx.win)
        error("mlx", mapInfo);
}

// int	move_hook(int key, t_map *map_info)
// {
// 	if (key == XK_Right || key == XK_d)
// 		move_right(map_info);
// 	if (key == XK_Left || key == XK_a)
// 		move_left(map_info);
// 	if (key == XK_Up || key == XK_w)
// 		move_up(map_info);
// 	if (key == XK_Down || key == XK_s)
// 		move_down(map_info);
// 	if (key == XK_Escape)
// 		close_game(map_info);
// 	return (0);
// }

