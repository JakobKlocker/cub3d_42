/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:28:25 by iengels           #+#    #+#             */
/*   Updated: 2023/05/09 10:50:48 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	draw_player(t_mini *m, t_mapInfo *mI)
{
	int	i;
	int	j;
	int	player_size;

	player_size = m->unit / 3;
	if (player_size > 4)
		player_size = 4;
	m->x = (m->map_x + 0.5 - mI->player.pos_x) * m->unit;
	m->y = (m->map_y + 0.5 - mI->player.pos_y) * m->unit;
	i = 0 - player_size / 2;
	while (i < player_size - player_size / 2)
	{
		j = 0 - player_size / 2;
		while (j < player_size - player_size / 2)
		{
			img_pxl_put(&mI->img, SCREENWIDTH - (m->x + j), SCREENHEIGHT - (m->y
					+ i), 0x00FF0000);
			j++;
		}
		i++;
	}
}

void	init_minimap(t_mini *m, t_mapInfo *mI)
{
	m->unit = 360 / get_bigger_axis(m, mI);
	m->x = 0;
	m->y = 0;
	m->color_floor = 0x00008822;
	m->color_wall = 0x00333333;
	m->color_border = 0x00010101;
	m->width = 360;
	m->height = 360;
}
