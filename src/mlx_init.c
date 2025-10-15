/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:16:45 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/15 12:07:57 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	get_images(t_all *all, t_mlx *mlx)
{
	int	w;
	int	h;

	mlx->n_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
			all->texture->north_texture, &w, &h);
	if (!mlx->n_texture)
		error_exit("Error\nXPM to image failure\n", all, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", all, NULL);
	all->texture->width_n = w;
	all->texture->height_n = h;
	t_addr *addr_n = all->texture->addr_n;
	addr_n->addr = mlx_get_data_addr(all->mlx->n_texture,
	&addr_n->bpp, &addr_n->line_length, &addr_n->endian); //SECURISER PITIE
	addr_n->bpp /= 8;


	mlx->s_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
			all->texture->south_texture, &w, &h);
	if (!mlx->s_texture)
		error_exit("Error\nXPM to image failure\n", all, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", all, NULL);
	all->texture->width_s = w;
	all->texture->height_s = h;
	t_addr *addr_s = all->texture->addr_s;
	addr_s->addr = mlx_get_data_addr(all->mlx->s_texture,
	&addr_s->bpp, &addr_s->line_length, &addr_s->endian);
	addr_s->bpp /= 8;

	mlx->e_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
			all->texture->east_texture, &w, &h);
	if (!mlx->e_texture)
		error_exit("Error\nXPM to image failure\n", all, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", all, NULL);
	all->texture->width_e = w;
	all->texture->height_e = h;
	t_addr *addr_e = all->texture->addr_e;
	addr_e->addr = mlx_get_data_addr(all->mlx->e_texture,
	&addr_e->bpp, &addr_e->line_length, &addr_e->endian);
	addr_e->bpp /= 8;

	mlx->w_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
			all->texture->west_texture, &w, &h);
	if (!mlx->w_texture)
		error_exit("Error\nXPM to image failure\n", all, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", all, NULL);
	all->texture->width_w = w;
	all->texture->height_w = h;
	t_addr *addr_w = all->texture->addr_w;
	addr_w->addr = mlx_get_data_addr(all->mlx->w_texture,
	&addr_w->bpp, &addr_w->line_length, &addr_w->endian);
}

void	dble_tab_to_fc_image(t_all *all)
{
	int		i;
	int		j;
	int		index;
	char	*img;
	char	**tab;

	i = 0;
	j = 0;
	index = 0;
	tab = all->mlx->img_tab;
	img = ft_calloc((all->mlx->h_win * all->mlx->w_win) + 1, sizeof(char));
	while(tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			img[index] = tab[i][j];
			index++;
			j++;
		}
		i++;
	}
	free(all->mlx->fc_image);
	all->mlx->fc_image = (void *)img;
}

char	*dup_img_line(t_all *all, char *img, int start, int end)
{
	char	*cpy;
	int	i;

	i = 0;
	cpy = ft_calloc(end - start + 1, sizeof(char));
	if(!cpy)
		error_exit("Error\nmalloc failure\n", all, NULL);
	while(start < end)
	{
		cpy[i] = img[start];
		i++;
		start++;
	}
	return(cpy);
}

void	fc_image_to_dble_tab(t_all *all)
{
	int		i;
	int		start;
	int		end;
	char	**img_tab;
	char	*img;

	i = 0;
	img_tab = ft_calloc(all->data->screen_height, sizeof(char *));
	if(!img_tab)
		error_exit("Error\nMalloc failure\n", all, NULL);
	img = all->mlx->fc_image;
	start = 0;
	end = 0;
	while(img_tab[i])
	{
		while(end - start != all->mlx->w_win)
			end++;
		img_tab[i] = dup_img_line(all, img, start, end);
		i++;
		end++;
		start = end;
	}
	all->mlx->img_tab = img_tab;
}

void	fill_fc_image(t_all *all)
{
	int		x;
	int		y;
	int		half_height;

	// ⚙️ Récupération du buffer pixel
	all->addr = mlx_get_data_addr(all->mlx->fc_image, &all->bpp, &all->line_length, &all->endian);
	all->bpp /= 8;

	half_height = all->data->screen_height / 2;

	for (y = 0; y < all->data->screen_height; y++)
	{
		for (x = 0; x < all->data->screen_width; x++)
		{
			union s_argb color;

			// 🌈 Choix de la couleur selon la moitié de l'écran
			if (y < half_height)
				color = all->mlx->c_color; // couleur du "ciel"
			else
				color = all->mlx->f_color; // couleur du "sol"

			// 🧠 Écriture du pixel (4 octets)
			*(uint32_t *)(all->addr + (y * all->line_length + x * (all->bpp / 8))) = color.argb;
		}
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

// void	update_img(t_all *all, int wall_size, int i_col)
// {
// 	int	i;
// 	int	wall_limits;

// 	wall_limits = (all->data->screen_height - wall_size) / 2;
// 	i = wall_limits;
// 	while(i <= all->data->screen_height - wall_limits)
// 	{
// 		all->mlx->fc_image[];
// 		mlx_put_image_to_window()
// 	}
// }

void	display_game(t_all *all, t_mlx *mlx)
{
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, all->data->screen_width, all->data->screen_height, "cub3D");
	all->mlx->fc_image = mlx_new_image(mlx->mlx_ptr, all->data->screen_width, all->data->screen_height);
	fill_color_struct(all);
	fill_fc_image(all);
	all->texture->addr_n = malloc(sizeof(t_addr));
	if(!all->texture->addr_n)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->texture->addr_s = malloc(sizeof(t_addr));
	if(!all->texture->addr_s)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->texture->addr_e = malloc(sizeof(t_addr));
	if(!all->texture->addr_e)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->texture->addr_w = malloc(sizeof(t_addr));
	if(!all->texture->addr_w)
		error_exit("Error\nMalloc failure\n", all, NULL);
	get_images(all, all->mlx);
}
