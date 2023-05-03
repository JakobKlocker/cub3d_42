#include "../includes/cub3d.h"

char	*malloc_1d_util(t_mapInfo *mapInfo, char **line)
{
	char	*ret;

	ret = calloc(1, 1);
	if (!ret)
		error("malloc", mapInfo);
	*line = get_next_line(mapInfo->fd);
	if (!line)
		error("malloc", mapInfo);
	return (ret);
}
