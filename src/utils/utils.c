/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:42:01 by raamorim          #+#    #+#             */
/*   Updated: 2025/11/11 13:28:01 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	close_fds(int i)
{
	i = 3;
	while (i < FOPEN_MAX)
	{
		close(i);
		i++;
	}
}

size_t	ft_stralen(char **arr)
{
	size_t	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	*replace_tabs(char *line)
{
	int	i;

	if (!line)
		return (NULL);
	i = -1;
	while (line[++i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
	}
	return (line);
}

uint32_t	ft_rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return (r << 16 | g << 8 | b);
}

uint8_t	ft_atob(char *str)
{
	uint8_t	n;
	uint8_t	b;
	size_t	i;
	size_t	l;

	n = 0;
	i = 0;
	l = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	while (ft_isdigit((int)str[i]) && l < 4)
	{
		l++;
		b = n * 10 + (str[i] - '0');
		if (b < n)
			return (0);
		n = b;
		i++;
	}
	if (l > 3)
		return (0);
	return (n);
}
