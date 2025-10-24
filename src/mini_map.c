/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:25:37 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/24 10:50:59 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	fill_mini_map(t_all *all, char **map)
{
	int	i;
	int	j;

	i = all->data->player->grid_y;
	j = all->data->player->grid_x;
	map[0][0] = all->data->map[i - 1][j - 1];
	map[0][1] = all->data->map[i - 1][j];
	map[0][2] = all->data->map[i - 1][j + 1];
	map[1][0] = all->data->map[i][j - 1];
	map[1][1] = all->data->map[i][j];
	map[1][2] = all->data->map[i][j + 1];
	map[2][0] = all->data->map[i + 1][j - 1];
	map[2][1] = all->data->map[i + 1][j];
	map[2][2] = all->data->map[i + 1][j + 1];
	all->minimap->map = map;
	print_map(all->minimap->map);
}

void	get_map_image(t_all *all)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	all->minimap->image = mlx_new_image(all->mlx->mlx_ptr,
			204, 204);
	all->addr = mlx_get_data_addr(all->minimap->image,
			&all->bpp, &all->line_length, &all->endian);
	all->bpp /= 8;
	while (y < 204)
	{
		while (x < 204)
		{
			if(x >= 99 && x <= 109 && y >= 99 && y <= 109)
				*(uint32_t *)(all->addr + (y * all->line_length
						+ x * (all->bpp))) = all->minimap->p_color->argb;
			else
				*(uint32_t *)(all->addr + (y * all->line_length
							+ x * (all->bpp))) = all->minimap->f_color->argb;
			x++;
		}
		x = 0;
		y++;
	}
}

void	fill_minimap_colors(t_minimap *minimap)
{
	t_argb	*color;

	minimap->p_color = ft_calloc(1, sizeof(t_argb));
	color = minimap->p_color;
	color->a = 255;
	color->b = 0;
	color->g = 0;
	color->r = 255;
	minimap->f_color = ft_calloc(1, sizeof(t_argb));
	color = minimap->f_color;
	color->a = 255;
	color->b = 255;
	color->g = 0;
	color->r = 0;
}

void	get_minimap(t_all *all)
{
	int	i;
	char	**map;

	i = 0;
	fill_minimap_colors(all->minimap);
	map = ft_calloc (4, sizeof(char *));
	while(i < 3)
	{
		map[i] = ft_calloc (4, sizeof(char));
		i++;
	}
	fill_mini_map(all, map);
	get_map_image(all);
}
