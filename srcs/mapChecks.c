/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapChecks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:20:57 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/09 15:16:00 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	valid_characters(t_mapInfo *mapInfo)
{
	t_index	index;
	char	cur;

	index.i = 0;
	while (index.i < mapInfo->height)
	{
		index.j = 0;
		while (mapInfo->map2d[index.i][index.j] != '\0')
		{
			cur = mapInfo->map2d[index.i][index.j];
			if (cur != '0' && cur != '1' && cur != 'N' && cur != 'E'
				&& cur != 'S' && cur != 'W' && cur != ' ')
				error("invChar", mapInfo);
			index.j++;
		}
		index.i++;
	}
}

void	valid_map_extention(char *mapname, t_mapInfo *mapInfo)
{
	int	map_name_lenght;

	map_name_lenght = ft_strlen(mapname);
	if (map_name_lenght < 4 || ft_strncmp(&mapname[map_name_lenght - 4], ".cub",
			4) != 0)
		error(".cub", mapInfo);
}

void	wall_top_bottom(t_mapInfo *mapInfo)
{
	t_index	index;

	index.i = 0;
	while (mapInfo->map2d[0][index.i])
	{
		if (mapInfo->map2d[0][index.i] != '1'
			&& mapInfo->map2d[0][index.i] != ' ')
			error("wall", mapInfo);
		index.i++;
	}
	index.i = 0;
	while (mapInfo->map2d[mapInfo->height - 1][index.i])
	{
		if (mapInfo->map2d[mapInfo->height - 1][index.i] != '1'
			&& mapInfo->map2d[mapInfo->height - 1][index.i] != ' ')
			error("wall", mapInfo);
		index.i++;
	}
}

void	wall_check(t_mapInfo *mapInfo)
{
	char	**map2d;
	t_index	index;

	wall_top_bottom(mapInfo);
	map2d = mapInfo->map2d;
	index.i = 1;
	while (index.i < mapInfo->height - 1)
	{
		index.j = 0;
		if (map2d[index.i][0] == '\0')
			error("wall", mapInfo);
		while (map2d[index.i][index.j])
		{
			if (map2d[index.i][index.j] == '0')
				wall_check_surrounding(map2d, &index, mapInfo);
			index.j++;
		}
		index.i++;
	}
}

void	wall_check_surrounding(char **map2d, t_index *index, t_mapInfo *mapInfo)
{
	if (map2d[index->i][index->j] == '0' && (index->j == 0
			|| map2d[index->i][index->j + 1] == '\0'))
		error("wall", mapInfo);
	else if (map2d[index->i][index->j - 1] == ' ' || map2d[index->i][index->j
			+ 1] == ' ')
		error("wall", mapInfo);
	else if (ft_strlen(map2d[index->i - 1]) < index->j + 1
		|| ft_strlen(map2d[index->i + 1]) < index->j + 1)
		error("wall", mapInfo);
	else if (map2d[index->i - 1][index->j] == ' ' || map2d[index->i
			+ 1][index->j] == ' ')
		error("wall", mapInfo);
}
