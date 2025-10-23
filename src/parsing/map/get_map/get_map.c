/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:13:21 by raamorim          #+#    #+#             */
/*   Updated: 2025/10/23 18:06:20 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	get_lines(t_data *data, char *file_name)
{
	static char	*line;

	if (!data || !file_name)
		exit_error(NULL, "ERROR:\nGET_LINES: Invalid pointer to file/struct\n");
	data->file.fd = open(file_name, O_RDONLY);
	if (data->file.fd < 0)
		exit_error(NULL, "ERROR:\nGET_LINES : Error opening the file\n");
	line = get_next_line(data->file.fd);
	if (!line)
		exit_error(data, "ERROR:\nGET_LINES: READING 1st LINE OF MAP\n");
	while (line)
	{
		++(data->map.height);
		if (data->map.height == 1)
			data->map.width = (ft_strlen(line) - 1);
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
			"ERROR:\nALLOC_BUFFER: Failed to read first line or empty file\n");
	while (file)
	{
		if (*i < data->map.height)
		{
			trimmed = ft_strtrim(file, "\n");
			free(file);
			if (!trimmed)
				exit_error(data,
					"ERROR:\nALLOC_BUFFER: strtrim malloc error\n");
			data->map.buffer[*i] = trimmed;
			if (!data->map.buffer[*i])
				exit_error(data, "ERROR:\nALLOC_BUFFER: strdup/alloc error\n");
			file = get_next_line(data->file.fd);
		}
		(*i)++;
	}
	return (1);
}

void	get_map(char *file_name, t_data *data)
{
	int	i;

	i = 0;
	if (!file_name || !data || data->map.height <= 0)
		exit_error(NULL, "ERROR:\nGET_MAP: Inv pointer file/struct\n");
	data->file.fd = open(file_name, O_RDONLY);
	if (data->file.fd < 0)
		exit_error(NULL, "ERROR:\nGET_MAP : Error opening the file\n");
	data->map.buffer = malloc(sizeof(char *) * (data->map.height + 1));
	if (!data->map.buffer)
		exit_error(NULL, "ERROR:\nGET_MAP : Memory allocation error\n");
	start_buffer(data);
	if (alloc_buffer(data, &i) != 1)
		exit_error(data, "ERROR:\n GET_MAP ERROR W/ALLOC BUFFER\n");
	if (parse_map(data) == false);
		exit_error(data, "ERROR:\n GET_MAP ERROR W/PARSE_MAP\n");
	close(data->file.fd);
	/* if (i != data->map.height)
		exit_error(data, "ERROR:\nGET_MAP : expected != real lines\n"); */
}

