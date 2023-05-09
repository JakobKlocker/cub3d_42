/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBG_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:20:36 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/08 19:34:18 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

void	create_sky(t_mapInfo *mapInfo)
{
	t_index	index;
	int		color;

	index.i = 0;
	color = encode_rgb(ft_atoi(mapInfo->ccolor[0]), ft_atoi(mapInfo->ccolor[1]),
			ft_atoi(mapInfo->ccolor[2]));
	while (index.i < mapInfo->screen.height / 2)
	{
		index.j = 0;
		while (index.j < mapInfo->screen.width)
		{
			img_pxl_put(&mapInfo->img, index.j, index.i, color);
			index.j++;
		}
		index.i++;
	}
}

void	create_floor(t_mapInfo *mapInfo)
{
	t_index	index;
	int		color;

	index.i = 0;
	color = encode_rgb(ft_atoi(mapInfo->fcolor[0]), ft_atoi(mapInfo->fcolor[1]),
			ft_atoi(mapInfo->fcolor[2]));
	index.i = mapInfo->screen.height / 2;
	while (index.i < mapInfo->screen.height)
	{
		index.j = 0;
		while (index.j < mapInfo->screen.width)
		{
			img_pxl_put(&mapInfo->img, index.j, index.i, color);
			index.j++;
		}
		index.i++;
	}
}

void	create_bg(t_mapInfo *mapInfo)
{
	create_sky(mapInfo);
	create_floor(mapInfo);
}
