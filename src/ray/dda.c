/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:39:38 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/16 11:17:11 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

#define EPSILON 1e-6f
#define HUGE 1e30f

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

void	ray_values(t_data *data, float dir_x, float dir_y)
{
	t_ray	*ray;

	ray = data->ray;
	ray->map_x = data->player->grid_x;
	ray->map_y = data->player->grid_y;
	// if (fabsf(dir_x) < EPSILON)
	// 	ray->delta_x = HUGE;
	// else
	// 	ray->delta_x = fabsf(1.0f / dir_x);
	//
	// if (fabsf(dir_y) < EPSILON)
	// 	ray->delta_y = HUGE;
	// else
	// 	ray->delta_y = fabsf(1.0f / dir_y);
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
	// printf(BLUE"last side : %d\n"RESET, ray->last_side);
	// printf(RED"ray_step_x : %d ray_step_y : %d\n"RESET, ray->step_x, ray->step_y);
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

float	dda(t_data *data, float dir_x, float dir_y)
{
	t_ray	*ray;
	bool	hit;

	ray = data->ray;
	hit = false;
	ray_values(data, dir_x, dir_y);
	// printf(GREEN"delta x : %f, delta y : %f\n"RESET, ray->delta_x, ray->delta_y);
	while (!hit)
	{
		// printf(YELLOW"side x : %f, side y : %f \n"RESET, ray->side_x, ray->side_y);
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
		if (data->map[ray->map_y][ray->map_x] == '1')
			hit = true;
	}
	// printf(CYAN"X = %d, Y = %d\n", ray->map_x, ray->map_y);
	return (dda_return(data, dir_x, dir_y));
}
