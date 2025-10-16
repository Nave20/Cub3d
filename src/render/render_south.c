/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_south.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:48:04 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/16 12:50:48 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

t_argb	change_pxl_south(t_all *all, t_render *render, float impact, int z)
{
	t_argb	color;

	render->lost_pix += (render->coef_pix - (int) render->coef_pix);
	if ((int) render->impact == 0)
	{
		color = yx_back_converter(all->texture->addr_w,
				(int) render->start_on_texture
				+ (z / (int) render->coef_pix), 100 - (int) impact);
	}
	else
		color = yx_back_converter(all->texture->addr_w,
				(int) render->start_on_texture
				+ (z / (int) render->coef_pix), 100
				- (int) render->impact);
	return (color);
}

void	init_render_south_values(t_all *all, t_render *render)
{
	render->lost_pix = 0;
	render->to_draw = render->draw_end - render->draw_start;
	render->text_to_put = (render->text_perc / 100) * all->texture->height_w;
	render->coef_pix = render->to_draw / render->text_to_put;
	render->start_on_texture = (all->texture->height_w
			- render->text_to_put) / 2;
}

void	render_south(t_all *all, t_render *render, int x, int z)
{
	t_argb			color;
	static float	impact;
	int				y;
	int				a;

	a = 0;
	impact = 1;
	z = 0;
	init_render_south_values(all, render);
	y = render->draw_start;
	while (y < render->draw_end)
	{
		if (z % (int)render->coef_pix == 0)
			color = change_pxl_south(all, render, impact, z);
		if (render->lost_pix >= 1)
		{
			a++;
			render->lost_pix -= 1;
			yx_converter(all, color, y, x);
			y++;
		}
		yx_converter(all, color, y, x);
		z++;
		y++;
	}
	if (render->impact > 0)
		impact = render->impact;
}
