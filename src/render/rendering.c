/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:18:55 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/15 12:07:20 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	yx_converter(t_all *all, t_argb color, int y, int x)
{
	uint32_t	color_bis;

	color_bis = color.argb;
	*(uint32_t *)(all->addr + (y * all->line_length + x * (all->bpp))) = color_bis;
}

t_argb	yx_back_converter(t_addr *addr, int y, int x)
{
	t_argb	color;

	color.argb = *(uint32_t *)(addr->addr + (y * addr->line_length + x * (addr->bpp)));
	return (color);
}


void	render_north(t_all *all, t_render *render, int x, int z)
{
	t_argb	color;
	float	to_draw;
	int		y;
	float	text_to_put;
	float	coef_pix;
	float	lost_pix;
	float	start_on_texture;
	static	float impact = 1;

	lost_pix = 0;
	to_draw = render->draw_end - render->draw_start;
	z = 0;
	y = render->draw_start;
	text_to_put = (render->text_perc / 100) * all->texture->height_e;
	coef_pix = to_draw / text_to_put;
	start_on_texture = (all->texture->height_e - text_to_put) / 2;
	z = (start_on_texture - (int) start_on_texture) * coef_pix;
	color = yx_back_converter(all->texture->addr_e, (int) start_on_texture + (z /
				(int) coef_pix), 100 - (int) render->impact);
	while (y < render->draw_end)
	{
		if (z % (int)coef_pix == 0)
		{
			lost_pix += (coef_pix - (int) coef_pix);
			if ((int) render->impact == 0)
			{
				color = yx_back_converter(all->texture->addr_e, (int) start_on_texture + (z /
				(int) coef_pix), 100 - (int) impact);
			}
			else
				color = yx_back_converter(all->texture->addr_e, (int) start_on_texture + (z /
				(int) coef_pix), 100 - (int) render->impact);
		}
		if (lost_pix >= 1)
		{
			lost_pix -= 1;
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

void	render_south(t_all *all, t_render *render, int x, int z)
{
	t_argb	color;
	float	to_draw;
	int		y;
	float	text_to_put;
	float	coef_pix;
	float	lost_pix;
	float	start_on_texture;
	static	float impact = 1;

	lost_pix = 0;
	to_draw = render->draw_end - render->draw_start;
	z = 0;
	y = render->draw_start;
	text_to_put = (render->text_perc / 100) * all->texture->height_w;
	coef_pix = to_draw / text_to_put;
	start_on_texture = (all->texture->height_w - text_to_put) / 2;
	z = (start_on_texture - (int) start_on_texture) * coef_pix;
	color = yx_back_converter(all->texture->addr_w, (int) start_on_texture + (z /
				(int) coef_pix), 100 - (int) render->impact);
	while (y < render->draw_end)
	{
		if (z % (int)coef_pix == 0)
		{
			lost_pix += (coef_pix - (int) coef_pix);
			if ((int) render->impact == 0)
			{
				color = yx_back_converter(all->texture->addr_w, (int) start_on_texture + (z /
				(int) coef_pix), 100 - (int) impact);
			}
			else
				color = yx_back_converter(all->texture->addr_w, (int) start_on_texture + (z /
				(int) coef_pix), 100 - (int) render->impact);
		}
		if (lost_pix >= 1)
		{
			lost_pix -= 1;
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

void	render_west(t_all *all, t_render *render, int x, int z)
{
	t_argb	color;
	float	to_draw;
	int		y;
	float	text_to_put;
	float	coef_pix;
	float	lost_pix;
	float	start_on_texture;
	static	float impact = 1;

	lost_pix = 0;
	to_draw = render->draw_end - render->draw_start;
	z = 0;
	y = render->draw_start;
	text_to_put = (render->text_perc / 100) * all->texture->height_s;
	coef_pix = to_draw / text_to_put;
	start_on_texture = (all->texture->height_s - text_to_put) / 2;
	z = (start_on_texture - (int) start_on_texture) * coef_pix;
	color = yx_back_converter(all->texture->addr_s, (int) start_on_texture + (z /
				(int) coef_pix), 100 - (int) render->impact);
	while (y < render->draw_end)
	{
		if (z % (int)coef_pix == 0)
		{
			lost_pix += (coef_pix - (int) coef_pix);
			if ((int) render->impact == 0)
			{
				color = yx_back_converter(all->texture->addr_s, (int) start_on_texture + (z /
				(int) coef_pix), 100 - (int) impact);
			}
			else
				color = yx_back_converter(all->texture->addr_s, (int) start_on_texture + (z /
				(int) coef_pix), 100 - (int) render->impact);
		}
		if (lost_pix >= 1)
		{
			lost_pix -= 1;
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

void	render_east(t_all *all, t_render *render, int x, int z)
{
	t_argb	color;
	float	to_draw;
	int		y;
	float	text_to_put;
	float	coef_pix;
	float	lost_pix;
	float	start_on_texture;
	static	float impact = 1;

	lost_pix = 0;
	to_draw = render->draw_end - render->draw_start;
	z = 0;
	y = render->draw_start;
	text_to_put = (render->text_perc / 100) * all->texture->height_n;
	coef_pix = to_draw / text_to_put;
	start_on_texture = (all->texture->height_n - text_to_put) / 2;
	z = (start_on_texture - (int) start_on_texture) * coef_pix;
	color = yx_back_converter(all->texture->addr_n, (int) start_on_texture + (z /
				(int) coef_pix), 100 - (int) render->impact);
	while (y < render->draw_end)
	{
		if (z % (int)coef_pix == 0)
		{
			lost_pix += (coef_pix - (int) coef_pix);
			if ((int) render->impact == 0)
			{
				color = yx_back_converter(all->texture->addr_n, (int) start_on_texture + (z /
				(int) coef_pix), 100 - (int) impact);
			}
			else
				color = yx_back_converter(all->texture->addr_n, (int) start_on_texture + (z /
				(int) coef_pix), 100 - (int) render->impact);
		}
		if (lost_pix >= 1)
		{
			lost_pix -= 1;
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

void	rendering(t_all *all, t_render *render, int x)
{
	if (all->data->ray->side == NORTH)
		render_north(all, render, x, 0);
	else if (all->data->ray->side == SOUTH)
		render_south(all, render, x, 0);
	else if (all->data->ray->side == WEST)
		render_west(all, render, x, 0);
	else if (all->data->ray->side == EAST)
		render_east(all, render, x, 0);
}
