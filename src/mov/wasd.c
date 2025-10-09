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

#include <math.h>

#include "../../header/cub3D.h"

void	w_key(t_data *data)
{
	t_player	*player;
	float		tmp;

	player = data->player;
	tmp = player->pos_y;
	player->pos_y -= STEP * sin(player->radian * PI);
	if (data->map[(int)player->pos_y][(int)player->pos_x] == '1')
	{
		if (player->pos_y > tmp)
			player->pos_y = ((int)player->pos_y) - STEP;
		else
			player->pos_y = ((int)player->pos_y) + STEP;
	}
	tmp = player->pos_x;
	player->pos_x -= STEP * cos(player->radian * PI);
	if (data->map[(int)player->pos_y][(int)player->pos_x] == '1')
	{
		if (player->pos_x > tmp)
			player->pos_x = ((int)player->pos_x) - STEP;
		else
			player->pos_x = ((int)player->pos_x) + STEP;
	}
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
}

void	a_key(t_data *data)
{
	t_player	*player;
	float		tmp;

	player = data->player;
	tmp = player->pos_y;
	player->pos_y -= STEP * sin((player->radian + 0.5) * PI);
	if (data->map[(int)player->pos_y][(int)player->pos_x] == '1')
	{
		if (player->pos_y > tmp)
			player->pos_y = ((int)player->pos_y) - STEP;
		else
			player->pos_y = ((int)player->pos_y) + STEP;
	}
	tmp = player->pos_x;
	player->pos_x -= STEP * cos((player->radian + 0.5) * PI);
	if (data->map[(int)player->pos_y][(int)player->pos_x] == '1')
	{
		if (player->pos_x > tmp)
			player->pos_x = ((int)player->pos_x) - STEP;
		else
			player->pos_x = ((int)player->pos_x) + STEP;
	}
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
}

void	s_key(t_data *data)
{
	t_player	*player;
	float		tmp;

	player = data->player;
	tmp = player->pos_y;
	player->pos_y -= STEP * sin((player->radian + 1) * PI);
	if (data->map[(int)player->pos_y][(int)player->pos_x] == '1')
	{
		if (player->pos_y > tmp)
			player->pos_y = ((int)player->pos_y) - STEP;
		else
			player->pos_y = ((int)player->pos_y) + STEP;
	}
	tmp = player->pos_x;
	player->pos_x -= STEP * cos((player->radian + 1) * PI);
	if (data->map[(int)player->pos_y][(int)player->pos_x] == '1')
	{
		if (player->pos_x > tmp)
			player->pos_x = ((int)player->pos_x) - STEP;
		else
			player->pos_x = ((int)player->pos_x) + STEP;
	}
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
}

void	d_key(t_data *data)
{
	t_player	*player;
	float		tmp;

	player = data->player;
	tmp = player->pos_y;
	player->pos_y -= STEP * sin((player->radian + 1.5) * PI);
	if (data->map[(int)player->pos_y][(int)player->pos_x] == '1')
	{
		if (player->pos_y > tmp)
			player->pos_y = ((int)player->pos_y) - STEP;
		else
			player->pos_y = ((int)player->pos_y) + STEP;
	}
	tmp = player->pos_x;
	player->pos_x -= STEP * cos((player->radian + 1.5) * PI);
	if (data->map[(int)player->pos_y][(int)player->pos_x] == '1')
	{
		if (player->pos_x > tmp)
			player->pos_x = ((int)player->pos_x) - STEP;
		else
			player->pos_x = ((int)player->pos_x) + STEP;
	}
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
}