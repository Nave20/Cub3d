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

float	select_impact(t_data *data)
{
	if ((data->ray->impact_x - (int) data->ray->impact_x) > 0)
	{
		return (data->ray->impact_x - (int) data->ray->impact_x);
	}
	else if ((data->ray->impact_y - (int) data->ray->impact_y) > 0)
	{
		return (data->ray->impact_y - (int) data->ray->impact_y);
	}
	else
	{
		return (0);
	}
}

float	select_impact_side(t_data *data, t_side side)
{
	if (side == NORTH)
		return (roundf(select_impact(data) * data->texture->width_n));
	else if (side == SOUTH)
		return (100 - roundf(select_impact(data) * data->texture->width_s));
	else if (side == EAST)
		return (roundf(select_impact(data) * data->texture->width_e));
	else
		return (100 - roundf(select_impact(data) * data->texture->width_w));
}

void	wall_height(t_data *data, float wall_dist, int col, float ray)
{
	t_render	*render;

	render = data->render;
	// (void) ray;
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
	render->impact = select_impact_side(data, data->ray->side);
	// printf("ray : %f\n", ray);
	rendering(data->all, render, col);
}
