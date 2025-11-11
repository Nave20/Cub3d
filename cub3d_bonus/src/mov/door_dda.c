/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:32:19 by lpaysant          #+#    #+#             */
/*   Updated: 2025/11/11 12:04:39 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

static void	door_dda_loop(t_data *data, t_ray *ray, bool *hit)
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
		|| data->map[ray->map_y][ray->map_x] == 'C'
		|| data->map[ray->map_y][ray->map_x] == 'O')
		*hit = true;
}

float	door_dda(t_data *data, float dir_x, float dir_y)
{
	t_ray	*ray;
	bool	hit;

	ray = data->ray;
	hit = false;
	ray_values(data, dir_x, dir_y);
	while (!hit)
		door_dda_loop(data, ray, &hit);
	if (data->map[ray->map_y][ray->map_x] == 'C'
		|| data->map[ray->map_y][ray->map_x] == 'O')
	{
		ray->door = true;
	}
	return (dda_return(data, dir_x, dir_y));
}
