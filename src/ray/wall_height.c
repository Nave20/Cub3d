/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:27:53 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/16 15:43:23 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

#define EPSILON 1e-6f
#define ONE_MINUS_EPSILON (1.0f - EPSILON)

float	select_impact(t_data *data)
{
	float diff_x = data->ray->impact_x - (int)data->ray->impact_x;
	float diff_y = data->ray->impact_y - (int)data->ray->impact_y;

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
	render->correct_dist = wall_dist
		* ft_trig(data, ray - data->player->radian, COS);
	render->wall_height = data->screen_height / render->correct_dist;
	render->text_perc = render->wall_height / data->screen_height * 100;
	if (render->text_perc > 100)
		render->text_perc = 100 / (render->text_perc / 100);
	else if (render->text_perc < 100)
		render->text_perc = 100;
	if (render->wall_height >= data->screen_height)
		render->draw_start = 0;
	else
		render->draw_start = (int)(data->screen_height
				- render->wall_height) / 2;
	render->draw_end = data->screen_height - render->draw_start;
	rendering(data->all, render, col);
}
