/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 02:16:26 by rafael            #+#    #+#             */
/*   Updated: 2025/11/04 02:23:12 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void init_mlx(t_data *data)
{
    if (!data)
        return ;
    data->mlx.mlx = mlx_init();
    if (!data->mlx.mlx)
        exit_error(data, "Error creating the conection with mlx");
    data->mlx.win = mlx_new_window(data->mlx.mlx, WIN_W, WIN_H, "Cub3d");
    if (!data->mlx.win)
        exit_error(data, "Error creating the window with mlx");
    data->mlx.img.img = mlx_new_image(data->mlx.mlx, WIN_W, WIN_H);
    if (!data->mlx.img.img)
        exit_error(data, "Error creating the image with mlx");
}