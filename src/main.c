/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:49:25 by rafael            #+#    #+#             */
/*   Updated: 2025/11/11 11:13:42 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		ft_putendl_fd("Invalid nmber of arguments", 2);
		return (-1);
	}
	init_struct(&data);
	if (init_map(argv[1], &data) == -1)
		return (-1);
	init_mlx(&data);
	mlx_loop(data.mlx.mlx);
	free_all(&data);
	return (0);
}
