/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:51:46 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/09 09:51:46 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	w_key(t_data *data)
{
	t_player	*player;
	float		tmp;

	player = data->player;
	tmp = player->pos_y;
	player->pos_y -= STEP * ft_trig(data, player->radian, SIN);
	if (data->map[(int)player->pos_x][(int)player->pos_y] == '1')
	{
		if (player->pos_y > tmp)
			player->pos_y = ((int)tmp) - 0.1f;
		else
			player->pos_y = ((int)tmp) + 0.1f;
	}
	tmp = player->pos_x;
	player->pos_x -= STEP * ft_trig(data, player->radian, COS);
	if (data->map[(int)player->pos_x][(int)player->pos_y] == '1')
	{
		if (player->pos_x > tmp)
			player->pos_x = ((int)tmp) - 0.1f;
		else
			player->pos_x = ((int)tmp) + 0.1f;
	}
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
	update(data->all);
}

void	a_key(t_data *data)
{
	t_player	*player;
	float		tmp;

	player = data->player;
	tmp = player->pos_y;
	player->pos_y -= STEP * ft_trig(data, player->radian + 0.5f, SIN);
	if (data->map[(int)player->pos_x][(int)player->pos_y] == '1')
	{
		if (player->pos_y > tmp)
			player->pos_y = ((int)tmp) - 0.1f;
		else
			player->pos_y = ((int)tmp) + 0.1f;
	}
	tmp = player->pos_x;
	player->pos_x -= STEP * ft_trig(data, player->radian + 0.5f, COS);
	if (data->map[(int)player->pos_x][(int)player->pos_y] == '1')
	{
		if (player->pos_x > tmp)
			player->pos_x = ((int)tmp) - 0.1f;
		else
			player->pos_x = ((int)tmp) + 0.1f;
	}
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
	update(data->all);
}

void	s_key(t_data *data)
{
	t_player	*player;
	float		tmp;

	player = data->player;
	tmp = player->pos_y;
	player->pos_y -= STEP * ft_trig(data, player->radian + 1.0f, SIN);
	if (data->map[(int)player->pos_x][(int)player->pos_y] == '1')
	{
		if (player->pos_y > tmp)
			player->pos_y = ((int)tmp) - 0.1f;
		else
			player->pos_y = ((int)tmp) + 0.1f;
	}
	tmp = player->pos_x;
	player->pos_x -= STEP * ft_trig(data, player->radian + 1.0f, COS);
	if (data->map[(int)player->pos_x][(int)player->pos_y] == '1')
	{
		if (player->pos_x > tmp)
			player->pos_x = ((int)tmp) - 0.1f;
		else
			player->pos_x = ((int)tmp) + 0.1f;
	}
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
	update(data->all);
}

void	d_key(t_data *data)
{
	t_player	*player;
	float		tmp;

	player = data->player;
	tmp = player->pos_y;
	player->pos_y -= STEP * ft_trig(data, player->radian - 0.5f, SIN);
	if (data->map[(int)player->pos_x][(int)player->pos_y] == '1')
	{
		if (player->pos_y > tmp)
			player->pos_y = (int) tmp - 0.1f;
		else
			player->pos_y = (int) tmp + 0.1f;
	}
	tmp = player->pos_x;
	player->pos_x -= STEP * ft_trig(data, player->radian - 0.5f, COS);
	if (data->map[(int)player->pos_x][(int)player->pos_y] == '1')
	{
		if (player->pos_x > tmp)
			player->pos_x = (int)tmp - 0.1f;
		else
			player->pos_x = (int)tmp + 0.1f;
	}
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
	update(data->all);
}
