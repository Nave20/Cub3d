/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:39:38 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/27 17:44:33 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

#define EPSILON 1e-6f
#define HUGE 1e30f

void	ray_values(t_data *data, float dir_x, float dir_y)
{
	t_ray	*ray;

	ray = data->ray;
	ray->door = false;
	ray->map_x = data->player->grid_x;
	ray->map_y = data->player->grid_y;
	ray->delta_x = fabsf(1.0f / dir_x);
	ray->delta_y = fabsf(1.0f / dir_y);
	ray->side_x = side_x(data, dir_x, ray->delta_x);
	ray->side_y = side_y(data, dir_y, ray->delta_y);
}

float	dda_return(t_data *data, float dir_x, float dir_y)
{
	float	wall_dist;
	t_ray	*ray;

	ray = data->ray;
	if (ray->last_side == 0)
	{
		wall_dist = (ray->map_x - data->player->pos_x
				+ (1 - ray->step_x) / 2.0f) / dir_x;
	}
	else
	{
		wall_dist = (ray->map_y - data->player->pos_y
				+ (1 - ray->step_y) / 2.0f) / dir_y;
	}
	return (fabsf(wall_dist));
}

void	dda_loop(t_data *data, t_ray *ray, bool *hit)
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
	if (data->map[ray->map_y][ray->map_x] == '1'
		|| data->map[ray->map_y][ray->map_x] == 'C')
		*hit = true;
}

float	dda(t_data *data, float dir_x, float dir_y)
{
	t_ray	*ray;
	bool	hit;

	ray = data->ray;
	hit = false;
	ray_values(data, dir_x, dir_y);
	while (!hit)
		dda_loop(data, ray, &hit);
	if (data->map[ray->map_y][ray->map_x] == 'C')
	{
		ray->door = true;
	}
	return (dda_return(data, dir_x, dir_y));
}
