/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:31:11 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/27 14:31:11 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

float	door_dda(t_data *data, float dir_x, float dir_y)
{
	t_ray	*ray;
	bool	hit;

	ray = data->ray;
	hit = false;
	ray_values(data, dir_x, dir_y);
	while (!hit)
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
		if (data->map[ray->map_y][ray->map_x] == '1' || data->map[ray->map_y][ray->map_x] == 'C' || data->map[ray->map_y][ray->map_x] == 'O')
			hit = true;
	}
	if (data->map[ray->map_y][ray->map_x] == 'C' || data->map[ray->map_y][ray->map_x] == 'O')
	{
		ray->door = true;
	}
	return (dda_return(data, dir_x, dir_y));
}

float	door_detect(t_data *data, float ray)
{
	float	res;

	if (ray < 0)
		ray = 2.0f - fabsf(ray);
	if (ray > 2.0f)
		ray = fmodf(ray, 2.0f);
	data->ray->dir_x = ft_trig(data, ray, SIN);
	data->ray->dir_y = ft_trig(data, ray, COS);
	res = door_dda(data, data->ray->dir_x, data->ray->dir_y);
	side_touched(data, data->ray->last_side,
		data->ray->dir_x, data->ray->dir_y);
	return (res);
}

void	f_key(t_all *all)
{
	int	x;
	int	y;

	door_detect(all->data, all->data->player->radian);
	if (all->data->ray->door != true)
		return ;
	x = all->data->player->pos_x;
	y = all->data->player->pos_y;
	if (all->data->map[y + 1][x] == 'C' || all->data->map[y + 1][x] == 'O')
	{
		if (all->data->map[y + 1][x] == 'C')
			all->data->map[y + 1][x] = 'O';
		else
			all->data->map[y + 1][x] = 'C';
	}
	if (all->data->map[y][x + 1] == 'C' || all->data->map[y][x + 1] == 'O')
	{
		if (all->data->map[y][x + 1] == 'C')
			all->data->map[y][x + 1] = 'O';
		else
			all->data->map[y][x + 1] = 'C';
	}
	if (all->data->map[y - 1][x] == 'C' || all->data->map[y - 1][x] == 'O')
	{
		if (all->data->map[y - 1][x] == 'C')
			all->data->map[y - 1][x] = 'O';
		else
			all->data->map[y - 1][x] = 'C';
	}
	if (all->data->map[y][x - 1] == 'C' || all->data->map[y][x - 1] == 'O')
	{
		if (all->data->map[y][x - 1] == 'C')
			all->data->map[y][x - 1] = 'O';
		else
			all->data->map[y][x - 1] = 'C';
	}
	// update(all);
}
