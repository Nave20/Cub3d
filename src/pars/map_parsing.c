/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:07:44 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/06 15:28:56 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	char_check(t_data *data)
{
	int	i;

	i = 0;
	while(data->map[i])
	{
		if(data->map[i] != ' ' && data->map[i] != '1' && data->map[i] != '0' && data->map[i] != 'N' && data->map[i] != 'S' && data->map[i] != 'W' && data->map[i] != 'O')
		{
			perror(RED "Error\nlist of authorized characters in the map : \n-1\n-0\n-N\n-W\n-S\n-O\n" RESET);
			exit(errno);
		}
	}
}

void	get_map(char **map, t_data *data)
{
	int		lines;
	int		i;

	i = 0;
	lines = 0;
	while (map[lines])
		lines++;
	data->map = ft_calloc(lines, (sizeof(char *)));
	if(!data->map)
	{
		perror(RED "Error\nMalloc failure\n" RESET);
		exit(errno);
	}
	while (map[i])
	{
		data->map[i] = ft_strdup(map[i]);
		if (!data->map[i])
		{
			perror(RED "Error\nMalloc failure\n" RESET);
			exit(errno);
		}
	}
}
