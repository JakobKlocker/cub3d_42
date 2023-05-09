/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:21:11 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/08 19:34:34 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	init_ray_info_loop(int x, t_rayinfo *rayinfo, t_player *player,
		t_mapInfo *mapInfo)
{
	rayinfo->pos_x = player->pos_x + 0.5;
	rayinfo->pos_y = player->pos_y + 0.5;
	rayinfo->camera = 2 * x / (double)mapInfo->screen.width - 1;
	rayinfo->raydir_x = rayinfo->dir_x + rayinfo->plane_x * rayinfo->camera;
	rayinfo->raydir_y = rayinfo->dir_y + rayinfo->plane_y * rayinfo->camera;
	rayinfo->mapx = (int)rayinfo->pos_x;
	rayinfo->mapy = (int)rayinfo->pos_y;
	if (rayinfo->raydir_x == 0)
		rayinfo->deltadistx = 1e30;
	else
		rayinfo->deltadistx = fabs(1 / rayinfo->raydir_x);
	if (rayinfo->raydir_y == 0)
		rayinfo->deltadisty = 1e30;
	else
		rayinfo->deltadisty = fabs(1 / rayinfo->raydir_y);
	rayinfo->hit = 0;
}

t_texture	*select_texture(t_mapInfo *mapInfo, t_rayinfo *rayinfo)
{
	if (rayinfo->side == 1 && rayinfo->raydir_y < 0)
		return (&mapInfo->n);
	else if (rayinfo->side == 1 && rayinfo->raydir_y > 0)
		return (&mapInfo->s);
	else if (rayinfo->side == 0 && rayinfo->raydir_x < 0)
		return (&mapInfo->w);
	else
		return (&mapInfo->e);
}

void	img_pxl_put(t_img *img, int x, int y, int color)
{
	char	*pxl;

	if (((x >= 0) && (y >= 0)) && ((x < SCREENWIDTH) && (y < SCREENHEIGHT)))
	{
		pxl = img->addr + (y * img->size_line + x * (img->bpp / 8));
		*(int *)pxl = color;
	}
}
