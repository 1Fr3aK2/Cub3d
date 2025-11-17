/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 00:07:28 by rafael            #+#    #+#             */
/*   Updated: 2025/11/17 17:42:09 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	set_player_direction(t_player *player, char dir)
{
	(void)player;
	if (dir == 'N')
		set_directions(cos(3 * PI / 2), sin(3 * PI / 2), 3 * PI / 2, player);
	else if (dir == 'S')
		set_directions(cos(PI / 2), sin(PI / 2), PI / 2, player);
	else if (dir == 'E')
		set_directions(cos(2 * PI), sin(2 * PI), 2 * PI, player);
	else if (dir == 'W')
		set_directions(cos(PI), sin(PI), PI, player);
}

void	set_directions(float dir_x, float dir_y, float plane_x,
		t_player *player)
{
	player->dir_x = dir_x;
	player->dir_y = dir_y;
	player->plane_x = plane_x;
	if (player->plane_x < 0)
		player->plane_x += 2 * PI;
	else if (player->plane_x > 2 * PI)
		player->plane_x -= 2 * PI;
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
