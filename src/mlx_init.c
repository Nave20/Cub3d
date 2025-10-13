/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:16:45 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/13 15:10:05 by lpaysant         ###   ########.fr       */
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
		error_exit("Error\nXPM to image failure\n", NULL, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", NULL, NULL);
	mlx->s_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
			all->texture->south_texture, &w, &h);
	if (!mlx->s_texture)
		error_exit("Error\nXPM to image failure\n", NULL, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", NULL, NULL);
	mlx->e_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
			all->texture->east_texture, &w, &h);
	if (!mlx->e_texture)
		error_exit("Error\nXPM to image failure\n", NULL, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", NULL, NULL);
	mlx->w_texture = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
			all->texture->west_texture, &w, &h);
	if (!mlx->w_texture)
		error_exit("Error\nXPM to image failure\n", NULL, NULL);
	if (w <= 0 || h <= 0)
		error_exit("Error\nBad image dimensions\n", NULL, NULL);
}

void	dlbe_tab_to_fc_image(t_all *all)
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
		while(tab[i][j])
		{
			img[index] = tab[i][j];
			index++;
			j++;
		}
		j = 0;
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
}

void	fill_fc_image(t_all *all)
{
	int		i;
	char	*img;

	img = (char *)all->mlx->fc_image;
	i = 0;
	while (i < (all->data->screen_height * all->data->screen_width))
	{
		while (i < ((all->data->screen_height * all->data->screen_width) / 2))
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

// void	display_game(t_all *all, t_mlx *mlx)
// {
// 	int	x;
// 	int	y;
//
// 	mlx->mlx_ptr = mlx_init();
// 	if (!mlx->mlx_ptr)
// 		error_exit("Error\nMLX init failure\n", NULL, NULL);
// 	// mlx_get_screen_size(mlx->mlx_ptr, &x, &y);
// 	// mlx->w_win = x;
// 	// mlx->h_win = y;
// 	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, all->data->screen_height, all->data->screen_width, "cub3D");
// 	all->mlx->fc_image = mlx_new_image(mlx->mlx_ptr, 100, 100);
// 	fill_color_struct(all);
// 	fill_fc_image(all);
// 	mlx_hook(all->mlx->win_ptr, 17, 0, exit_game, all);
// }
