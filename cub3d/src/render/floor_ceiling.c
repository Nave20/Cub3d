/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:44:24 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/29 12:00:56 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	draw_ceiling(t_all *all, int max, int z)
{
	int		i;
	t_argb	color;

	i = 0;
	color = all->mlx->c_color;
	while (i < max)
	{
		yx_converter(all, color, i, z);
		i++;
	}
}

void	draw_floor(t_all *all, int start, int z)
{
	t_argb	color;

	color = all->mlx->f_color;
	while (start < all->data->screen_height)
	{
		yx_converter(all, color, start, z);
		start++;
	}
}
