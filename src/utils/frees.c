/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:26:56 by raamorim          #+#    #+#             */
/*   Updated: 2025/12/03 17:04:57 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

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

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->buffer)
		free_arr(map->buffer);
	i = 0;
	while (i < 4)
	{
		if (map->textures[i].id)
			free(map->textures[i].id);
		if (map->textures[i].path)
			free(map->textures[i].path);
		i++;
	}
	if (map->temp_map)
		free_arr(map->temp_map);
}

void	free_file(t_file *file)
{
	if (!file)
		return ;
	if (file->fd >= 0)
		close(file->fd);
	file->fd = -1;
}

void	free_mlx(t_mlx *mlx)
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

void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_mlx(&data->mlx);
	free_map(&data->map);
	free_file(&data->file);
}
