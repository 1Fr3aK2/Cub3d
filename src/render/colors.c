/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:50:04 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/08 18:09:48 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

t_rgb	set_rgb(char *floor, t_data *data)
{
	char	**floor_bi;
	uint8_t	rgb[3];
	size_t	i;

	floor_bi = ft_split(floor, ',');
	if (floor == NULL)
		exit_error(data, "ERROR: Malloc fail");
	i = -1;
	while (++i < 3)
		rgb[i] = ft_atob(floor_bi[i]);
	free_arr(floor_bi);
	return (ft_rgb(rgb[0], rgb[1], rgb[2]));
}
