#include "../includes/cub3d.h"

int	ft_is_in_array(t_mimap m)
{
	if (((m.x_i - m.offset_x) / m.u_size) < m.x && ((m.y_i - m.offset_y)
			/ m.u_size) < m.y)
	{
		return (1);
	}
	return (0);
}

void	ft_get_map_h_and_w(t_mapInfo *mapInfo, int *x, int *y)
{
	int	max;

	*x = 0;
	*y = 0;
	while (mapInfo->map2D[*y])
	{
		max = 0;
		while (mapInfo->map2D[*y][max])
			max++;
		if ((*x) < max)
			(*x) = max;
		(*y)++;
	}
}

// int	ft_player_mm_pos(char c, t_mimap m, int x_i, int y_i)
// {
// 	int	p_l;
// 	int	p_m;

// 	p_l = m.u_size / 2 - 4;
// 	p_m = p_l + 7;
// 	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
// 	{
// 		if (x_i >= p_l && x_i <= p_m && y_i >= p_l && y_i <= p_m)
// 			return (1);
// 	}
// 	return (0);
// }

int	ft_get_size_of_unit(t_mimap m, int x, int y)
{
	int	size;

	size = 0;
	if (((m.s_w - m.offset_x) / x) > ((m.s_h - m.offset_y) / y))
		size = (m.s_h - m.offset_y) / y;
	else
		size = (m.s_w - m.offset_x) / x;
	return (size);
}

void	ft_init_mimap(t_mapInfo *mapInfo, t_mimap *m)
{
	(*m).offset_x = 1020;
	(*m).offset_y = 486;
	(*m).s_h = ScreenHeight / 3 + (*m).offset_y;
	(*m).s_w = ScreenWidth / 3 + (*m).offset_x;
	ft_get_map_h_and_w(mapInfo, &(*m).x, &(*m).y);
	(*m).u_size = ft_get_size_of_unit(*m, (*m).x, (*m).y);
	(*m).color_g = 0x00000BB00;
	(*m).color_r = 0x00222222;
	(*m).color_w = 0x00888888;
	(*m).a_x = 0;
	(*m).a_y = 0;
	(*m).player_drawn = 0;
}

int	ft_get_double_pos(double pos, int size)
{
	int	temp;

	temp = pos - (int)pos * 100;
	size = size / 100 * temp;
	return (size);
}

void	ft_draw_player(t_mapInfo *mapinfo, t_mimap m, int size)
{
	int	x;
	int	y;
	int	p_size;
	int	i;
	int	j;

	x = mapinfo->player.posX * size + m.offset_x;
	y = mapinfo->player.posY * size + m.offset_y;
	p_size = size / 4;
	i = 0;
	while (i < p_size)
	{
		j = 0;
		while (j < p_size)
		{
			img_pxl_put(&mapinfo->img, x + i - p_size / 2, y + j - p_size / 2,
					0x00DD0000);
			j++;
		}
		i++;
	}
}

int	ft_is_ground(char c, t_mapInfo mapinfo, t_mimap m)
{
	if (c == '0' || c == 'W' || c == 'E' || c == 'N' || c == 'S')
	{
		return (1);
	}
	return (0);
}

// void	ft_draw_player(t_mapInfo mapinfo, t_mimap m)
// {

// }

void	ft_save_minmap(t_mapInfo *mapInfo, t_mimap *m)
{
	(*m).y_i = 0 + (*m).offset_y;
	while ((*m).y_i < (*m).s_h)
	{
		(*m).a_y = ((*m).y_i - (*m).offset_y) / (*m).u_size;
		(*m).x_i = 0 + (*m).offset_x;
		while ((*m).x_i < (*m).s_w)
		{
			(*m).a_x = ((*m).x_i - (*m).offset_x) / (*m).u_size;
			if (ft_is_in_array(*m))
			{
				if (((*m).x_i - (*m).offset_x) % (*m).u_size == 0 || ((*m).y_i
						- (*m).offset_y) % (*m).u_size == 0)
					(*m).color = 0x00000000;
				else if ((*m).a_x < ft_strlen(mapInfo->map2D[(*m).a_y]) &&
							mapInfo->map2D[(*m).a_y][(*m).a_x] == '1')
					(*m).color = 0x00666666;
				else if ((*m).a_x < ft_strlen(mapInfo->map2D[(*m).a_y])
						&& ft_is_ground(mapInfo->map2D[(*m).a_y][(*m).a_x],
							*mapInfo, *m))
					(*m).color = 0x00009900;
				else
					(*m).color = 0x00000000;
				img_pxl_put(&mapInfo->img, (*m).x_i, (*m).y_i, (*m).color);
			}
			(*m).x_i++;
		}
		(*m).y_i++;
	}
}

void	ft_minimapBG(t_mapInfo *mapInfo, t_mimap *m)
{
	ft_init_mimap(mapInfo, m);
	m->img.img = mlx_new_image(mapInfo->mlx.mlx, ScreenWidth, ScreenHeight);
	m->img.addr = mlx_get_data_addr(m->img.img,
									&m->img.bpp,
									&m->img.size_line,
									&m->img.endian);
	ft_save_minmap(mapInfo, m);
	ft_draw_player(mapInfo, *m, m->u_size);
	mlx_put_image_to_window(mapInfo->mlx.mlx,
							mapInfo->mlx.win,
							mapInfo->img.img,
							0,
							0);
}

/*
if	((x_i / m.u_size) < m.x && (y_i / m.u_size) < m.y
						&& (mapInfo->map2D[y_i / m.u_size][x_i
							/ m.u_size] == '0'))
*/