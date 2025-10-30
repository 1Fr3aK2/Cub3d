/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:52:17 by raamorim          #+#    #+#             */
/*   Updated: 2025/10/30 17:28:43 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft/get_next_line/get_next_line_bonus.h"
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define VALID_CHARS "01NSEW "
# define WALL '1'
# define SPACE '0'
# define ORIENTATION "NSEW"
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'
# define PLAYER "NSWE"

typedef struct s_file
{
	int		fd;
	char	*file_name;
}			t_file;

typedef struct s_map
{
	char	**buffer;
	char	**map;
	char	**temp_map;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		height;
	int		width;
	int		start_pos;
	int		startpos_x;
	int		startpos_y;
}			t_map;

typedef struct s_data
{
	t_map	map;
	t_file	file;
}			t_data;

// src/textures/set_textures.c
bool		check_load_textures(t_map *map);
bool		set_texture(char *line, t_map *map);

// src/init/init.c
void		init_struct(t_data *data);

// src/erros/errors.c
void		exit_error(t_data *data, char *str);
void		free_all(t_data *data);

// src/parsing/file/check_file.c
void		check_map_name(char *file_name);

// src//parsing/map/check_map/check_map.c
bool		check_map(t_map *map);
bool		check_valid_chars(t_map *map);
bool		check_player(t_map *map);
void		set_bool(t_map *map);
bool		alloc_temp_map(t_map *map);

// src//parsing/map/check_map/check_map_utils.c
bool		check_surroundings(t_map *map);
bool		flood_fill_map(t_map *map, int i, int j);
bool		is_valid(char *arr, char c);
bool		verify_texture(char *path);
bool		check_textures(t_map *map);

// src/parsing/map/get_map/get_map.c
void		get_lines(t_data *data, char *file_name);
void		start_buffer(t_data *data);
int			alloc_buffer(t_data *data, int *i);
void		get_map(char *file_name, t_data *data);

// src/parsing/get_map/parse_map.c
bool		parse_map(t_data *data);
bool		set_map(t_map *map, int i);
bool		alloc_map(t_map *map, int *i);

// src/parsing/map/init_map.c
int			init_map(char *file, t_data *data);

// src/utils/utils.c
void		close_fds(int i);
int			ft_stralen(char **arr);
void		free_arr(char **arr, int height);
char		*replace_tabs(char *line);
void		free_map(t_map *map);
void		free_file(t_file *file);

#endif