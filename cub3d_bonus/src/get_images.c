/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:01:43 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/29 13:56:26 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	get_w_image(t_all *all, t_mlx *mlx, int w, int h)
{
	t_addr	*addr_w;

	mlx->w_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
			all->texture->west_texture, &w, &h);
	if (!mlx->w_texture)
		error_exit("Error\nXPM to image failure\n", all, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", all, NULL);
	all->texture->width_w = w;
	all->texture->height_w = h;
	addr_w = all->texture->addr_w;
	addr_w->addr = mlx_get_data_addr(all->mlx->w_texture,
			&addr_w->bpp, &addr_w->line_length, &addr_w->endian);
	if(!addr_w->addr)
		error_exit("Error\nGet data addr failure\n", all, NULL);
	addr_w->bpp /= 8;
}

void	get_e_image(t_all *all, t_mlx *mlx, int w, int h)
{
	t_addr	*addr_e;

	mlx->e_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
			all->texture->east_texture, &w, &h);
	if (!mlx->e_texture)
		error_exit("Error\nXPM to image failure\n", all, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", all, NULL);
	all->texture->width_e = w;
	all->texture->height_e = h;
	addr_e = all->texture->addr_e;
	addr_e->addr = mlx_get_data_addr(all->mlx->e_texture,
			&addr_e->bpp, &addr_e->line_length, &addr_e->endian);
	if(!addr_e->addr)
		error_exit("Error\nGet data addr failure\n", all, NULL);
	addr_e->bpp /= 8;
}

void	get_s_image(t_all *all, t_mlx *mlx, int w, int h)
{
	t_addr	*addr_s;

	mlx->s_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
			all->texture->south_texture, &w, &h);
	if (!mlx->s_texture)
		error_exit("Error\nXPM to image failure\n", all, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", all, NULL);
	all->texture->width_s = w;
	all->texture->height_s = h;
	addr_s = all->texture->addr_s;
	addr_s->addr = mlx_get_data_addr(all->mlx->s_texture,
			&addr_s->bpp, &addr_s->line_length, &addr_s->endian);
	if(!addr_s->addr)
		error_exit("Error\nGet data addr failure\n", all, NULL);
	addr_s->bpp /= 8;
}

void	get_n_image(t_all *all, t_mlx *mlx, int w, int h)
{
	t_addr	*addr_n;

	mlx->n_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
			all->texture->north_texture, &w, &h);
	if (!mlx->n_texture)
		error_exit("Error\nXPM to image failure\n", all, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", all, NULL);
	all->texture->width_n = w;
	all->texture->height_n = h;
	addr_n = all->texture->addr_n;
	addr_n->addr = mlx_get_data_addr(all->mlx->n_texture,
			&addr_n->bpp, &addr_n->line_length, &addr_n->endian);
	if(!addr_n->addr)
		error_exit("Error\nGet data addr failure\n", all, NULL);
	addr_n->bpp /= 8;
}

void	get_d_image(t_all *all, t_mlx *mlx, int w, int h)
{
	t_addr	*addr_d;

	mlx->d_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
			all->texture->door_texture, &w, &h);
	if (!mlx->d_texture)
		error_exit("Error\nXPM to image failure\n", all, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", all, NULL);
	all->texture->width_d = w;
	all->texture->height_d = h;
	addr_d = all->texture->addr_d;
	addr_d->addr = mlx_get_data_addr(all->mlx->d_texture,
			&addr_d->bpp, &addr_d->line_length, &addr_d->endian);
	if(!addr_d->addr)
		error_exit("Error\nGet data addr failure\n", all, NULL);
	addr_d->bpp /= 8;
}

void	get_txt_image(t_all *all, t_mlx *mlx, int w, int h)
{
	t_addr	*addr_txt;

	mlx->txt_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
			"./assets/texture/door_txt.xpm", &w, &h);
	if (!mlx->txt_texture)
		error_exit("Error\nXPM to image failure\n", all, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", all, NULL);
	all->texture->width_txt = w;
	all->texture->height_txt = h;
	addr_txt = all->texture->addr_txt;
	addr_txt->addr = mlx_get_data_addr(all->mlx->txt_texture,
			&addr_txt->bpp, &addr_txt->line_length, &addr_txt->endian);
	if(!addr_txt->addr)
		error_exit("Error\nGet data addr failure\n", all, NULL);
	addr_txt->bpp /= 8;
}

void	get_images(t_all *all, t_mlx *mlx)
{
	get_n_image(all, mlx, 0, 0);
	get_s_image(all, mlx, 0, 0);
	get_e_image(all, mlx, 0, 0);
	get_w_image(all, mlx, 0, 0);
	get_d_image(all, mlx, 0, 0);
	// get_txt_image(all, mlx, 0, 0);
}
