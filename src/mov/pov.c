/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:48:31 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/09 11:48:31 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	letf_arr(t_data *data)
{
	data->player->radian += 0.125;
}

void	right_arr(t_data *data)
{
	data->player->radian -= 0.125;
}