/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:50:08 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/27 16:31:08 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	left_arr_mouse(t_data *data)
{
	data->player->radian += 0.0115f;
	if (data->player->radian < 0)
		data->player->radian = 2.0f - fabsf(data->player->radian);
	update(data->all);
}

void	right_arr_mouse(t_data *data)
{
	data->player->radian -= 0.0115f;
	if (data->player->radian < 0)
		data->player->radian = 2.0f - fabsf(data->player->radian);
	update(data->all);
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
