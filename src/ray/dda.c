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
	// printf(RED"x : %d, y : %d\n"RESET, ray->map_x, ray->map_y);
	// printf(YELLOW"side : %d\n"RESET, ray->last_side);
	// printf(BLUE"res : %f\n"RESET, dir_x);
	if (ray->last_side == 0)
	{
		if (roundf(dir_x * 10000) == 0.0f)
			return ((ray->map_x - data->player->pos_x + (1 - ray->step_x) / 2.0f));
		return ((ray->map_x - data->player->pos_x + (1 - ray->step_x) / 2.0f) / dir_x);
	}
	else
		return ((ray->map_y - data->player->pos_y + (1 - ray->step_y) / 2.0f) / dir_y);
}

float	pre_dda(t_data *data)
{
	float	alpha_revised;
	float	res;

	if (data->player->radian < 0)
		data->player->radian = 2.0f - fabsf(data->player->radian);
	alpha_revised = fmodf(data->player->radian + 0.5f, 2.0f);
	data->ray->dir_x = ft_trig(data, alpha_revised, COS);
	data->ray->dir_y = ft_trig(data, alpha_revised, SIN);
	printf("\n");
	printf("dir_x : %f\n", data->ray->dir_x);
	printf("dir_y : %f\n", data->ray->dir_y);
	res = dda(data, data->ray->dir_x, data->ray->dir_y, false);
	side_touched(data);
	return (res);
}
