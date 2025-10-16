/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_north.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:43:55 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/16 15:41:13 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

t_argb	change_pxl_north(t_all *all, t_render *render, float impact, int z)
{
	t_argb	color;

	render->lost_pix += (render->coef_pix - (int) render->coef_pix);
	if ((int) render->impact == 0)
	{
		color = yx_back_converter(all->texture->addr_e,
				(int) render->start_on_texture
				+ (z / (int) render->coef_pix), 100 - (int) impact);
	}
	else
		color = yx_back_converter(all->texture->addr_e,
				(int) render->start_on_texture
				+ (z / (int) render->coef_pix), 100
				- (int) render->impact);
	return (color);
}

void	init_render_north_values(t_all *all, t_render *render,
		int *z, t_argb *color)
{
	render->lost_pix = 0;
	render->to_draw = render->draw_end - render->draw_start;
	render->text_to_put = (render->text_perc / 100) * all->texture->height_e;
	render->coef_pix = render->to_draw / render->text_to_put;
	render->start_on_texture = (all->texture->height_e
			- render->text_to_put) / 2;
	*z = (render->start_on_texture - (int) render->start_on_texture)
		* render->coef_pix;
	*color = yx_back_converter(all->texture->addr_e,
			(int) render->start_on_texture
			+ (*z / (int) render->coef_pix), 100 - (int) render->impact);
}

void	render_north(t_all *all, t_render *render, int x, int z)
{
	t_argb			color;
	static float	impact;
	int				y;
	int				a;

	a = 0;
	impact = 1;
	z = 0;
	init_render_north_values(all, render, &z, &color);
	y = render->draw_start;
	while (y < render->draw_end)
	{
		if (z % (int)render->coef_pix == 0)
			color = change_pxl_north(all, render, impact, z);
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
