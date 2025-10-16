/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:54:29 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/16 11:14:07 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	update(t_all *all)
{
	fill_fc_image(all, 0, 0);
	ray_servo(all->data, 0);
	mlx_put_image_to_window(all->mlx->mlx_ptr,
			all->mlx->win_ptr, all->mlx->fc_image, 0, 0);
}

int	mov_servo(t_data *data)
{
	create_player(data);
	return (0);
}

int	key_event(int keycode, t_all *all)
{
	if (keycode == XK_Escape)
		exit_game(all);
	if (keycode == XK_w)
		w_key(all->data);
	if (keycode == XK_s)
		s_key(all->data);
	if (keycode == XK_a)
		a_key(all->data);
	if (keycode == XK_d)
		d_key(all->data);
	if (keycode == 65361)
		letf_arr(all->data);
	if (keycode == 65363)
		right_arr(all->data);
	return (0);
}
