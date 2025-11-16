/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:49:25 by rafael            #+#    #+#             */
/*   Updated: 2025/11/16 17:16:27 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putendl_fd("Invalid nmber of arguments", 2);
		return (-1);
	}
	init_struct(data_s());
	if (init_map(argv[1], data_s()) == -1)
		return (-1);
	init_mlx(data_s());
	mlx_loop(data_s()->mlx.mlx);
	free_all(data_s());
	return (0);
}
