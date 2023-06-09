/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocMap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:20:48 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/08 14:20:49 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
