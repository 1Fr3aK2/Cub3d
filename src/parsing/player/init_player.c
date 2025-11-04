/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 00:07:28 by rafael            #+#    #+#             */
/*   Updated: 2025/11/04 00:07:56 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	set_player_direction(t_player *p, char dir)
{
	if (dir == 'N')
	{
		p->dir_x = 0;
		p->dir_y = -1;
		p->plane_x = 0.66;
		p->plane_y = 0;
	}
	else if (dir == 'S')
	{
		p->dir_x = 0;
		p->dir_y = 1;
		p->plane_x = -0.66;
		p->plane_y = 0;
	}
	else if (dir == 'E')
	{
		p->dir_x = 1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		p->dir_x = -1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = -0.66;
	}
}


void	init_player(t_data *data)
{
	int		y;
	int		x;
	char	dir;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			dir = data->map.map[y][x];
			if (ft_strchr("NSEW", dir))
			{
				data->player.x = x + 0.5;
				data->player.y = y + 0.5;
				set_player_direction(&data->player, dir);
				data->map.map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
	ft_putendl_fd("ERROR:\nplayer not found in map", 2);
	exit(1);
}
