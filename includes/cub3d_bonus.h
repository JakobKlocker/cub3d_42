/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:18:27 by jklocker          #+#    #+#             */
/*   Updated: 2023/05/09 12:12:05 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libft/ft_printf.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# define SCREENHEIGHT 720
# define SCREENWIDTH 1280

# define TEXWIDTH 1024
# define TEXHEIGHT 1024

typedef struct s_addr
{
	char			*img;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_addr;

typedef struct s_texture
{
	t_addr			addr;
	void			*img;
	char			*path;
	int				width;
	int				height;

}					t_texture;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

// typedef struct s_time
// {
// 	double			time;
// 	double			oldTime;
// }					t_time;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	char			spawn_dir;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct s_screen
{
	int				width;
	int				height;
}					t_screen;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;

typedef struct s_mini
{
	int				unit;
	int				color_floor;
	int				color_wall;
	int				color_border;
	char			**map;
	int				map_x;
	int				map_y;
	int				x;
	int				y;
	int				width;
	int				height;
	int				bolean;
	t_img			img;
}					t_mini;

typedef struct s_rayinfo
{
	double			pos_x;
	double			pos_y;
	double			camera;
	double			dir_x;
	double			dir_y;
	double			raydir_x;
	double			raydir_y;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			plane_x;
	double			plane_y;
	double			olddir_x;
	double			oldplane_x;
	int				mapx;
	int				mapy;
	int				hit;
	int				side;
	int				stepx;
	int				stepy;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				texx;
	int				texy;
	double			wallx;
	double			step;
	double			texpos;
	unsigned int	color;
}					t_rayinfo;

typedef struct s_mapInfo
{
	int				fd;
	int				height;
	char			*map1d;
	char			**map2d;
	char			*mapname;
	char			*ntexture;
	char			*etexture;
	char			*stexture;
	char			*wtexture;
	char			**fcolor;
	char			**ccolor;
	int				mouse_x;
	int				mouse_y;
	unsigned long	current;
	unsigned long	previous;
	t_mini			mini;
	t_screen		screen;
	t_player		player;
	t_rayinfo		rayinfo;
	t_mlx			mlx;
	t_img			img;
	t_texture		n;
	t_texture		s;
	t_texture		e;
	t_texture		w;
}					t_mapInfo;

typedef struct s_index
{
	int				i;
	int				j;
	int				k;
}					t_index;

//mallocMap.c
char				*malloc_1d(t_mapInfo *mapInfo);
char				**malloc_2d(t_mapInfo *mapInfo);
void				copy_2d_map(t_mapInfo *mapInfo);
int					get_len_till_char(char *line, char c);
void				print_2d_map(t_mapInfo *mapInfo);

//mallocMap_1.c
char				*malloc_1d_util(t_mapInfo *mapInfo, char **line);

//mapChecks.c
void				valid_characters(t_mapInfo *mapInfo);
void				valid_map_extention(char *mapname, t_mapInfo *mapInfo);
void				wall_top_bottom(t_mapInfo *mapInfo);
void				wall_check(t_mapInfo *mapInfo);
void				wall_check_surrounding(char **map2d, t_index *index,
						t_mapInfo *mapInfo);

//mapChecks_1.c
void				color_check(t_mapInfo *mapInfo);
void				is_rgb(char *str, t_mapInfo *mapInfo);
void				all_map_checks(t_mapInfo *mapInfo);

//mapInfos.c
int					open_map(char *mapname, t_mapInfo *mapInfo);
void				add_map_infos(char **split, t_mapInfo *mapInfo);
void				add_map(t_mapInfo *mapInfo);
void				get_map_info(t_mapInfo *mapInfo);
void				init_map_info(t_mapInfo *mapInfo, char *mapname);

//mapInfos_1.c
void				get_player_cordinates(t_mapInfo *mapInfo, t_player *player);
void				set_spawn_dir(t_player *player, t_rayinfo *rayinfo);
void				add_map_infos_1(t_mapInfo *mapInfo, int *i, char **split);

//mlxCalls.c
void				open_window(t_mapInfo *mapInfo);
int					move_hook(int key, t_mapInfo *mapInfo);
void				mlx_loop_own(t_mapInfo *mapInfo);
unsigned long		get_current_time(void);

//moveHooks.c
void				move_hook_right(int key, t_rayinfo *rayinfo,
						t_mapInfo *mapInfo);
void				move_hook_left(int key, t_rayinfo *rayinfo,
						t_mapInfo *mapInfo);
void				move_hook_updown(int key, t_rayinfo *rayinfo,
						t_mapInfo *mapInfo);
int					move_mousehook_lr(int x, t_rayinfo *rayinfo, t_mapInfo *mI);

//rayCasting.C
void				ray_casting(t_mapInfo *mapInfo);
void				calc_step(t_rayinfo *rayinfo);
void				calc_dist(t_mapInfo *mapInfo, t_player *player,
						t_rayinfo *rayinfo);
void				dda_exec(t_mapInfo *mapInfo, t_player *player,
						t_rayinfo *rayinfo);
void				calc_text(t_mapInfo *mapInfo, t_rayinfo *rayinfo, int x);

//rayCasting_1.c
//void initrayinfo(t_rayinfo *rayinfo, t_player *player, t_mapInfo *mapInfo);
//void drawLine(t_mapInfo *mapInfo, int x, int drawstart, int drawend);

void				init_ray_info_loop(int x, t_rayinfo *rayinfo,
						t_player *player, t_mapInfo *mapInfo);
void				img_pxl_put(t_img *img, int x, int y, int color);
t_texture			*select_texture(t_mapInfo *mapInfo, t_rayinfo *rayinfo);

//createBG.c
int					encode_rgb(unsigned char red, unsigned char green,
						unsigned char blue);
void				create_floor(t_mapInfo *mapInfo);
void				create_sky(t_mapInfo *mapInfo);
void				create_bg(t_mapInfo *mapInfo);

//errorFree.c
void				free_2d(char **str);
void				error(char *error, t_mapInfo *mapInfo);
void				free_mlx(t_mapInfo *mapInfo);
int					free_exit(t_mapInfo *mapInfo);

//errorFree_1.c
void				fd_free(t_mapInfo *mapInfo);
int					malloc_check(void);

//textures.c
t_texture			open_texture(t_mapInfo *mapInfo, char *path);
void				open_all_textures(t_mapInfo *mapInfo);
unsigned int		get_color_pixel(t_texture tex, int y, int x);

//	minimap.c

void				minimap(t_mapInfo *mI);
int					get_bigger_axis(t_mini *m, t_mapInfo *mI);
char				**create_equal_map(t_mapInfo *mI);
int					find_biggest_line(t_mapInfo *mI);
void				copy_minimap_info(t_mapInfo *mI, char **map);

//	minimap_player.c

void				draw_player(t_mini *m, t_mapInfo *mI);
void				init_minimap(t_mini *m, t_mapInfo *mI);

//	minimap_helper.c

void				draw_crosshair(t_mapInfo *mI);
void				draw_map(t_mini *m, t_mapInfo *mI);
void				draw_unit(char c, t_mini *m, t_mapInfo *mI);
void				draw_mini_square(t_mini *m, int color, t_mapInfo *mI);

#endif