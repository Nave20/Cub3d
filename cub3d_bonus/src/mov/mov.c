/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:54:29 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/12 12:40:14 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	update(t_all *all)
{
	int			x;
	int			y;

	x = all->data->player->pos_x;
	y = all->data->player->pos_y;
	ray_servo(all->data, 0);
	door_detect(all->data, all->data->player->radian);
	if (all->data->ray->door == true && (all->data->map[y][x + 1] == 'C'
		|| all->data->map[y + 1][x] == 'C' || all->data->map[y][x - 1] == 'C'
		|| all->data->map[y - 1][x] == 'C' || all->data->map[y][x + 1] == 'O'
		|| all->data->map[y + 1][x] == 'O' || all->data->map[y][x - 1] == 'O'
		|| all->data->map[y - 1][x] == 'O'))
		put_txt_to_window(all, all->texture->addr_txt,
			all->texture->height_txt, all->texture->width_txt);
	mlx_put_image_to_window(all->mlx->mlx_ptr,
		all->mlx->win_ptr, all->mlx->fc_image, 0, 0);
	fill_minimap_image(all);
	mlx_put_image_to_window(all->mlx->mlx_ptr,
		all->mlx->win_ptr, all->minimap->image, 0, 0);
}

static void	key_dispatcher(t_all *all)
{
	if (all->key->w)
		w_key(all->data, all->data->player->pos_x,
			all->data->player->pos_y);
	if (all->key->a)
		a_key(all->data, all->data->player->pos_x,
			all->data->player->pos_y);
	if (all->key->s)
		s_key(all->data, all->data->player->pos_x,
			all->data->player->pos_y);
	if (all->key->d)
		d_key(all->data, all->data->player->pos_x,
			all->data->player->pos_y);
	if (all->key->left_arrow)
		letf_arr(all->data);
	if (all->key->right_arrow)
		right_arr(all->data);
}

int	key_check(t_all *all)
{
	static int	nb_frame;

	nb_frame++;
	if (nb_frame % 5000 == 0)
	{
		key_dispatcher(all);
		update(all);
		all->anim->anim_frame++;
		if (all->anim->anim_frame >= 7)
			all->anim->anim_frame = 0;
	}
	return (0);
}

int	key_release(int keycode, t_all *all)
{
	if (keycode == XK_w)
		all->key->w = 0;
	if (keycode == XK_a)
		all->key->a = 0;
	if (keycode == XK_s)
		all->key->s = 0;
	if (keycode == XK_d)
		all->key->d = 0;
	if (keycode == 65361)
		all->key->left_arrow = 0;
	if (keycode == 65363)
		all->key->right_arrow = 0;
	return (0);
}

int	key_press(int keycode, t_all *all)
{
	if (keycode == XK_Escape)
		exit_game(all);
	if (keycode == XK_f)
		f_key(all);
	if (keycode == XK_w)
		all->key->w = 1;
	if (keycode == XK_a)
		all->key->a = 1;
	if (keycode == XK_s)
		all->key->s = 1;
	if (keycode == XK_d)
		all->key->d = 1;
	if (keycode == 65361)
		all->key->left_arrow = 1;
	if (keycode == 65363)
		all->key->right_arrow = 1;
	return (0);
}
