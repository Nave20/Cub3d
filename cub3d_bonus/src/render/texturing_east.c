/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing_east.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:04:08 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/12 11:56:15 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

#define EPSILON 1e-6f

static void	init_render_e(t_all *all, t_render *render)
{
	if (render->wall_height < EPSILON)
	{
		render->coef_pix = 0.0f;
		render->start_on_texture = 0.0f;
		return ;
	}
	render->coef_pix = (float)all->data->texture->height_e
		/ (float)render->wall_height;
	render->start_on_texture = ((float)render->draw_start
			- (float)all->data->screen_height / 2.0f
			+ render->wall_height / 2.0f) * render->coef_pix;
	render->to_draw = (float)render->draw_end - (float)render->draw_start;
	render->impact = (float)all->data->texture->width_e
		- select_impact(all->data)
		* (float)all->data->texture->width_e;
}

static void	pixel_loop_e(t_all *all, t_render *render, float texpos, int x)
{
	t_argb	color;
	int		i;

	i = render->draw_start;
	while (i < render->draw_end)
	{
		render->tex_y = ((int)texpos);
		render->tex_y = render->tex_y % all->data->texture->height_e;
		if (render->tex_y < 0)
			render->tex_y += all->data->texture->height_e;
		texpos += render->coef_pix;
		color = yx_back_converter(all->texture->addr_e,
				render->tex_y, render->tex_x);
		yx_converter(all, color, i, x);
		i++;
	}
}

void	render_e(t_all *all, t_render *render, int x)
{
	float	texpos;

	init_render_e(all, render);
	texpos = render->start_on_texture;
	render->tex_x = (int)render->impact;
	if (render->coef_pix == 0.0f)
	{
		draw_ceiling(all, all->data->screen_height, x);
		draw_floor(all, 0, x);
		return ;
	}
	draw_ceiling(all, render->draw_start, x);
	if (render->tex_x >= all->data->texture->width_e)
		render->tex_x = all->data->texture->width_e - 1;
	if (render->tex_x < 0)
		render->tex_x = 0;
	pixel_loop_e(all, render, texpos, x);
	draw_floor(all, render->draw_end, x);
}
