/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:43:51 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/27 17:44:25 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

float	side_x(t_data *data, float dir_x, float delta_x)
{
	t_ray	*ray;

	ray = data->ray;
	if (dir_x < 0.0f)
	{
		ray->step_x = -1;
		return ((data->player->pos_x - ray->map_x) * delta_x);
	}
	else
	{
		ray->step_x = 1;
		return ((ray->map_x + 1.0f - data->player->pos_x) * delta_x);
	}
}

float	side_y(t_data *data, float dir_y, float delta_y)
{
	t_ray	*ray;

	ray = data->ray;
	if (dir_y < 0.0f)
	{
		ray->step_y = -1;
		return ((data->player->pos_y - ray->map_y) * delta_y);
	}
	else
	{
		ray->step_y = 1;
		return ((ray->map_y + 1.0f - data->player->pos_y) * delta_y);
	}
}
