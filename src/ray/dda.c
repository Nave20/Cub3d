/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:39:38 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/11 11:39:38 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

float	side_x(t_data *data, float dir_x, float delta_x)
{
	t_ray		*ray;

	ray = data->ray;
	if (dir_x < 0.0f)
	{
		ray->step_x = -1;
		return ((data->player->pos_x - data->player->grid_x) * delta_x);
	}
	else
	{
		ray->step_x = 1;
		return ((data->player->pos_x - data->player->grid_x + 1.0f)
			* delta_x);
	}
}

float	side_y(t_data *data, float dir_y, float delta_y)
{
	t_ray		*ray;

	ray = data->ray;
	if (dir_y < 0.0f)
	{
		ray->step_y = -1;
		return ((data->player->pos_y - data->player->grid_y) * delta_y);
	}
	else
	{
		ray->step_y = 1;
		return ((data->player->pos_y - data->player->grid_y + 1.0f)
			* delta_y);
	}
}

void	ray_values(t_data *data, float dir_x, float dir_y)
{
	t_ray		*ray;

	ray = data->ray;
	ray->delta_x = fabsf(1.0f / dir_x);
	ray->delta_y = fabsf(1.0f / dir_y);
	ray->side_x = side_x(data, dir_x, ray->delta_x);
	ray->side_y = side_y(data, dir_y, ray->delta_y);
	ray->map_x = data->player->grid_x;
	ray->map_y = data->player->grid_y;
}

float	dda(t_data *data, float dir_x, float dir_y, bool hit)
{
	t_ray	*ray;

	ray = data->ray;
	ray_values(data, dir_x, dir_y);
	while (hit == false)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->last_side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->last_side = 1;
		}
		if (data->map[ray->map_x][ray->map_y] == '1')
			hit = true;
	}
	if (ray->last_side == 0)
		return ((ray->map_x - data->player->pos_x + (1 - ray->step_x) / 2.0f) / dir_x);
	else
		return ((ray->map_y - data->player->pos_y + (1 - ray->step_y) / 2.0f) / dir_y);
}

float	pre_dda(t_data *data)
{
	float	dir_x;
	float	dir_y;
	float	alpha_revised;

	if (data->player->radian < 0)
		data->player->radian = 2.0f - fabsf(data->player->radian);
	alpha_revised = fmodf(data->player->radian + 0.5f, 2.0f);
	dir_x = data->f_cos[(int)((alpha_revised) * PI * TRIG_TABLE / TWOPI)];
	dir_y = data->f_sin[(int)((alpha_revised) * PI * TRIG_TABLE / TWOPI)];
	return (dda(data, dir_x, dir_y, false));
}
