/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:51:46 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/27 17:31:22 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	s_key(t_data *data, float new_x, float new_y)
{
	t_player	*player;

	player = data->player;
	new_y -= STEP * ft_trig(data, player->radian, COS);
	if (data->map[(int)new_y][(int)player->pos_x] != '1'
	&& data->map[(int)new_y][(int)player->pos_x] != 'C')
		data->player->pos_y = new_y;
	new_x -= STEP * ft_trig(data, player->radian, SIN);
	if (data->map[(int)player->pos_y][(int)new_x] != '1'
	&& data->map[(int)player->pos_y][(int)new_x] != 'C')
		data->player->pos_x = new_x;
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
	update(data->all);
}

void	a_key(t_data *data, float new_x, float new_y)
{
	t_player	*player;

	player = data->player;
	new_y -= STEP * ft_trig(data, player->radian - 0.5f, COS);
	if (data->map[(int)new_y][(int)player->pos_x] != '1'
	&& data->map[(int)new_y][(int)player->pos_x] != 'C')
		data->player->pos_y = new_y;
	new_x -= STEP * ft_trig(data, player->radian - 0.5f, SIN);
	if (data->map[(int)player->pos_y][(int)new_x] != '1'
	&& data->map[(int)player->pos_y][(int)new_x] != 'C')
		data->player->pos_x = new_x;
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
	update(data->all);
}

void	aaa(t_data *data, float ray, float new_x, float new_y)
{
	t_player	*player;

	player = data->player;
	new_y -= STEP * ft_trig(data, player->radian + ray, SIN);
	if (data->map[(int)new_y][(int)player->pos_x] != '1'
	&& data->map[(int)new_y][(int)player->pos_x] != 'C')
		data->player->pos_y = new_y;
	new_x -= STEP * ft_trig(data, player->radian + ray, COS);
	if (data->map[(int)player->pos_y][(int)new_x] != '1'
	&& data->map[(int)player->pos_y][(int)new_x] != 'C')
		data->player->pos_x = new_x;
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
	update(data->all);
	return ;
}

void	w_key(t_data *data, float new_x, float new_y)
{
	t_player	*player;

	player = data->player;
	if (data->player->radian == 1.0f)
		return (aaa(data, 1.0f, new_x, new_y));
	new_y -= STEP * ft_trig(data, player->radian + 1.0f, COS);
	if (data->map[(int)new_y][(int)player->pos_x] != '1'
	&& data->map[(int)new_y][(int)player->pos_x] != 'C')
		data->player->pos_y = new_y;
	new_x -= STEP * ft_trig(data, player->radian + 1.0f, SIN);
	if (data->map[(int)player->pos_y][(int)new_x] != '1'
	&& data->map[(int)player->pos_y][(int)new_x] != 'C')
		data->player->pos_x = new_x;
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
	update(data->all);
}

void	d_key(t_data *data, float new_x, float new_y)
{
	t_player	*player;

	player = data->player;
	if (data->player->radian == 1.5f)
		return (aaa(data, 0.5f, new_x, new_y));
	new_y -= STEP * ft_trig(data, player->radian + 0.5f, COS);
	if (data->map[(int)new_y][(int)player->pos_x] != '1'
	&& data->map[(int)new_y][(int)player->pos_x] != 'C')
		data->player->pos_y = new_y;
	new_x -= STEP * ft_trig(data, player->radian + 0.5f, SIN);
	if (data->map[(int)player->pos_y][(int)new_x] != '1'
	&& data->map[(int)player->pos_y][(int)new_x] != 'C')
		data->player->pos_x = new_x;
	player->grid_y = (int) player->pos_y;
	player->grid_x = (int) player->pos_x;
	update(data->all);
}
