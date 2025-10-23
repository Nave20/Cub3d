/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing_west.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:39:01 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/23 10:39:01 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

#define EPSILON 1e-6f

void	init_render(t_all *all, t_render *render)
{
    if (render->wall_height < EPSILON)
    {
        render->coef_pix = 0.0f;
        render->start_on_texture = 0.0f;
        return;
    }
	render->coef_pix = all->data->texture->height_s / render->wall_height;
	render->start_on_texture =
          (render->draw_start - (float)all->data->screen_height / 2.0f + render->wall_height / 2.0f)
          * render->coef_pix;
	render->to_draw = render->draw_end - render->draw_start;
}

void	render_w(t_all *all, t_render *render, int x)
{
	float	texPos;
	int		i;
	int     texY;
	t_argb	color;
	int     texX;

	init_render(all, render);
	i = render->draw_start;
	if (render->coef_pix == 0.0f)
	{
		draw_ceiling(all, all->data->screen_height, x);
		draw_floor(all, 0, x);
		return;
	}
	draw_ceiling(all, render->draw_start, x);
	texPos = render->start_on_texture;
	float test = select_impact(all->data) * all->data->texture->width_s;
	texX = (int)test;
	if (texX >= all->data->texture->width_s)
		texX = all->data->texture->width_s - 1;
	if (texX < 0)
        texX = 0;
	while (i < render->draw_end)
	{
        texY = ((int)texPos);
        texY = texY % all->data->texture->height_s;
        if (texY < 0)
            texY += all->data->texture->height_s;
		texPos += render->coef_pix;
		color = yx_back_converter(all->texture->addr_s, texY, texX);
		yx_converter(all, color, i, x);
		i++;
	}
	draw_floor(all, render->draw_end, x);
}
