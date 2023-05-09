/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorFree_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:20:43 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/09 11:09:53 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	free_2d(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

//Don't free mapname, it's copied from the arg
int	free_exit(t_mapInfo *mapInfo)
{
	if (mapInfo->map1d)
		free(mapInfo->map1d);
	if (mapInfo->map2d)
		free_2d(mapInfo->map2d);
	if (mapInfo->ntexture)
		free(mapInfo->ntexture);
	if (mapInfo->etexture)
		free(mapInfo->etexture);
	if (mapInfo->stexture)
		free(mapInfo->stexture);
	if (mapInfo->wtexture)
		free(mapInfo->wtexture);
	if (mapInfo->fcolor)
		free_2d(mapInfo->fcolor);
	if (mapInfo->ccolor)
		free_2d(mapInfo->ccolor);
	if (mapInfo->mini.map)
		free_2d(mapInfo->mini.map);
	fd_free(mapInfo);
	free_mlx(mapInfo);
	exit(1);
	return (0);
}

void	destory_images(t_mapInfo *mapInfo)
{
	if (mapInfo->n.img)
		mlx_destroy_image(mapInfo->mlx.mlx, mapInfo->n.img);
	if (mapInfo->e.img)
		mlx_destroy_image(mapInfo->mlx.mlx, mapInfo->e.img);
	if (mapInfo->s.img)
		mlx_destroy_image(mapInfo->mlx.mlx, mapInfo->s.img);
	if (mapInfo->w.img)
		mlx_destroy_image(mapInfo->mlx.mlx, mapInfo->w.img);
	if (mapInfo->img.img)
		mlx_destroy_image(mapInfo->mlx.mlx, mapInfo->img.img);
}

void	free_mlx(t_mapInfo *mapInfo)
{
	destory_images(mapInfo);
	if (mapInfo->mlx.mlx && mapInfo->mlx.win)
		mlx_destroy_window(mapInfo->mlx.mlx, mapInfo->mlx.win);
	if (mapInfo->mlx.mlx)
	{
		mlx_destroy_display(mapInfo->mlx.mlx);
		free(mapInfo->mlx.mlx);
	}
}

void	error(char *error, t_mapInfo *mapInfo)
{
	if (ft_strcmp(error, "RGB") == 0)
		ft_printf("Error\n Invalid RGB Values\n");
	else if (ft_strcmp(error, "wall") == 0)
		ft_printf("Error\n Map not surrounded by Walls\n");
	else if (ft_strcmp(error, "invChar") == 0)
		ft_printf("Error\n Only '0', '1', 'N', 'S', 'E', \
		'W' or ' ' inside the map\n");
	else if (ft_strcmp(error, "malloc") == 0)
		ft_printf("Error\nmalloc failed\n");
	else if (ft_strcmp(error, "identif") == 0)
		ft_printf("Error\nInvalid Map identifier\n");
	else if (ft_strcmp(error, ".cub") == 0)
		ft_printf("Error\nMap name invalid, must end with .cub\n");
	else if (ft_strcmp(error, "open") == 0)
		ft_printf("Error\nCouldn't open file\n");
	else if (ft_strcmp(error, "mlx") == 0)
		ft_printf("Error\nMlx function failed\n");
	else if (ft_strcmp(error, "texsize") == 0)
		ft_printf("Error\nTexture width or height wrong\n");
	else
		ft_printf("Error\n");
	free_exit(mapInfo);
}
