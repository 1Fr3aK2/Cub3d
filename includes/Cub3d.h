/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:52:17 by raamorim          #+#    #+#             */
/*   Updated: 2025/10/23 04:36:31 by rafael           ###   ########.fr       */
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

# define VALID_CHARS "01NSEW"
# define WALL '1'
# define SPACE '0'
# define ORIENTATION "NSEW"
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'

typedef struct s_file
{
	int		fd;
	char	*file_name;
}			t_file;

typedef struct s_map
{
	char	**buffer;
	char	**map;
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

//src/textures/set_textures.c
bool check_load_textures(t_map *map);
bool	set_texture(char *line, t_map *map);
bool alloc_map(t_map *map, int *i);
bool set_map(t_map *map, int i);

// src/init/init.c
void		init_struct(t_data *data);

// src/erros/errors.c
void		exit_error(t_data *data, char *str);
void	free_all(t_data *data);

// src/parsing/file/check_file.c
void		check_map_name(char *file_name);

// src/parsing/map/get_map/get_map.c
void		get_lines(t_data *data, char *file_name);
void		start_buffer(t_data *data);
int			alloc_buffer(t_data *data, int *i);
void		get_map(char *file_name, t_data *data);
void parse_map(t_data *data);

// src/parsing/map/init_map.c
int			init_map(char *file, t_data *data);

// src/utils/utils.c
void		close_fds(int i);
int ft_stralen(char **arr);
void	free_arr(char **arr, int height);
char *replace_tabs(char *line);


#endif