/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:31:11 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/28 17:34:16 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

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

void	second_grid_door_check(t_all *all, int x, int y)
{
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
}

void	first_grid_door_check(t_all *all, int x, int y)
{
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
	first_grid_door_check(all, x, y);
	second_grid_door_check(all, x, y);
	update(all);
}
