/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 02:16:26 by rafael            #+#    #+#             */
/*   Updated: 2025/11/05 01:04:05 by rafael           ###   ########.fr       */
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
    mlx_hook(data->mlx.win, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->mlx.win, DestroyNotify, StructureNotifyMask, press_x, data);
}