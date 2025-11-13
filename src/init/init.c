/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:22:33 by raamorim          #+#    #+#             */
/*   Updated: 2025/11/13 15:30:38 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	init_struct(t_data *data)
{
	if (!data)
		return ;
	ft_bzero(data, sizeof(t_data));
}

t_data	*data_s(void)
{
	static t_data	data;

	return (&data);
}
