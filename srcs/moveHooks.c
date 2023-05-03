#include "../includes/cub3d.h"

void	move_hook_right(int key, t_rayinfo *rayinfo, t_mapInfo *mapInfo)
{
	if (key == XK_Right || key == XK_d)
	{
		rayinfo->olddir_x = rayinfo->dir_x;
		rayinfo->dir_x = rayinfo->dir_x * cos(0.05) - rayinfo->dir_y
			* sin(0.05);
		rayinfo->dir_y = rayinfo->olddir_x * sin(0.05) + rayinfo->dir_y
			* cos(0.05);
		rayinfo->oldplane_x = rayinfo->plane_x;
		rayinfo->plane_x = rayinfo->plane_x * cos(0.05) - rayinfo->plane_y
			* sin(0.05);
		rayinfo->plane_y = rayinfo->oldplane_x * sin(0.05) + rayinfo->plane_y
			* cos(0.05);
		ray_casting(mapInfo);
	}
}

void	move_hook_left(int key, t_rayinfo *rayinfo, t_mapInfo *mapInfo)
{
	if (key == XK_Left || key == XK_a)
	{
		rayinfo->olddir_x = rayinfo->dir_x;
		rayinfo->dir_x = rayinfo->dir_x * cos(-0.05) - rayinfo->dir_y
			* sin(-0.05);
		rayinfo->dir_y = rayinfo->olddir_x * sin(-0.05) + rayinfo->dir_y
			* cos(-0.05);
		rayinfo->oldplane_x = rayinfo->plane_x;
		rayinfo->plane_x = rayinfo->plane_x * cos(-0.05) - rayinfo->plane_y
			* sin(-0.05);
		rayinfo->plane_y = rayinfo->oldplane_x * sin(-0.05) + rayinfo->plane_y
			* cos(-0.05);
		ray_casting(mapInfo);
	}
}

void	move_hook_updown(int key, t_rayinfo *rayinfo, t_mapInfo *mapInfo)
{
	if (key == XK_Up || key == XK_w)
	{
		if (mapInfo->map2d[(int)rayinfo->pos_y][(int)(rayinfo->pos_x
			+ rayinfo->dir_x * 0.3)] != '1')
			mapInfo->player.pos_x += rayinfo->dir_x * 0.2;
		if (mapInfo->map2d[(int)(rayinfo->pos_y + rayinfo->dir_y
				* 0.3)][(int)rayinfo->pos_x] != '1')
			mapInfo->player.pos_y += rayinfo->dir_y * 0.2;
		ray_casting(mapInfo);
	}
	if (key == XK_Down || key == XK_s)
	{
		if (mapInfo->map2d[(int)rayinfo->pos_y][(int)(rayinfo->pos_x
			- rayinfo->dir_x * 0.3)] != '1')
			mapInfo->player.pos_x -= rayinfo->dir_x * 0.2;
		if (mapInfo->map2d[(int)(rayinfo->pos_y - rayinfo->dir_y
				* 0.3)][(int)rayinfo->pos_x] != '1')
			mapInfo->player.pos_y -= rayinfo->dir_y * 0.2;
		ray_casting(mapInfo);
	}
}
