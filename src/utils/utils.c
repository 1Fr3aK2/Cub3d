/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:42:01 by raamorim          #+#    #+#             */
/*   Updated: 2025/11/10 10:42:20 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	close_fds(int i)
{
	i = 3;
	while (i < FOPEN_MAX)
	{
		close(i);
		i++;
	}
}

size_t ft_stralen(char **arr)
{
    size_t i;
    
	if (!arr)
        return (0);
    i = 0;
    while (arr[i])
        i++;
    return (i);
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

char *replace_tabs(char *line)
{
	int i;
	
	if (!line)
		return (NULL);
	i = -1;
	while (line[++i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
	}
	return (line);
	
}

void free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->buffer)
	{
		free_arr(map->buffer);
		map->buffer = NULL;
	}
	if (map->north)
	{
		free(map->north);
		map->north = NULL;
	}
	if (map->south)
	{
		free(map->south);
		map->south = NULL;
	}
	if (map->east)
	{
		free(map->east);
		map->east = NULL;
	}
	if (map->west)
	{
		free(map->west);
		map->west = NULL;
	}
	if (map->floor)
	{
		free(map->floor);
		map->floor = NULL;
	}
	if (map->ceiling)
	{
		free(map->ceiling);
		map->ceiling = NULL;
	}
	if (map->temp_map)
	{
		free_arr(map->temp_map);
		map->temp_map = NULL;
	}
}

void free_file(t_file *file)
{
	if (!file)
		return ;
	if (file->fd >= 0)
		close(file->fd);
	file->fd = -1;
}

void free_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->img.img)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx->img.img = NULL;	
	}
	if (mlx->win)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx->win = NULL;
	}
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		mlx->mlx = NULL;
	}
}

uint32_t ft_rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return (r << 16 | g << 8 | b);
}

uint8_t	ft_atob(char *str)
{
	uint8_t	n;
	uint8_t	b;
	size_t	i;
	size_t	l;

	n = 0;
	i = 0;
	l = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	while (ft_isdigit((int)str[i]) && l < 4)
	{
		l++;
		b = n * 10 + (str[i] - '0');
		if (b < n)
			return (0);
		n = b;
		i++;
	}
	if (l > 3)
		return (0);
	return (n);
}
