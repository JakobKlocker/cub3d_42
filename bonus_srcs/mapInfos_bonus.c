/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapInfos_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:21:04 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/09 14:58:15 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	open_map(char *mapname, t_mapInfo *mapInfo)
{
	int	fd;

	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		error("open", mapInfo);
	return (fd);
}

// Change Strncmp to strcmp to not overflow if word is below 3 or 2
void	add_map_infos(char **split, t_mapInfo *mapInfo)
{
	t_index	index;

	index.i = 0;
	add_map_infos_1(mapInfo, &index.i, split);
	if (!mapInfo->ntexture && ft_strcmp(split[0], "NO\0") == 0)
		mapInfo->ntexture = ft_strdup(split[1]);
	else if (!mapInfo->stexture && ft_strcmp(split[0], "SO\0") == 0)
		mapInfo->stexture = ft_strdup(split[1]);
	else if (!mapInfo->wtexture && ft_strcmp(split[0], "WE\0") == 0)
		mapInfo->wtexture = ft_strdup(split[1]);
	else if (!mapInfo->etexture && ft_strcmp(split[0], "EA\0") == 0)
		mapInfo->etexture = ft_strdup(split[1]);
	else if (!mapInfo->fcolor && ft_strcmp(split[0], "F\0") == 0)
		mapInfo->fcolor = ft_split(split[1], ',');
	else if (!mapInfo->ccolor && ft_strcmp(split[0], "C\0") == 0)
		mapInfo->ccolor = ft_split(split[1], ',');
	else
	{
		free_2d(split);
		error("identif", mapInfo);
	}
	free_2d(split);
}

void	add_map(t_mapInfo *mapInfo)
{
	t_index	index;

	mapInfo->map1d = malloc_1d(mapInfo);
	index.i = 0;
	index.j = 0;
	while (mapInfo->map1d[index.i])
	{
		if (mapInfo->map1d[index.i] == '\n')
			index.j++;
		index.i++;
	}
	if (index.i == 0)
		free_exit(mapInfo);
	mapInfo->height = index.j;
	mapInfo->map2d = malloc_2d(mapInfo);
	copy_2d_map(mapInfo);
}

void	get_map_info(t_mapInfo *mapInfo)
{
	t_index	index;
	char	**split;
	char	*line;

	index.i = 0;
	index.j = 0;
	line = get_next_line(mapInfo->fd);
	if (!line)
		error("else", mapInfo);
	while (index.j < 6 && line)
	{
		split = ft_split(line, ' ');
		if (line)
			free(line);
		if (split)
		{
			index.j++;
			add_map_infos(split, mapInfo);
		}
		if (index.j != 6)
			line = get_next_line(mapInfo->fd);
	}
	if (index.j != 6)
		free_exit(mapInfo);
	add_map(mapInfo);
}

void	init_map_info(t_mapInfo *mapInfo, char *mapname)
{
	mapInfo->mapname = mapname;
	mapInfo->fd = -1;
	mapInfo->height = 0;
	mapInfo->map1d = NULL;
	mapInfo->map2d = NULL;
	mapInfo->ntexture = NULL;
	mapInfo->etexture = NULL;
	mapInfo->stexture = NULL;
	mapInfo->wtexture = NULL;
	mapInfo->fcolor = NULL;
	mapInfo->ccolor = NULL;
	mapInfo->mlx.mlx = NULL;
	mapInfo->mlx.win = NULL;
	mapInfo->n.img = NULL;
	mapInfo->s.img = NULL;
	mapInfo->w.img = NULL;
	mapInfo->e.img = NULL;
	mapInfo->img.img = NULL;
	mapInfo->mini.map = NULL;
	mapInfo->mini.bolean = 0;
	mapInfo->previous = get_current_time();
}
