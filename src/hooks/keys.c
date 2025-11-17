/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:21:42 by rafael            #+#    #+#             */
/*   Updated: 2025/11/17 14:33:18 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

int	handle_keypress(int key, t_data *data)
{
	if (key == XK_w)
		set_bit(&data->keys, FORWARD, true);
	else if (key == XK_s)
		set_bit(&data->keys, BACKWARDS, true);
	else if (key == XK_a)
		set_bit(&data->keys, LEFT_S, true);
	else if (key == XK_d)
		set_bit(&data->keys, RIGHT_S, true);
	else if (key == XK_Left)
		set_bit(&data->keys, TURN_L, true);
	else if (key == XK_Right)
		set_bit(&data->keys, TURN_R, true);
	else if (key == XK_Escape)
		exit_error(data, "GAME OVER!");
	return (0);
}

int	handle_keyrelease(int key, t_data *data)
{
	if (key == XK_w)
		set_bit(&data->keys, FORWARD, false);
	else if (key == XK_s)
		set_bit(&data->keys, BACKWARDS, false);
	else if (key == XK_a)
		set_bit(&data->keys, LEFT_S, false);
	else if (key == XK_d)
		set_bit(&data->keys, RIGHT_S, false);
	else if (key == XK_Left)
		set_bit(&data->keys, TURN_L, false);
	else if (key == XK_Right)
		set_bit(&data->keys, TURN_R, false);
	return (0);
}

int	press_x(t_data *data)
{
	exit_error(data, "GAME OVER!");
	return (0);
}
