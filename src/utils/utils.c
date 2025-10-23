/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:42:01 by raamorim          #+#    #+#             */
/*   Updated: 2025/10/23 17:58:48 by rafael           ###   ########.fr       */
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

int ft_stralen(char **arr)
{
    int i;
    
	if (!arr)
        return (0);
    i = 0;
    while (arr[i])
        i++;
    return (i);
}

void	free_arr(char **arr, int height)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < height && arr[i])
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
	if (map->map)
	{
		free_arr(map->map, ft_stralen(map->map));
		map->map = NULL;
	}
	if (map->buffer)
	{
		free_arr(map->buffer, ft_stralen(map->buffer));
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
}

void free_file(t_file *file)
{
	if (!file)
		return ;
	if (file->file_name)
	{
		free(file->file_name);
		file->file_name = NULL;
	}
	if (file->fd >= 0)
		close(file->fd);
	file->fd = -1;
}