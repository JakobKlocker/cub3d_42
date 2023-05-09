/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:28:32 by iengels           #+#    #+#             */
/*   Updated: 2023/05/09 13:37:43 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	draw_crosshair(t_mapInfo *mI)
{
	int	center_x;
	int	center_y;
	int	crosshair_size;
	int	y;
	int	x;

	center_x = SCREENWIDTH / 2;
	center_y = SCREENHEIGHT / 2;
	crosshair_size = 20;
	y = center_y - crosshair_size / 2;
	while (y <= center_y + crosshair_size / 2)
	{
		img_pxl_put(&mI->img, center_x, y, 0x00FF0000);
		y++;
	}
	x = center_x - crosshair_size / 2;
	while (x <= center_x + crosshair_size / 2)
	{
		img_pxl_put(&mI->img, x, center_y, 0x00FF0000);
		x++;
	}
}

void	draw_mini_square(t_mini *m, int color, t_mapInfo *mI)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->unit)
	{
		j = 0;
		while (j < m->unit)
		{
			if (i == 0 || j == 0 || i == m->unit - 1 || j == m->unit - 1)
				img_pxl_put(&mI->img, SCREENWIDTH - (m->x + j), SCREENHEIGHT
						- (m->y + i), m->color_border);
			else
				img_pxl_put(&mI->img, SCREENWIDTH - (m->x + j), SCREENHEIGHT
						- (m->y + i), color);
			j++;
		}
		i++;
	}
}

void	draw_unit(char c, t_mini *m, t_mapInfo *mI)
{
	if (c == '1')
		draw_mini_square(m, m->color_wall, mI);
	else if (c == '0')
		draw_mini_square(m, m->color_floor, mI);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		draw_mini_square(m, m->color_floor, mI);
	else if (c == ' ')
		return ;
	else
		error("invalid map", NULL);
}

void	draw_map(t_mini *m, t_mapInfo *mI)
{
	int	i;
	int	j;

	j = m->map_y;
	while (j-- > 0)
	{
		i = m->map_x;
		while (i-- > 0)
		{
			m->x = m->unit * (m->map_x - i);
			m->y = m->unit * (m->map_y - j);
			draw_unit(m->map[j][i], m, mI);
		}
	}
}
