/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:13:21 by raamorim          #+#    #+#             */
/*   Updated: 2025/12/09 17:18:12 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	get_lines(t_data *data, char *file_name)
{
	static char	*line;

	if (!data || !file_name)
		exit_error(NULL, "ERROR:\nGET_LINES: Invalid pointer to file/struct");
	data->file.fd = open(file_name, O_RDONLY);
	if (data->file.fd < 0)
		exit_error(NULL, "ERROR:\nGET_LINES : Error opening the file");
	line = get_next_line(data->file.fd);
	if (!line)
		exit_error(data, "ERROR:\nGET_LINES: READING 1st LINE OF MAP");
	while (line)
	{
		++(data->map.height);
		free(line);
		line = get_next_line(data->file.fd);
	}
	close(data->file.fd);
}

void	start_buffer(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		return ;
	while (i < data->map.height + 1)
	{
		data->map.buffer[i] = NULL;
		i++;
	}
}

int	alloc_buffer(t_data *data, int *i)
{
	char	*file;
	char	*trimmed;

	if (!data)
		return (-1);
	file = get_next_line(data->file.fd);
	if (!file)
		exit_error(data,
			"ERROR:\nALLOC_BUFFER: Failed to read first line or empty file");
	while (file)
	{
		if (*i < data->map.height)
		{
			trimmed = ft_strtrim(file, "\n");
			free(file);
			if (!trimmed)
				exit_error(data, "ERROR:\nALLOC_BUFFER: strtrim malloc error");
			data->map.buffer[*i] = trimmed;
			if (!data->map.buffer[*i])
				exit_error(data, "ERROR:\nALLOC_BUFFER: strdup/alloc error");
			file = get_next_line(data->file.fd);
		}
		(*i)++;
	}
	return (1);
}

void	get_map(char *file_name, char **floor, char **ceiling, t_data *data)
{
	int	i;

	i = 0;
	if (!file_name || !data || data->map.height <= 0)
		return ;
	data->file.fd = open(file_name, O_RDONLY);
	if (data->file.fd < 0)
		return ;
	data->map.buffer = malloc(sizeof(char *) * (data->map.height + 1));
	if (!data->map.buffer)
		return ;
	start_buffer(data);
	if (alloc_buffer(data, &i) != 1)
		return ;
	if (!parse_map(data, floor, ceiling))
		return ;
	close(data->file.fd);
}
