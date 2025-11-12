/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:47:19 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/12 12:01:55 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	find_player(t_data *data, int i, int j)
{
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				data->player->grid_x = j;
				data->player->grid_y = i;
				data->player->pos_x = j + 0.5f;
				data->player->pos_y = i + 0.5f;
				if (data->map[i][j] == 'E')
					data->player->radian = 0.5f;
				if (data->map[i][j] == 'N')
					data->player->radian = 1.0f;
				if (data->map[i][j] == 'W')
					data->player->radian = 1.5f;
				if (data->map[i][j] == 'S')
					data->player->radian = 0.0f;
			}
			j++;
		}
		i++;
	}
}

int	create_player(t_all *all)
{
	all->data->player = malloc(sizeof(t_player));
	if (!all->data->player)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->data->player->data = all->data;
	find_player(all->data, 0, 0);
	return (0);
}
