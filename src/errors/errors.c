/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:15:03 by raamorim          #+#    #+#             */
/*   Updated: 2025/11/03 18:32:35 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	exit_error(t_data *data, char *str)
{
	if (!str)
		ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	if (data)
	{
		free_all(data);
		/* if (data->map.map)
			free_arr(data->map.map, data->map.height); */
		// if (data->window_ptr)
		// 	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		// if (data->mlx_ptr)
		// {
		// 	mlx_destroy_display(data->mlx_ptr);
		// 	free(data->mlx_ptr);
		// }
		data = NULL;
	}
	close_fds(0);
	exit(1);
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_map(&data->map);
	free_file(&data->file);
	// free_animations(data);
	// free_images(data);
	// free_player(data);
	// free_enemy(data);
}
