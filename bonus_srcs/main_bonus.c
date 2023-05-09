/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:20:45 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/09 10:59:10 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_mapInfo	mapinfo;

	if (argc != 2)
	{
		ft_printf("Error\nWrong amount of Arguments.\n");
		return (1);
	}
	if (malloc_check())
		return (1);
	init_map_info(&mapinfo, argv[1]);
	valid_map_extention(mapinfo.mapname, &mapinfo);
	mapinfo.fd = open_map(mapinfo.mapname, &mapinfo);
	get_map_info(&mapinfo);
	all_map_checks(&mapinfo);
	get_player_cordinates(&mapinfo, &mapinfo.player);
	open_window(&mapinfo);
	set_spawn_dir(&mapinfo.player, &mapinfo.rayinfo);
	open_all_textures(&mapinfo);
	ray_casting(&mapinfo);
	mlx_loop_own(&mapinfo);
}
