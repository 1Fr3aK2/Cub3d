/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 00:07:28 by rafael            #+#    #+#             */
/*   Updated: 2025/11/17 14:33:51 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	set_player_direction(t_player *player, char dir)
{
	(void)player;
	if (dir == 'N')
		set_directions(0, -1, 0.66, player);
	else if (dir == 'S')
		set_directions(0, 1, -0.66, player);
	else if (dir == 'E')
		set_directions(1, 0, 0, player);
	else if (dir == 'W')
		set_directions(-1, 0, 0, player);
}

void	set_directions(float dir_x, float dir_y, float plane_x,
		t_player *player)
{
	player->dir_x = dir_x;
	player->dir_y = dir_y;
	player->plane_x = plane_x;
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
	exit_error(data, "ERROR:\nplayer not found in map");
}
