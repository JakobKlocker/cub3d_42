#include "../includes/cub3d.h"

char	*malloc_1d(t_mapInfo *mapInfo)
{
	char	*ret;
	char	*tmp;
	char	*line;

	ret = malloc_1d_util(mapInfo, &line);
	while (line && *line == '\0')
	{
		free(line);
		line = get_next_line(mapInfo->fd);
	}
	while (line)
	{
		tmp = ret;
		ret = ft_strjoin(ret, line);
		if (tmp)
			free(tmp);
		tmp = ret;
		ret = ft_strjoin(ret, "\n");
		if (tmp)
			free(tmp);
		free(line);
		line = get_next_line(mapInfo->fd);
	}
	return (ret);
}

char	**malloc_2d(t_mapInfo *mapInfo)
{
	t_index	index;
	char	**ret;

	index.i = 0;
	index.j = 0;
	ret = malloc(mapInfo->height * (sizeof(char *) + 1));
	if (!ret)
		error("malloc", mapInfo);
	while (index.i < mapInfo->height)
	{
		ret[index.i] = malloc(get_len_till_char(mapInfo->map1d + index.j, '\n')
				+ 1);
		if (!ret[index.i])
			error("malloc", mapInfo);
		index.j += get_len_till_char(mapInfo->map1d + index.j, '\n') + 1;
		index.i++;
	}
	ret[index.i] = NULL;
	return (ret);
}

void	copy_2d_map(t_mapInfo *mapInfo)
{
	t_index	index;

	index.i = 0;
	index.j = 0;
	while (index.i < mapInfo->height)
	{
		index.k = 0;
		while (mapInfo->map1d[index.j] != '\n')
		{
			mapInfo->map2d[index.i][index.k] = mapInfo->map1d[index.j];
			index.j++;
			index.k++;
		}
		mapInfo->map2d[index.i][index.k] = '\0';
		index.j++;
		index.i++;
	}
}

int	get_len_till_char(char *line, char c)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] != c)
		i++;
	return (i);
}

void	print_2d_map(t_mapInfo *mapInfo)
{
	t_index	index;

	index.i = 0;
	index.j = 0;
	while (index.i < mapInfo->height)
	{
		ft_printf("%s\n", mapInfo->map2d[index.i]);
		index.i++;
	}
}
