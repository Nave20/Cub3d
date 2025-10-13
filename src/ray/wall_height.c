/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:27:53 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/13 12:27:53 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

float	select_impact(t_data *data)
{
	if (fmodf(data->ray->impact_x * 1000, 1) > 0)
	{
		return (data->ray->impact_x - (int) data->ray->impact_x);
	}
	else if (fmodf(data->ray->impact_y * 1000, 1) > 0)
	{
		return (data->ray->impact_y - (int) data->ray->impact_x);
	}
	else
		return (0);
}

void	wall_height(t_data *data, float wall_dist, int col, float ray)
{
	float	wall_height;
	float	correct_dist;
	float	coef;
	float	draw_start;

	(void) col;
	data->screen_height = 1080;

	printf(BOLD"%f\n"RESET, wall_dist);
	if (fabsf(data->player->radian * 1000) != fabsf(ray * 1000))
		correct_dist = wall_dist * ft_trig(data,(data->player->radian - ray), COS);
	else
		correct_dist = wall_dist;
	printf(PINK"correct_dist = %f\n"RESET, correct_dist);
	wall_height = data->screen_height / correct_dist;

	coef = TEXT_RES / wall_height;
	draw_start = (data->screen_height / 2) - (wall_height / 2);
	printf(BOLD RED"Wall height %f\n"RESET, wall_height);
	if (wall_height > data->screen_height)
		draw_start = fabs((draw_start - (wall_height / 2) + (data->screen_height / 2)) * coef) / 2;
	if (wall_height > data->screen_height)
		wall_height = data->screen_height;
	float draw_end = draw_start + (100.0 - (2 * draw_start));
	printf(ORANGE"Wall height : %f\n COEF : %f\n Draw start : %f\n Draw_end : %f\n"RESET, wall_height, coef, draw_start, draw_end);
	select_impact(data);
}
