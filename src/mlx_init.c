/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:16:45 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/15 15:40:50 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

char	*dup_img_line(t_all *all, char *img, int start, int end)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = ft_calloc(end - start + 1, sizeof(char));
	if (!cpy)
		error_exit("Error\nmalloc failure\n", all, NULL);
	while (start < end)
	{
		cpy[i] = img[start];
		i++;
		start++;
	}
	return (cpy);
}

void	fill_fc_image(t_all *all, int x, int y)
{
	int		half_height;
	t_argb	color;

	all->addr = mlx_get_data_addr(all->mlx->fc_image,
			&all->bpp, &all->line_length, &all->endian);
	all->bpp /= 8;
	half_height = all->data->screen_height / 2;
	while (y < all->data->screen_height)
	{
		while (x < all->data->screen_width)
		{
			if (y < half_height)
				color = all->mlx->c_color;
			else
				color = all->mlx->f_color;
			*(uint32_t *)(all->addr + (y * all->line_length
						+ x * (all->bpp))) = color.argb;
			x++;
		}
		x = 0;
		y++;
	}
}

void	fill_color_struct(t_all *all)
{
	all->mlx->c_color.a = 255;
	all->mlx->c_color.r = all->texture->ceiling_color->r;
	all->mlx->c_color.g = all->texture->ceiling_color->g;
	all->mlx->c_color.b = all->texture->ceiling_color->b;
	all->mlx->f_color.a = 255;
	all->mlx->f_color.r = all->texture->floor_color->r;
	all->mlx->f_color.g = all->texture->floor_color->g;
	all->mlx->f_color.b = all->texture->floor_color->b;
}

void	display_game(t_all *all, t_mlx *mlx)
{
	all->mlx->fc_image = mlx_new_image(mlx->mlx_ptr,
			all->data->screen_width, all->data->screen_height);
	fill_color_struct(all);
	fill_fc_image(all, 0, 0);
	all->texture->addr_n = malloc(sizeof(t_addr));
	if (!all->texture->addr_n)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->texture->addr_s = malloc(sizeof(t_addr));
	if (!all->texture->addr_s)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->texture->addr_e = malloc(sizeof(t_addr));
	if (!all->texture->addr_e)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->texture->addr_w = malloc(sizeof(t_addr));
	if (!all->texture->addr_w)
		error_exit("Error\nMalloc failure\n", all, NULL);
	get_images(all, all->mlx);
}
