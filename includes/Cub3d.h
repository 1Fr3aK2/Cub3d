/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:52:17 by raamorim          #+#    #+#             */
/*   Updated: 2025/12/09 23:33:17 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft/get_next_line/get_next_line_bonus.h"
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# ifndef WIN_W
#  define WIN_W 800
# endif
# ifndef WIN_H
#  define WIN_H 600
# endif
# ifndef FOV
#  define FOV 66
# endif

# ifndef MOVE_SPEED
#  define MOVE_SPEED 0.03125
# endif

# ifndef SQ_SIZE
#  define SQ_SIZE 13
# endif

# ifndef ROT
#  define ROT 0.03125
# endif

# ifndef C_SIZE
#  define C_SIZE 10
# endif

# define VALID_CHARS "01NSEW "
# define WALL '1'
# define SPACE '0'
# define ORIENTATION "NSEW"
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'
# define PLAYER "NSWE"
# define PI 3.1415926535
# define TRACE 0.5

# define MAP_S 64

typedef uint32_t	t_rgb;

typedef enum e_texture_type
{
	N = 0,
	S = 1,
	EA = 2,
	WE = 3,
	TEXTURE_COUNT = 4
}					t_texture_type;

typedef enum e_keys
{
	NONE = 0,
	FORWARD = 1 << 0,
	BACKWARDS = 1 << 1,
	LEFT_S = 1 << 2,
	RIGHT_S = 1 << 3,
	TURN_L = 1 << 4,
	TURN_R = 1 << 5
}					t_keys;

typedef struct s_rays
{
	float			y;
	float			x;
	float			dir_y;
	float			dir_x;
	float			dy;
	float			dx;
	float			dist_y;
	float			dist_x;
	float			theta;
	int				sy;
	int				sx;
	int				map_y;
	int				map_x;
}					t_rays;

typedef struct s_limits
{
	float			x;
	float			y;
}					t_limits;

typedef struct s_paint
{
	t_rgb			color;
	size_t			x;
	size_t			y;
	t_limits		begin;
	t_limits		end;
}					t_paint;

typedef struct s_file
{
	int				fd;
}					t_file;

typedef struct s_img
{
	void			*img;
	char			*pixel_ptr;
	int				bits_pixel;
	int				end;
	int				line_len;
	int				width;
	int				height;
	char			*path;
}					t_img;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_img			img;
}					t_mlx;

typedef struct s_assets
{
	t_img			textures[TEXTURE_COUNT];
}					t_assets;

typedef struct s_map
{
	t_assets		assets;
	char			**buffer;
	char			**map;
	char			**temp_map;
	int				height;
	t_rgb			rgb_floor;
	t_rgb			rgb_ceiling;
	size_t			max_w;
	size_t			max_h;
	t_img			img;
}					t_map;

typedef struct s_player
{
	float			x;
	float			y;
	float			dir_x;
	float			dir_y;
	float			plane_x;
}					t_player;

typedef struct s_data
{
	t_assets		assets;
	t_img			img;
	t_mlx			mlx;
	t_player		player;
	t_map			map;
	t_file			file;
	uint8_t			keys;
}					t_data;

void				rotate_right(t_data *data);
void				rotate_left(t_data *data);
// src/textures/set_textures.c
bool				check_load_textures(char *floor, char *ceiling, t_map *map);
bool				set_texture(char *line, char **floor, char **ceiling,
						t_map *map);

// src/init/init.c
void				init_struct(t_data *data);
t_data				*data_s(void);

// src/mlx/init_mlx.c
void				init_mlx(t_data *data);

// src/erros/errors.c
void				exit_error(t_data *data, char *str);

// src//hooks/keys.c
int					handle_keypress(int key, t_data *data);
int					press_x(t_data *data);
int					handle_keyrelease(int key, t_data *data);

// src/parsing/file/check_file.c
void				check_map_name(char *file_name);

// src//parsing/map/check_map/check_map.c
bool				check_map(char *floor, char *ceiling, t_map *map);
bool				check_valid_chars(t_map *map);
bool				check_player(t_map *map);
void				set_bool(t_map *map);
bool				alloc_temp_map(t_map *map);

// src//parsing/map/check_map/check_map_utils.c
bool				check_surroundings(t_map *map);
bool				flood_fill_map(t_map *map, int i, int j);
bool				is_valid(char *arr, char c);
bool				verify_texture(char *path);

// src//parsing/map/check_map/checks_utils.c
bool				check_textures(char *floor, char *ceiling, t_map *map);
bool				check_rgb(char *rgb);
bool				check_range(int nb);
bool				is_player_char(char c);
// src/parsing/map/get_map/get_map.c
void				get_lines(t_data *data, char *file_name);
void				start_buffer(t_data *data);
int					alloc_buffer(t_data *data, int *i);
void				get_map(char *file_name, char **floor, char **ceiling,
						t_data *data);

// src/parsing/get_map/parse_map.c
bool				parse_map(t_data *data, char **floor, char **ceiling);
bool				set_map(t_map *map, int i);
bool				alloc_map(t_map *map, int *i);

// src/parsing/player/init_player.c
void				set_directions(float dir_x, float dir_y, float plane_x,
						t_player *player);
void				init_player(t_data *data);
void				set_player_direction(t_player *p, char dir);

// src/parsing/map/init_map.c
int					init_map(char *file, t_data *data);
bool				set_fc_rgb(char *floor, char *ceiling, t_data *data);

// src/parsing/player/init_player.c
void				init_player(t_data *data);
void				set_player_direction(t_player *player, char dir);

// src/player/move.c
bool				is_wall(t_map *map, float y, float x);
void				move_forward(t_data *data);
void				move_backward(t_data *data);
void				move_left(t_data *data);
void				move_right(t_data *data);

// src/player/render_player.c
void				draw_player_pos(t_player *player, t_img *img);
void				set_bit(uint8_t *var, int bit, bool value);
void				movements(t_data *data);

// src/utils/utils.c
void				close_fds(int i);
size_t				ft_stralen(char **arr);
char				*replace_tabs(char *line);
t_rgb				ft_rgb(uint8_t r, uint8_t g, uint8_t b);
uint8_t				ft_atob(char *str);

// src/utils/frees.c
void				free_arr(char **arr);
void				free_map(t_map *map);
void				free_file(t_file *file);
void				free_mlx(t_mlx *mlx);
void				free_all(t_data *data);

// src/render/color.c
t_rgb				set_rgb(char *strrgb, t_data *data);

// src/render/minimap.c
void				draw_minimap(t_data *data, t_img *img);
void				draw_sq(t_paint paint, t_img *img);

// src/render/render.c
int					render(t_data *data);
void				set_color(t_img *img, size_t y, size_t x, t_rgb cc);

// src/render/paint.c
t_paint				paint_init(void);
t_paint				set_dimensions(t_rgb color, t_paint paint, t_limits begin,
						t_limits end);
t_limits			set_limits(float x, float y);

// src/render/vertice.c
void				compass_setter(t_player *player, t_img *img);

// src/math/init.c
t_rays				dda_init(t_player *player, float angle);

// src/math/dda.c
void				dda(t_player *player, t_map *map, t_img *img);

#endif
