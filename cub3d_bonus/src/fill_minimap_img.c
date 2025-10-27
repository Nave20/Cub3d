/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_minimap_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:18:33 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/27 17:19:30 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	put_color_pxl(t_all *all, uint32_t argb, int x, int y)
{
	*(uint32_t *)(all->minimap->addr->addr
			+ (y * all->minimap->addr->line_length
				+ x * (all->minimap->addr->bpp)))
		= argb;
}

void	fill_minimap_lines(t_all *all, float line, int y, int x)
{
	float	col;

	col = ((x - 100.0) / 40.0) + all->data->player->pos_x;
	if (all->data->map[(int)line][(int)col] == '1')
		put_color_pxl(all, all->minimap->w_color->argb, x, y);
	else if (x >= 95 && x <= 105 && y >= 95 && y <= 105)
		put_color_pxl(all, all->minimap->p_color->argb, x, y);
	else if (all->data->map[(int)line][(int)col] == ' ')
		put_color_pxl(all, all->minimap->n_color->argb, x, y);
	else if (all->data->map[(int)line][(int)col] == 'C')
		put_color_pxl(all, all->minimap->c_color->argb, x, y);
	else
		put_color_pxl(all, all->minimap->f_color->argb, x, y);
}

void	fill_minimap_image(t_all *all)
{
	int		x;
	int		y;
	float	line;

	x = 0;
	y = 0;
	while (y < 200)
	{
		line = ((y - 100.0) / 40.0) + all->data->player->pos_y;
		while (x < 200)
		{
			fill_minimap_lines(all, line, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}
