/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:50:08 by lpaysant          #+#    #+#             */
/*   Updated: 2025/11/12 11:56:15 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	left_arr_mouse(t_data *data)
{
	data->player->radian += POV_MOUSE;
	if (data->player->radian < 0)
		data->player->radian = 2.0f - fabsf(data->player->radian);
}

static void	right_arr_mouse(t_data *data)
{
	data->player->radian -= POV_MOUSE;
	if (data->player->radian < 0)
		data->player->radian = 2.0f - fabsf(data->player->radian);
}

int	mouse_hook(int x, int y, t_all *all)
{
	int	dif;

	if (x == all->mouse->mid_x && y == all->mouse->mid_y)
		return (0);
	dif = x - all->mouse->mid_x;
	if (dif > 5)
		right_arr_mouse(all->data);
	if (dif < -5)
		left_arr_mouse(all->data);
	mlx_mouse_move(all->mlx->mlx_ptr, all->mlx->win_ptr,
		all->mouse->mid_x, all->mouse->mid_y);
	return (0);
}
