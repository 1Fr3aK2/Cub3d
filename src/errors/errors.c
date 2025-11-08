/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:15:03 by raamorim          #+#    #+#             */
/*   Updated: 2025/11/08 03:58:44 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	exit_error(t_data *data, char *str)
{
	if (!str)
		ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	if (data)
	{
		free_all(data);
		data = NULL;
	}
	close_fds(0);
	exit(1);
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_mlx(&data->mlx);
	free_map(&data->map);
	free_file(&data->file);
	// free_animations(data);
	// free_images(data);
	// free_player(data);
	// free_enemy(data);
}
