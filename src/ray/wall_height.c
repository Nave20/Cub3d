/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:27:53 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/13 12:27:53 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	wall_height(t_data *data, float wall_dist, int col, float ray)
{
	int		wall_height;
	float	correct_dist;

	correct_dist = wall_dist * ft_trig(data,
		(data->player->radian - ray), COS);
	wall_height = data->screen_height / wall_dist;
}