/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:20:14 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/08 14:40:23 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray_casting(t_mapInfo *mapInfo)
{
	int	x;

	create_bg(mapInfo);
	x = 0;
	while (x < mapInfo->screen.width)
	{
		init_ray_info_loop(x, &mapInfo->rayinfo, &mapInfo->player, mapInfo);
		calc_step(&mapInfo->rayinfo);
		dda_exec(mapInfo, &mapInfo->player, &mapInfo->rayinfo);
		calc_dist(mapInfo, &mapInfo->player, &mapInfo->rayinfo);
		calc_text(mapInfo, &mapInfo->rayinfo, x);
		x++;
	}
	mlx_put_image_to_window(mapInfo->mlx.mlx, mapInfo->mlx.win,
		mapInfo->img.img, 0, 0);
}

void	calc_step(t_rayinfo *rayinfo)
{
	if (rayinfo->raydir_x < 0)
	{
		rayinfo->stepx = -1;
		rayinfo->sidedistx = (rayinfo->pos_x - rayinfo->mapx)
			* rayinfo->deltadistx;
	}
	else
	{
		rayinfo->stepx = 1;
		rayinfo->sidedistx = (rayinfo->mapx + 1.0 - rayinfo->pos_x)
			* rayinfo->deltadistx;
	}
	if (rayinfo->raydir_y < 0)
	{
		rayinfo->stepy = -1;
		rayinfo->sidedisty = (rayinfo->pos_y - rayinfo->mapy)
			* rayinfo->deltadisty;
	}
	else
	{
		rayinfo->stepy = 1;
		rayinfo->sidedisty = (rayinfo->mapy + 1.0 - rayinfo->pos_y)
			* rayinfo->deltadisty;
	}
}

void	calc_dist(t_mapInfo *mapInfo, t_player *player, t_rayinfo *rayinfo)
{
	if (rayinfo->side == 0)
		rayinfo->perpwalldist = rayinfo->sidedistx - rayinfo->deltadistx;
	else
		rayinfo->perpwalldist = rayinfo->sidedisty - rayinfo->deltadisty;
	if (rayinfo->perpwalldist == 0)
		rayinfo->lineheight = mapInfo->screen.height;
	else
		rayinfo->lineheight = (int)(mapInfo->screen.height
				/ rayinfo->perpwalldist);
	rayinfo->drawstart = -rayinfo->lineheight / 2 + mapInfo->screen.height / 2;
	rayinfo->drawend = rayinfo->lineheight / 2 + mapInfo->screen.height / 2;
	if (rayinfo->drawstart < 0)
		rayinfo->drawstart = 0;
	if (rayinfo->drawend > mapInfo->screen.height)
		rayinfo->drawend = mapInfo->screen.height - 1;
}

void	calc_text(t_mapInfo *mapInfo, t_rayinfo *rayinfo, int x)
{
	int	y;

	if (rayinfo->side == 0)
		rayinfo->wallx = rayinfo->pos_y + rayinfo->perpwalldist
			* rayinfo->raydir_y;
	else
		rayinfo->wallx = rayinfo->pos_x + rayinfo->perpwalldist
			* rayinfo->raydir_x;
	rayinfo->wallx -= floor(rayinfo->wallx);
	rayinfo->texx = (int)(rayinfo->wallx * (double)TEXWIDTH);
	if ((rayinfo->side == 0 && rayinfo->raydir_x > 0) || (rayinfo->side == 1
			&& rayinfo->raydir_y < 0))
		rayinfo->texx = TEXWIDTH - rayinfo->texx - 1;
	rayinfo->step = 1.0 * TEXHEIGHT / rayinfo->lineheight;
	rayinfo->texpos = (rayinfo->drawstart - mapInfo->screen.height / 2
			+ rayinfo->lineheight / 2) * rayinfo->step;
	y = rayinfo->drawstart - 1;
	while (++y < rayinfo->drawend + 1)
	{
		rayinfo->texy = (int)rayinfo->texpos & (TEXHEIGHT - 1);
		rayinfo->texpos += rayinfo->step;
		rayinfo->color = get_color_pixel(*select_texture(mapInfo, rayinfo),
				rayinfo->texy, rayinfo->texx);
		img_pxl_put(&mapInfo->img, x, y, rayinfo->color);
	}
}

void	dda_exec(t_mapInfo *mapInfo, t_player *player, t_rayinfo *rayinfo)
{
	while (rayinfo->hit == 0)
	{
		if (rayinfo->sidedistx < rayinfo->sidedisty)
		{
			rayinfo->sidedistx += rayinfo->deltadistx;
			rayinfo->mapx += rayinfo->stepx;
			rayinfo->side = 0;
		}
		else
		{
			rayinfo->sidedisty += rayinfo->deltadisty;
			rayinfo->mapy += rayinfo->stepy;
			rayinfo->side = 1;
		}
		if (rayinfo->mapy <= 0 || rayinfo->mapy >= mapInfo->height
			|| rayinfo->mapx < 0)
			rayinfo->hit = 1;
		else if (mapInfo->map2d[rayinfo->mapy][rayinfo->mapx] == '1'
				|| mapInfo->map2d[rayinfo->mapy][rayinfo->mapx] == 0)
			rayinfo->hit = 1;
	}
}
