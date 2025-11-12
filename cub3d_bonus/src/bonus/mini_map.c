/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:25:37 by lpaysant          #+#    #+#             */
/*   Updated: 2025/11/12 11:56:15 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	fill_minimap_colors(t_minimap *minimap)
{
	minimap->p_color->a = 255;
	minimap->p_color->b = 0;
	minimap->p_color->g = 0;
	minimap->p_color->r = 255;
	minimap->f_color->a = 255;
	minimap->f_color->b = 255;
	minimap->f_color->g = 0;
	minimap->f_color->r = 0;
	minimap->w_color->a = 255;
	minimap->w_color->b = 0;
	minimap->w_color->g = 255;
	minimap->w_color->r = 0;
	minimap->n_color->a = 255;
	minimap->n_color->b = 0;
	minimap->n_color->g = 0;
	minimap->n_color->r = 0;
	minimap->c_color->a = 255;
	minimap->c_color->b = 255;
	minimap->c_color->g = 255;
	minimap->c_color->r = 0;
}

static void	init_minimap_colors(t_all *all)
{
	all->minimap->p_color = ft_calloc(1, sizeof(t_argb));
	if (!all->minimap->p_color)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->minimap->f_color = ft_calloc(1, sizeof(t_argb));
	if (!all->minimap->f_color)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->minimap->w_color = ft_calloc(1, sizeof(t_argb));
	if (!all->minimap->w_color)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->minimap->n_color = ft_calloc(1, sizeof(t_argb));
	if (!all->minimap->n_color)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->minimap->c_color = ft_calloc(1, sizeof(t_argb));
	if (!all->minimap->c_color)
		error_exit("Error\nMalloc failure\n", all, NULL);
}

void	init_minimap(t_all *all)
{
	all->minimap = ft_calloc(1, sizeof(t_minimap));
	if (!all->minimap)
		error_exit("Error\nMalloc failure\n", all, NULL);
	init_minimap_colors(all);
	all->minimap->addr = ft_calloc(1, sizeof(t_addr));
	if (!all->minimap->addr)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->minimap->image = mlx_new_image(all->mlx->mlx_ptr,
			200, 200);
	if (!all->minimap->image)
		error_exit("Error\nMLX new image failure\n", all, NULL);
	all->minimap->addr->addr = mlx_get_data_addr(all->minimap->image,
			&all->minimap->addr->bpp, &all->minimap->addr->line_length,
			&all->minimap->addr->endian);
	if (!all->minimap->addr->addr)
		error_exit("Error\nGet data addr failure\n", all, NULL);
	all->minimap->addr->bpp /= 8;
	fill_minimap_colors(all->minimap);
}
