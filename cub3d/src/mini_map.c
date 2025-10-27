/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:25:37 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/27 11:16:27 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	fill_mini_map(t_all *all, char **map)
{
	int	i;
	int	j;
	int	i_m;
	int	j_m;

	i = all->data->player->grid_y - 2;
	i_m = 0;
	while (i_m < 5)
	{
		j_m = 0;
		j = all->data->player->grid_x - 2;
		while (j_m < 5)
		{
			map[i_m][j_m] = all->data->map[i][j];
			j_m++;
			j++;
		}
		i++;
		i_m++;
	}
	all->minimap->map = map;
}

void	get_map_image(t_all *all)
{
	int		x;
	int		y;
	float	line;
	float	col;

	x = 0;
	y = 0;
	while (y < 200)
	{
		line = ((y - 100.0) / 40.0) + all->data->player->pos_y;
		while (x < 200)
		{
			col = ((x - 100.0) / 40.0) + all->data->player->pos_x;
			if (all->data->map[(int)line][(int)col] == '1')
			{
				*(uint32_t *)(all->minimap->addr->addr
						+ (y * all->minimap->addr->line_length
							+ x * (all->minimap->addr->bpp)))
						= all->minimap->w_color->argb;
			}
			else if (x >= 95 && x <= 105 && y >= 95 && y <= 105)
				*(uint32_t *)(all->minimap->addr->addr
						+ (y * all->minimap->addr->line_length
							+ x * (all->minimap->addr->bpp))) = all->minimap->p_color->argb;
			else if (all->data->map[(int)line][(int)col] == ' ')
			{
				*(uint32_t *)(all->minimap->addr->addr + (y * all->minimap->addr->line_length
					+ x * (all->minimap->addr->bpp))) = all->minimap->n_color->argb;
			}
			else
			{
				*(uint32_t *)(all->minimap->addr->addr + (y * all->minimap->addr->line_length
							+ x * (all->minimap->addr->bpp))) = all->minimap->f_color->argb;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	fill_minimap_colors(t_minimap *minimap)
{
	t_argb	*color;

	color = minimap->p_color;
	color->a = 255;
	color->b = 0;
	color->g = 0;
	color->r = 255;
	color = minimap->f_color;
	color->a = 255;
	color->b = 255;
	color->g = 0;
	color->r = 0;
	color = minimap->w_color;
	color->a = 255;
	color->b =0;
	color->g = 255;
	color->r = 0;
	color = minimap->n_color;
	color->a = 255;
	color->b =0;
	color->g = 0;
	color->r = 0;
}

void	init_minimap(t_all *all)
{
	all->minimap = ft_calloc(1, sizeof(t_minimap));
	if (!all->minimap)
		error_exit("Error\nMalloc failure\n", all, NULL);
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
	all->minimap->addr = ft_calloc(1, sizeof(t_addr));
	if (!all->minimap->addr)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->minimap->image = mlx_new_image(all->mlx->mlx_ptr,
			200, 200);
	all->minimap->addr->addr = mlx_get_data_addr(all->minimap->image,
			&all->minimap->addr->bpp, &all->minimap->addr->line_length, &all->minimap->addr->endian);
	all->minimap->addr->bpp /= 8;
}

void	get_minimap(t_all *all)
{
	int		i;
	char	**map;

	i = 0;
	fill_minimap_colors(all->minimap);
	map = ft_calloc (6, sizeof(char *));
	while (i < 5)
	{
		map[i] = ft_calloc (6, sizeof(char));
		i++;
	}
	fill_mini_map(all, map);
	// print_map(all->minimap->map);
	get_map_image(all);
}
