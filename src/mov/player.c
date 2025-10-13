/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:47:19 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/09 09:47:31 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	find_player(t_data *data, int i, int j)
{
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				data->player->grid_y = i;
				data->player->grid_x = j;
				data->player->pos_x = i;
				data->player->pos_y = j;
				if (data->map[i][j] == 'E')
					data->player->radian = 0.0f;
				if (data->map[i][j] == 'N')
					data->player->radian = 0.5f;
				if (data->map[i][j] == 'W')
					data->player->radian = 1.0f;
				if (data->map[i][j] == 'S')
					data->player->radian = 1.5f;
			}
			j++;
		}
		i++;
	}
}

int	create_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
	{
		perror(RED"Error\n -> allocating memory"RESET);
		return (1);
	}
	data->player->data = data;
	find_player(data, 0, 0);
	return (0);
}
