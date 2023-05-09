/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxCalls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:21:06 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/09 12:13:16 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

/*
	mlx_mouse_hide(mapInfo->mlx.mlx, mapInfo->mlx.win);
*/

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

unsigned long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	my_mouse_hook(int x, int y, t_mapInfo *mI)
{
	t_rayinfo	*rayinfo;

	mI->current = get_current_time();
	if (mI->current - mI->previous < 10)
		return (0);
	mI->previous = mI->current;
	rayinfo = &mI->rayinfo;
	move_mousehook_lr(x, rayinfo, mI);
	return (0);
}

void	mlx_loop_own(t_mapInfo *mapInfo)
{
	mlx_hook(mapInfo->mlx.win, 2, 1L << 0, &move_hook, mapInfo);
	mlx_hook(mapInfo->mlx.win, 17, 0, &free_exit, mapInfo);
	mlx_hook(mapInfo->mlx.win, MotionNotify, PointerMotionMask, &my_mouse_hook,
		mapInfo);
	mlx_loop(mapInfo->mlx.mlx);
}
