/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:12:02 by raamorim          #+#    #+#             */
/*   Updated: 2025/11/07 17:28:03 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	check_map_name(char *file_name)
{
	t_file	file;
	int		len;

	if (!file_name)
		exit_error(NULL, "ERROR:\nCHECK_MAP : Invalid pointer to file name");
	file.fd = open(file_name, O_RDONLY);
	if (file.fd < 0)
		exit_error(NULL, "ERROR:\nCHECK_MAP : Error opening the file");
	len = ft_strlen(file_name);
	if (len < 4 || ft_strncmp(&file_name[len - 4], ".cub", 4) != 0)
		exit_error(NULL, "ERROR:\n: Invalid map name, should be .cub");
	close(file.fd);
}