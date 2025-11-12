/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:48:31 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/12 11:56:15 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	letf_arr(t_data *data)
{
	data->player->radian += POV_INCR;
	if (data->player->radian < 0)
		data->player->radian = 2.0f - fabsf(data->player->radian);
	if (floorf(data->player->radian * 1000) == 2000)
		data->player->radian = 0.0f;
}

void	right_arr(t_data *data)
{
	data->player->radian -= POV_INCR;
	if (data->player->radian < 0)
		data->player->radian = 2.0f - fabsf(data->player->radian);
	if (floorf(data->player->radian * 1000) == 2000)
		data->player->radian = 0.0f;
}
