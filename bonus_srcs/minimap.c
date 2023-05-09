/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:51:09 by iengels           #+#    #+#             */
/*   Updated: 2023/05/09 12:12:26 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	find_biggest_line(t_mapInfo *mI)
{
	int	i;
	int	j;
	int	biggest;

	i = 0;
	biggest = 0;
	while (mI->map2d[i])
	{
		j = 0;
		while (mI->map2d[i][j])
			j++;
		if (j > biggest)
			biggest = j;
		i++;
	}
	return (biggest);
}

void	copy_minimap_info(t_mapInfo *mI, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (mI->map2d[i])
	{
		j = 0;
		while (mI->map2d[i][j])
		{
			map[i][j] = mI->map2d[i][j];
			j++;
		}
		while (j < find_biggest_line(mI))
		{
			map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

char	**create_equal_map(t_mapInfo *mI)
{
	char	**map;
	int		i;
	int		j;

	mI->mini.bolean = 1;
	i = 0;
	j = find_biggest_line(mI);
	while (mI->map2d[i])
		i++;
	map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!map)
		error("malloc", mI);
	map[i] = NULL;
	while (i-- > 0)
	{
		map[i] = (char *)malloc(sizeof(char) * (j + 1));
		if (!map[i])
			error("malloc", mI);
		map[i][j] = '\0';
	}
	copy_minimap_info(mI, map);
	return (map);
}

int	get_bigger_axis(t_mini *m, t_mapInfo *mI)
{
	int	i;
	int	j;

	j = find_biggest_line(mI);
	i = 0;
	while (mI->map2d[i])
		i++;
	m->map_x = j;
	m->map_y = i;
	if (i > j)
		return (i);
	return (j);
}

void	minimap(t_mapInfo *mI)
{
	init_minimap(&mI->mini, mI);
	if (mI->mini.bolean == 0)
		mI->mini.map = create_equal_map(mI);
	draw_map(&mI->mini, mI);
	draw_crosshair(mI);
	mlx_mouse_move(mI->mlx.mlx, mI->mlx.win, SCREENWIDTH / 2, SCREENHEIGHT / 2);
	draw_player(&mI->mini, mI);
}
