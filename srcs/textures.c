#include "../includes/cub3d.h"

t_texture	open_texture(t_mapInfo *mapInfo, char *path)
{
	t_texture	ret;

	ret.img = mlx_xpm_file_to_image(mapInfo->mlx.mlx, path, &ret.width,
			&ret.height);
	if (!ret.img)
		error("open", mapInfo);
	ret.path = path;
	ret.addr.img = mlx_get_data_addr(ret.img, &ret.addr.bpp, &ret.addr.sizeline,
			&ret.addr.endian);
	return (ret);
}

void	open_all_textures(t_mapInfo *mapInfo)
{
	mapInfo->e = open_texture(mapInfo, mapInfo->etexture);
	mapInfo->w = open_texture(mapInfo, mapInfo->wtexture);
	mapInfo->n = open_texture(mapInfo, mapInfo->ntexture);
	mapInfo->s = open_texture(mapInfo, mapInfo->stexture);
}

unsigned int	get_color_pixel(t_texture tex, int y, int x)
{
	unsigned int	pos;
	int				*addr;

	pos = y * tex.addr.sizeline + x * (tex.addr.bpp / 8);
	addr = (int *)tex.addr.img;
	return (*(int *)((char *)addr + pos));
}
