/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveHooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:21:09 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/08 19:54:35 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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
		if (mapInfo->map2d[(int)(rayinfo->pos_y + rayinfo->dir_y
				* 0.2)][(int)rayinfo->pos_x] != '1')
			mapInfo->player.pos_y += rayinfo->dir_y * 0.2;
		if (mapInfo->map2d[(int)rayinfo->pos_y][(int)(rayinfo->pos_x
			+ rayinfo->dir_x * 0.2)] != '1')
			mapInfo->player.pos_x += rayinfo->dir_x * 0.2;
		ray_casting(mapInfo);
	}
	if (key == XK_Down || key == XK_s)
	{
		if (mapInfo->map2d[(int)rayinfo->pos_y][(int)(rayinfo->pos_x
			- rayinfo->dir_x * 0.2)] != '1')
			mapInfo->player.pos_x -= rayinfo->dir_x * 0.2;
		if (mapInfo->map2d[(int)(rayinfo->pos_y - rayinfo->dir_y
				* 0.2)][(int)rayinfo->pos_x] != '1')
			mapInfo->player.pos_y -= rayinfo->dir_y * 0.2;
		ray_casting(mapInfo);
	}
}

int	move_mousehook_lr(int x, t_rayinfo *rayinfo, t_mapInfo *mI)
{
	double	move;

	if (x != SCREENWIDTH / 2)
	{
		move = (x - SCREENWIDTH / 2) * 0.0005;
		rayinfo->olddir_x = rayinfo->dir_x;
		rayinfo->dir_x = rayinfo->dir_x * cos(move) - rayinfo->dir_y
			* sin(move);
		rayinfo->dir_y = rayinfo->olddir_x * sin(move) + rayinfo->dir_y
			* cos(move);
		rayinfo->oldplane_x = rayinfo->plane_x;
		rayinfo->plane_x = rayinfo->plane_x * cos(move) - rayinfo->plane_y
			* sin(move);
		rayinfo->plane_y = rayinfo->oldplane_x * sin(move) + rayinfo->plane_y
			* cos(move);
		ray_casting(mI);
		mlx_mouse_move(mI->mlx.mlx, mI->mlx.win, SCREENWIDTH / 2, SCREENHEIGHT
			/ 2);
	}
	return (0);
}
