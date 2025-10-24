/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:18:55 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/16 15:37:56 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	yx_converter(t_all *all, t_argb color, int y, int x)
{
	uint32_t	color_bis;

	color_bis = color.argb;
	*(uint32_t *)(all->addr + (y * all->line_length
				+ x * (all->bpp))) = color_bis;
}

t_argb	yx_back_converter(t_addr *addr, int y, int x)
{
	t_argb	color;

	color.argb = *(uint32_t *)(addr->addr + (y * addr->line_length
				+ x * (addr->bpp)));
	return (color);
}

void	rendering(t_all *all, t_render *render, int x)
{
	if (all->data->ray->side == NORTH)
		render_n(all, render, x);
	else if (all->data->ray->side == SOUTH)
		render_s(all, render, x);
	else if (all->data->ray->side == WEST)
		render_w(all, render, x);
	else if (all->data->ray->side == EAST)
		render_e(all, render, x);
}
