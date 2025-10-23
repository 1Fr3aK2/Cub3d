/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:39:30 by raamorim          #+#    #+#             */
/*   Updated: 2025/10/23 22:43:47 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

bool check_map(t_map *map)
{
    if (!map)
        return (false);
    int i = 0;
    while(map->map[i])
    {
        printf("%s\n", map->map[i]);
        i++;
    }
    if (check_valid_chars(map) == false)
        return (false);
    return (true);
}

bool check_valid_chars(t_map *map)
{
    int i;
    int j;
    int k;
    
    if (!map || !map->map)
        return (false);
    i = 0;
    while (map->map[i] && i < map->height)
    {
        j = 0;
        while(map->map[i][j])
        {
            k = 0;
            while(VALID_CHARS[k] && map->map[i][j] != VALID_CHARS[k])
                k++;
            if (!VALID_CHARS[k])
                return (false);
            j++;
        }
        i++;       
    }
    return (true);
}