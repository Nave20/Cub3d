/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:27:53 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/12 12:31:58 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

#define EPSILON 1e-6f
#define ONE_MINUS_EPSILON 0.999999f

float	select_impact(t_data *data)
{
	float	diff_x;
	float	diff_y;

	diff_x = data->ray->impact_x - (int)data->ray->impact_x;
	diff_y = data->ray->impact_y - (int)data->ray->impact_y;
	if (fabsf(diff_x) > EPSILON && fabsf(diff_x) < ONE_MINUS_EPSILON)
		return (diff_x);
	else if (fabsf(diff_y) > EPSILON && fabsf(diff_y) < ONE_MINUS_EPSILON)
		return (diff_y);
	else
		return (0.0f);
}

void	wall_height(t_data *data, float wall_dist, int col, float ray)
{
	t_render	*render;

	render = data->render;
	render->correct_dist = fabsf(wall_dist
			* ft_trig(data, data->player->radian - ray, COS));
	render->wall_height = (data->screen_width / 2) / render->correct_dist;
	render->text_perc = render->wall_height / data->screen_height * 100;
	if (render->text_perc > 100)
		render->text_perc = 100 / (render->text_perc / 100);
	else if (render->text_perc < 100)
		render->text_perc = 100;
	if (render->wall_height < data->screen_height)
		render->draw_start = (int)((data->screen_height
					- render->wall_height) / 2.0f);
	else
		render->draw_start = 0;
	render->draw_end = data->screen_height - render->draw_start;
	rendering(data->all, render, col);
}
