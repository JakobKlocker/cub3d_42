/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorFree_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:20:38 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/08 19:34:20 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	fd_free(t_mapInfo *mapInfo)
{
	char	*tmp;

	if (mapInfo->fd != -1)
	{
		tmp = get_next_line(mapInfo->fd);
		while (tmp)
		{
			free(tmp);
			tmp = get_next_line(mapInfo->fd);
		}
		close(mapInfo->fd);
	}
}

int	malloc_check(void)
{
	char	*mal_check;

	mal_check = malloc(25000000);
	if (!mal_check)
	{
		ft_printf("Error\nNot enough memory to run the programm.\n");
		return (1);
	}
	free(mal_check);
	return (0);
}
