/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:21:42 by rafael            #+#    #+#             */
/*   Updated: 2025/11/07 17:25:00 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

int	handle_keypress(int key, t_data *data)
{
	if (!data)
		return (0);

	if (key == XK_w)
		move_forward(data);
	else if (key == XK_s)
		move_backward(data);
	else if (key == XK_a)
		move_left(data);
	else if (key == XK_d)
		move_right(data);
	else if (key == XK_Escape)
        exit_error(data, "GAME OVER!");
	return (0);
}

int	press_x(t_data *data)
{
	exit_error(data, "GAME OVER!");
	return (0);
}
