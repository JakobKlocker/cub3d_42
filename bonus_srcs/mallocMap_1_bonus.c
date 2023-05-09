/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocMap_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:20:48 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/08 15:35:59 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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
