/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:25:37 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/23 16:21:20 by lpaysant         ###   ########.fr       */
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
	t_argb	color;
	int	x;
	int	y;

	x = 0;
	y = 0;
	color.a = 255;
	color.b = 255;
	color.g = 0;
	color.r = 0;
	all->minimap->image = mlx_new_image(all->mlx->mlx_ptr,
			200, 200);
	all->addr = mlx_get_data_addr(all->minimap->image,
			&all->bpp, &all->line_length, &all->endian);
	all->bpp /= 8;
	while (y < 200)
	{
		while (x < 200)
		{
			*(uint32_t *)(all->addr + (y * all->line_length
						+ x * (all->bpp))) = color.argb;
			x++;
		}
		x = 0;
		y++;
	}
}

void	get_minimap(t_all *all)
{
	int	i;
	char	**map;

	i = 0;
	map = ft_calloc (4, sizeof(char *));
	while(i < 3)
	{
		map[i] = ft_calloc (4, sizeof(char));
		i++;
	}
	fill_mini_map(all, map);
	get_map_image(all);
	// mlx_put_image_to_window(all->mlx->mlx_ptr, all->mlx->win_ptr, all->minimap->image, 0, 0);
}
