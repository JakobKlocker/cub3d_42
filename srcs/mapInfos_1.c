#include "../includes/cub3d.h"

void	get_player_cordinates(t_mapInfo *mapInfo, t_player *player)
{
	t_index	index;
	char	c;

	index.i = 0;
	index.k = 0;
	while (index.i < mapInfo->height)
	{
		index.j = 0;
		while (mapInfo->map2d[index.i][index.j])
		{
			c = mapInfo->map2d[index.i][index.j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				if (index.k != 0)
					error("invChar", mapInfo);
				player->pos_y = index.i;
				player->pos_x = index.j;
				player->spawn_dir = c;
				index.k++;
			}
			index.j++;
		}
		index.i++;
	}
}

void	set_spawn_dir(t_player *player, t_rayinfo *rayinfo)
{
	rayinfo->dir_x = 0;
	rayinfo->dir_y = 0;
	rayinfo->plane_x = 0;
	rayinfo->plane_y = 0;
	if (player->spawn_dir == 'N')
	{
		rayinfo->dir_y = -1;
		rayinfo->plane_x = 0.66;
	}
	else if (player->spawn_dir == 'S')
	{
		rayinfo->dir_y = 1;
		rayinfo->plane_x = -0.66;
	}
	else if (player->spawn_dir == 'E')
	{
		rayinfo->dir_x = 1;
		rayinfo->plane_y = 0.66;
	}
	else if (player->spawn_dir == 'W')
	{
		rayinfo->dir_x = -1;
		rayinfo->plane_y = -0.66;
	}
}
