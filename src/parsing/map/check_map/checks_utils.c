/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:37:35 by raamorim          #+#    #+#             */
/*   Updated: 2025/12/02 16:57:35 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

bool	check_textures(char *floor, char *ceiling, t_map *map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (!map->textures[i].path)
			return (false);
		if (!verify_texture(map->textures[i].path))
			return (false);
		i++;
	}
	if (!check_rgb(floor))
		return (false);
	if (!check_rgb(ceiling))
		return (false);
	return (true);
}


bool	check_rgb(char *rgb)
{
	char	**arr;

	if (!rgb)
		return (false);
	arr = ft_split(rgb, ',');
	if (!arr)
		return (free(rgb), false);
	if (ft_stralen(arr) != 3)
	{
		free_arr(arr);
		return (free(rgb), false);
	}
	if (!ft_isnumber(arr[0]) || !ft_isnumber(arr[1]) || !ft_isnumber(arr[2]))
		return (false);
	if (!check_range(ft_atoi(arr[0])) || !check_range(ft_atoi(arr[1]))
		|| !check_range(ft_atoi(arr[2])))
	{
		free_arr(arr);
		return (false);
	}
	free_arr(arr);
	return (true);
}

bool	check_range(int nb)
{
	if (nb < 0 || nb > 255)
		return (false);
	return (true);
}

bool	is_player_char(char c)
{
	int	i;

	i = 0;
	while (PLAYER[i])
	{
		if (c == PLAYER[i])
			return (true);
		i++;
	}
	return (false);
}
