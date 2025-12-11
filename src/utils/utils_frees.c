/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_frees.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 02:40:48 by rafael            #+#    #+#             */
/*   Updated: 2025/12/11 02:42:38 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

static void	free_single_texture(t_img *texture)
{
	if (!texture)
		return ;
	if (texture->img && data_s()->mlx.mlx)
	{
		mlx_destroy_image(data_s()->mlx.mlx, texture->img);
		texture->img = NULL;
	}
	if (texture->path)
	{
		free(texture->path);
		texture->path = NULL;
	}
	texture->pixel_ptr = NULL;
}

void	free_textures(t_assets *assets)
{
	int	i;

	if (!assets)
		return ;
	i = 0;
	while (i < TEXTURE_COUNT)
	{
		free_single_texture(&assets->textures[i]);
		i++;
	}
}
