/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:24:16 by htrindad          #+#    #+#             */
/*   Updated: 2025/12/18 00:38:07 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	set_bit(uint8_t *var, int bit, bool value)
{
	if (value)
		*var |= bit;
	else
		*var &= ~bit;
}

static inline bool	side_check(uint8_t keys)
{
	if ((keys & FORWARD && keys & LEFT_S)
		|| (keys & FORWARD && keys & RIGHT_S)
		|| (keys & BACKWARDS && keys & LEFT_S)
		|| (keys & BACKWARDS && keys & RIGHT_S))
		return (true);
	return (false);
}

void	movements(t_data *data)
{
	if (data->keys & FORWARD)
		move_forward(data, side_check(data->keys));
	if (data->keys & BACKWARDS)
		move_backward(data, side_check(data->keys));
	if (data->keys & LEFT_S)
		move_left(data, side_check(data->keys));
	if (data->keys & RIGHT_S)
		move_right(data, side_check(data->keys));
	if (data->keys & TURN_L)
		rotate_left(data);
	if (data->keys & TURN_R)
		rotate_right(data);
}

void	rotate_left(t_data *data)
{
	data->player.plane_x -= ROT;
	data->player.dir_x = cos(data->player.plane_x);
	data->player.dir_y = sin(data->player.plane_x);
}

void	rotate_right(t_data *data)
{
	data->player.plane_x += ROT;
	data->player.dir_x = cos(data->player.plane_x);
	data->player.dir_y = sin(data->player.plane_x);
}
