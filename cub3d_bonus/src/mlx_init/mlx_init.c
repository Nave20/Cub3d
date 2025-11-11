/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:16:45 by lpaysant          #+#    #+#             */
/*   Updated: 2025/11/11 14:11:07 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	get_screen_size(t_all *all)
{
	int	x;
	int	y;

	all->mlx->mlx_ptr = mlx_init();
	mlx_get_screen_size(all->mlx->mlx_ptr, &x, &y);
	all->data->screen_height = y - 200; ///modif
	all->data->screen_width = x - 400; ///modif
}

static void	fill_color_struct(t_all *all)
{
	all->mlx->c_color.a = 255;
	all->mlx->c_color.r = (u_int8_t)all->texture->ceiling_color->r;
	all->mlx->c_color.g = (u_int8_t)all->texture->ceiling_color->g;
	all->mlx->c_color.b = (u_int8_t)all->texture->ceiling_color->b;
	all->mlx->f_color.a = 255;
	all->mlx->f_color.r = (u_int8_t)all->texture->floor_color->r;
	all->mlx->f_color.g = (u_int8_t)all->texture->floor_color->g;
	all->mlx->f_color.b = (u_int8_t)all->texture->floor_color->b;
}

static void	init_texture_addr(t_all *all)
{
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
	all->texture->addr_d = malloc(sizeof(t_addr));
	if (!all->texture->addr_d)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->texture->addr_txt = malloc(sizeof(t_addr));
	if (!all->texture->addr_txt)
		error_exit("Error\nMalloc failure\n", all, NULL);
}

void	init_mlx(t_all *all, t_mlx *mlx)
{
	all->key = ft_calloc(1, sizeof(t_key));
	if (!all->key)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->mlx->fc_image = mlx_new_image(mlx->mlx_ptr,
			all->data->screen_width, all->data->screen_height);
	if (!all->mlx->fc_image)
		error_exit("Error\nMLX new image failure\n", all, NULL);
	fill_color_struct(all);
	all->addr = mlx_get_data_addr(all->mlx->fc_image,
			&all->bpp, &all->line_length, &all->endian);
	if (!all->addr)
		error_exit("Error\nGet data addr failure\n", all, NULL);
	all->bpp /= 8;
	init_texture_addr(all);
	get_images(all, all->mlx);
}
