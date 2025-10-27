/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:31:11 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/27 17:39:04 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	scam_dda_loop(t_data *data, t_ray *ray, bool *hit)
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

float	scam_dda(t_data *data, float dir_x, float dir_y)
{
	t_ray	*ray;
	bool	hit;

	ray = data->ray;
	hit = false;
	ray_values(data, dir_x, dir_y);
	while (!hit)
		scam_dda_loop(data, ray, &hit);
	if (data->map[ray->map_y][ray->map_x] == 'C'
		|| data->map[ray->map_y][ray->map_x] == 'O')
		ray->door = true;
	return (dda_return(data, dir_x, dir_y));
}

float	pre_scam(t_data *data, float ray)
{
	float	res;

	if (ray < 0)
		ray = 2.0f - fabsf(ray);
	if (ray > 2.0f)
		ray = fmodf(ray, 2.0f);
	data->ray->dir_x = ft_trig(data, ray, SIN);
	data->ray->dir_y = ft_trig(data, ray, COS);
	res = scam_dda(data, data->ray->dir_x, data->ray->dir_y);
	side_touched(data, data->ray->last_side,
		data->ray->dir_x, data->ray->dir_y);
	return (res);
}

void	update_map_doors(t_all *all, int y, int x)
{
	if (all->data->map[y][x] == 'C')
		all->data->map[y][x] = 'O';
	else
		all->data->map[y][x] = 'C';
}

void	f_key(t_all *all)
{
	int	x;
	int	y;

	pre_scam(all->data, all->data->player->radian);
	if (all->data->ray->door != true)
		return ;
	x = all->data->player->pos_x;
	y = all->data->player->pos_y;
	if (all->data->map[y + 1][x] == 'C' || all->data->map[y + 1][x] == 'O')
		update_map_doors(all, y + 1, x);
	if (all->data->map[y][x + 1] == 'C' || all->data->map[y][x + 1] == 'O')
		update_map_doors(all, y, x + 1);
	if (all->data->map[y - 1][x] == 'C' || all->data->map[y - 1][x] == 'O')
		update_map_doors(all, y - 1, x);
	if (all->data->map[y][x - 1] == 'C' || all->data->map[y][x - 1] == 'O')
		update_map_doors(all, y, x - 1);
	update(all);
}
