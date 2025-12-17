/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:24:16 by htrindad          #+#    #+#             */
/*   Updated: 2025/12/16 19:17:46 by htrindad         ###   ########.fr       */
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

void	movements(t_data *data)
{
	if (data->keys & FORWARD)
		move_forward(data);
	if (data->keys & BACKWARDS)
		move_backward(data);
	if (data->keys & LEFT_S)
		move_left(data);
	if (data->keys & RIGHT_S)
		move_right(data);
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
