/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:15:03 by raamorim          #+#    #+#             */
/*   Updated: 2025/12/18 15:01:33 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	exit_error(t_data *data, char *str)
{
	if (!data)
		return ;
	if (!str)
		ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	if (data)
	{
		free_all(data);
		data = NULL;
	}
	close_fds(0);
	exit(1);
}
