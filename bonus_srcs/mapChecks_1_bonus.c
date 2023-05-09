/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapChecks_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:20:54 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/08 15:36:03 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	color_check(t_mapInfo *mapInfo)
{
	t_index	index;

	index.i = 0;
	index.j = 0;
	while (mapInfo->ccolor[index.i])
		index.i++;
	while (mapInfo->fcolor[index.j])
		index.j++;
	if (index.i != 3 || index.j != 3)
		error("RGB", mapInfo);
	index.i = 0;
	while (index.i < 3)
	{
		is_rgb(mapInfo->ccolor[index.i], mapInfo);
		is_rgb(mapInfo->fcolor[index.i], mapInfo);
		index.i++;
	}
}

void	is_rgb(char *str, t_mapInfo *mapInfo)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 3)
		error("RGB", mapInfo);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error("RGB", mapInfo);
		i++;
	}
	i = ft_atoi(str);
	if (i > 255 || i < 0)
		error("RGB", mapInfo);
}

void	all_map_checks(t_mapInfo *mapInfo)
{
	wall_check(mapInfo);
	color_check(mapInfo);
	valid_characters(mapInfo);
}
