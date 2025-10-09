/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:16:45 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/09 16:55:38 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	get_images(t_all *all, t_mlx *mlx)
{
	int	w;
	int	h;

	mlx->n_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr, all->texture->north_texture, &w, &h);
	if(!mlx->n_texture)
		error_exit("Error\nXPM to image failure\n", NULL, NULL);
	if(w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", NULL, NULL);
	mlx->s_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr, all->texture->south_texture, &w, &h);
	if(!mlx->s_texture)
		error_exit("Error\nXPM to image failure\n", NULL, NULL);
	if(w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", NULL, NULL);
	mlx->e_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr, all->texture->east_texture, &w, &h);
	if(!mlx->e_texture)
		error_exit("Error\nXPM to image failure\n", NULL, NULL);
	if(w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", NULL, NULL);
	mlx->w_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr, all->texture->west_texture, &w, &h);
	if(!mlx->w_texture)
		error_exit("Error\nXPM to image failure\n", NULL, NULL);
	if(w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", NULL, NULL);
}

void	fill_fc_texture(t_all *all)
{
	int	i;
	char	*img;

	img = (char *)all->mlx->fc_image;
	i = 0;
	while(i < 10000)
	{
		while(i < 5000)
		{
			img[i] = all->mlx->c_color.argb;
			i++;
		}
		img[i] = all->mlx->f_color.argb;
		i++;
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
	int	x;
	int	y;

	mlx->mlx_ptr = mlx_init();
	if(!mlx->mlx_ptr)
		error_exit("Error\nMLX init failure\n", NULL, NULL);
	mlx_get_screen_size(mlx->mlx_ptr, &x, &y);
	mlx->w_win = x;
	mlx->h_win = y;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, x, y, "cub3D");
	all->mlx->fc_image = mlx_new_image(mlx->mlx_ptr, 100, 100);
	fill_color_struct(all);
}
