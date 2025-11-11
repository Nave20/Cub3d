/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:21:37 by lpaysant          #+#    #+#             */
/*   Updated: 2025/11/11 13:00:26 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

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
	if (!addr_d->addr)
		error_exit("Error\nGet data addr failure\n", all, NULL);
	addr_d->bpp /= 8;
}

void	put_txt_to_window(t_all *all, t_addr *addr, int height, int width)
{
	int		i_txt;
	int		j_txt;
	int		i;
	int		j;
	t_argb	color;

	i_txt = 0;
	i = all->data->screen_height / 2;
	j = (int)(all->data->screen_width / 2.5);
	while (i_txt < height)
	{
		j = (int)(all->data->screen_width / 2.5);
		j_txt = 0;
		while (j_txt < width)
		{
			color = yx_back_converter(addr, i_txt, j_txt);
			if (color.argb == 789259)
				yx_converter(all, color, i, j);
			j++;
			j_txt++;
		}
		i++;
		i_txt++;
	}
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
	if (!addr_txt->addr)
		error_exit("Error\nGet data addr failure\n", all, NULL);
	addr_txt->bpp /= 8;
}
