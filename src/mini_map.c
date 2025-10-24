/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:25:37 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/24 15:02:10 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	fill_mini_map(t_all *all, char **map)
{
	int	i;
	int	j;

	i = all->data->player->grid_y;
	j = all->data->player->grid_x;
	map[0][0] = all->data->map[i - 2][j - 2];
	map[0][1] = all->data->map[i - 2][j - 1];
	map[0][2] = all->data->map[i - 2][j];
	map[0][3] = all->data->map[i - 2][j + 1];
	map[0][4] = all->data->map[i - 2][j + 2];
	map[1][0] = all->data->map[i - 1][j - 2];
	map[1][1] = all->data->map[i - 1][j - 1];
	map[1][2] = all->data->map[i - 1][j];
	map[1][3] = all->data->map[i - 1][j + 1];
	map[1][4] = all->data->map[i - 1][j + 2];
	map[2][0] = all->data->map[i][j - 2];
	map[2][1] = all->data->map[i][j - 1];
	map[2][2] = all->data->map[i][j];
	map[2][3] = all->data->map[i][j + 1];
	map[2][4] = all->data->map[i][j + 2];
	map[3][0] = all->data->map[i + 1][j - 2];
	map[3][1] = all->data->map[i + 1][j - 1];
	map[3][2] = all->data->map[i + 1][j];
	map[3][3] = all->data->map[i + 1][j + 1];
	map[3][4] = all->data->map[i + 1][j + 2];
	map[4][0] = all->data->map[i + 2][j - 2];
	map[4][1] = all->data->map[i + 2][j - 1];
	map[4][2] = all->data->map[i + 2][j];
	map[4][3] = all->data->map[i + 2][j + 1];
	map[4][4] = all->data->map[i + 2][j + 2];
	all->minimap->map = map;
}

void	get_map_image(t_all *all)
{
	int	x;
	int	y;
	int	line;
	int	col;

	x = 0;
	y = 0;
	while (y < 200)
	{
		line = y / 40;
		while (x < 200)
		{
			col = x  / 40;
			if(all->minimap->map[line][col] == '1')
			{
				while(x % 40 != 0)
				{
					*(uint32_t *)(all->minimap->addr->addr + (y * all->minimap->addr->line_length
						+ x * (all->minimap->addr->bpp))) = all->minimap->w_color->argb;
					x++;
				}
			}
			else if(x >= 95 && x <= 105 && y >= 95 && y <= 105)
				*(uint32_t *)(all->minimap->addr->addr + (y * all->minimap->addr->line_length
						+ x * (all->minimap->addr->bpp))) = all->minimap->p_color->argb;
			else if(all->minimap->map[line][col] == ' ')
			{
				while(x % 40 != 0)
				{
					*(uint32_t *)(all->minimap->addr->addr + (y * all->minimap->addr->line_length
						+ x * (all->minimap->addr->bpp))) = all->minimap->n_color->argb;
					x++;
				}
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
	all->minimap->f_color = ft_calloc(1, sizeof(t_argb));
	all->minimap->w_color = ft_calloc(1, sizeof(t_argb));
	all->minimap->n_color = ft_calloc(1, sizeof(t_argb));
	all->minimap->addr = ft_calloc(1, sizeof(t_addr));
	all->minimap->image = mlx_new_image(all->mlx->mlx_ptr,
			200, 200);
	all->minimap->addr->addr = mlx_get_data_addr(all->minimap->image,
			&all->minimap->addr->bpp, &all->minimap->addr->line_length, &all->minimap->addr->endian);
	all->minimap->addr->bpp /= 8;
}

void	get_minimap(t_all *all)
{
	int	i;
	char	**map;

	i = 0;
	fill_minimap_colors(all->minimap);
	map = ft_calloc (6, sizeof(char *));
	while(i < 5)
	{
		map[i] = ft_calloc (6, sizeof(char));
		i++;
	}
	fill_mini_map(all, map);
	print_map(all->minimap->map);
	get_map_image(all);
}
