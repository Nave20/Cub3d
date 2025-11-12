/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:51:46 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/12 12:54:29 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	s_key(t_data *data, float new_x, float new_y)
{
	t_player	*player;

	player = data->player;
	new_y -= STEP * ft_trig(data, player->radian, COS);
	if (data->map[(int)new_y][(int)player->pos_x] != '1')
		data->player->pos_y = new_y;
	new_x -= STEP * ft_trig(data, player->radian, SIN);
	if (data->map[(int)player->pos_y][(int)new_x] != '1')
		data->player->pos_x = new_x;
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
}

void	a_key(t_data *data, float new_x, float new_y)
{
	t_player	*player;

	player = data->player;
	new_y -= STEP * ft_trig(data, player->radian - 0.5f, COS);
	if (data->map[(int)new_y][(int)player->pos_x] != '1')
		data->player->pos_y = new_y;
	new_x -= STEP * ft_trig(data, player->radian - 0.5f, SIN);
	if (data->map[(int)player->pos_y][(int)new_x] != '1')
		data->player->pos_x = new_x;
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
}

void	w_key(t_data *data, float new_x, float new_y)
{
	t_player	*player;

	player = data->player;
	if (data->player->radian == 1.0f)
	{
		new_y -= STEP * ft_trig(data, player->radian + 1.0f, SIN);
		if (data->map[(int)new_y][(int)player->pos_x] != '1')
			data->player->pos_y = new_y;
		new_x -= STEP * ft_trig(data, player->radian + 1.0f, COS);
		if (data->map[(int)player->pos_y][(int)new_x] != '1')
			data->player->pos_x = new_x;
		player->grid_y = (int) player->pos_y;
		player->grid_x = (int) player->pos_x;
		update(data->all);
		return ;
	}
	new_y -= STEP * ft_trig(data, player->radian + 1.0f, COS);
	if (data->map[(int)new_y][(int)player->pos_x] != '1')
		data->player->pos_y = new_y;
	new_x -= STEP * ft_trig(data, player->radian + 1.0f, SIN);
	if (data->map[(int)player->pos_y][(int)new_x] != '1')
		data->player->pos_x = new_x;
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
}

void	d_key(t_data *data, float new_x, float new_y)
{
	t_player	*player;

	player = data->player;
	if (data->player->radian == 1.5f)
	{
		new_y -= STEP * ft_trig(data, player->radian + 0.5f, SIN);
		if (data->map[(int)new_y][(int)player->pos_x] != '1')
			data->player->pos_y = new_y;
		new_x -= STEP * ft_trig(data, player->radian + 0.5f, COS);
		if (data->map[(int)player->pos_y][(int)new_x] != '1')
			data->player->pos_x = new_x;
		player->grid_y = (int) player->pos_y;
		player->grid_x = (int) player->pos_x;
		update(data->all);
		return ;
	}
	new_y -= STEP * ft_trig(data, player->radian + 0.5f, COS);
	if (data->map[(int)new_y][(int)player->pos_x] != '1')
		data->player->pos_y = new_y;
	new_x -= STEP * ft_trig(data, player->radian + 0.5f, SIN);
	if (data->map[(int)player->pos_y][(int)new_x] != '1')
		data->player->pos_x = new_x;
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
}
