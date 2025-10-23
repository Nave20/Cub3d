/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:48:31 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/23 12:16:08 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	left_arr_mouse(t_data *data)
{
	data->player->radian -= 0.0125f;
	if (data->player->radian < 0)
		data->player->radian = 2.0f - fabsf(data->player->radian);
	update(data->all);
}

void	right_arr_mouse(t_data *data)
{
	data->player->radian += 0.0125f;
	if (data->player->radian < 0)
		data->player->radian = 2.0f - fabsf(data->player->radian);
	update(data->all);
}

void	letf_arr(t_data *data)
{
	data->player->radian -= 0.0125f;
	if (data->player->radian < 0)
		data->player->radian = 2.0f - fabsf(data->player->radian);
	update(data->all);
}

void	right_arr(t_data *data)
{
	data->player->radian += 0.0625f;
	if (data->player->radian < 0)
		data->player->radian = 2.0f - fabsf(data->player->radian);
	update(data->all);
}
