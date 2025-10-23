/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_west.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:51:22 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/16 15:40:17 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"


void	render_west_smallscale(t_all *all, t_render *render, int x)
{
	t_argb	color;
	int		y;

	y = render->draw_start;
	color = yx_back_converter(all->texture->addr_s, 0, x);
	printf("draw_start : %d\n", render->draw_start);
	printf("draw_end : %d\n", render->draw_end);
	// color.a = 255;
	// color.b = 0;
	// color.g = 0;
	// color.r = 255;
	while (y < render->draw_end)
	{
		yx_converter(all, color, y, x);
		y++;
	}
}

t_argb	change_pxl_west(t_all *all, t_render *render, float impact, int z)
{
	t_argb	color;

	(void) impact;
	render->lost_pix += (render->coef_pix - (int) render->coef_pix);
	if ((int) render->impact == 0)
	{
		color = yx_back_converter(all->texture->addr_s,
				(int) render->start_on_texture
				+ (z / (int) render->coef_pix), 100 - (int) impact);
	}
	else
		color = yx_back_converter(all->texture->addr_s,
				(int) render->start_on_texture
				+ (z / (int) render->coef_pix), 100
				- (int) render->impact);
	return (color);
}

void	init_render_west_values(t_all *all, t_render *render,
			int *z, t_argb *color)
{
	render->lost_pix = 0;
	render->to_draw = render->draw_end - render->draw_start;
	render->text_to_put = (render->text_perc / 100) * all->texture->height_s;
	render->coef_pix = render->to_draw / render->text_to_put;
	render->start_on_texture = (all->texture->height_s
			- render->text_to_put) / 2;
	*z = (render->start_on_texture - (int) render->start_on_texture)
		* render->coef_pix;
	if (render->coef_pix > 1)
		*color = yx_back_converter(all->texture->addr_s,
			(int) render->start_on_texture
			+ (*z / (int) render->coef_pix), 100 - (int) render->impact);
}

void	render_west(t_all *all, t_render *render, int x, int z)
{
	t_argb			color;
	static float	impact;
	int				y;

	z = 0;
	init_render_west_values(all, render, &z, &color);
	if (render->coef_pix < 1)
	{
		// dprintf(2, RED"TEST"RESET);
		return (render_west_smallscale(all, render, x));
	}
	y = render->draw_start;
	while (y < render->draw_end)
	{
		if (z % (int)render->coef_pix == 0)
			color = change_pxl_west(all, render, impact, z);
		if (render->lost_pix >= 1)
		{
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
