/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_trig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:53:09 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/12 12:01:55 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	fast_trig(t_data *data)
{
	int		i;
	float	alpha;

	i = 0;
	while (i < TRIG_TABLE)
	{
		alpha = (TWOPI * i) / TRIG_TABLE;
		data->f_cos[i] = cosf(alpha);
		data->f_sin[i] = sinf(alpha);
		data->f_tan[i] = tanf(alpha);
		i++;
	}
}

float	ft_trig(t_data *data, float angle, t_trig type)
{
	float	alpha;

	alpha = angle;
	if (alpha < 0)
		alpha = 2.0f - fabsf(alpha);
	if (alpha > 2.0f)
		alpha = fmodf(alpha, 2.0f);
	if (type == COS)
		return (data->f_cos[(int)((alpha) * TRIG_TABLE / 2)]);
	if (type == SIN)
		return (data->f_sin[(int)((alpha) * TRIG_TABLE / 2)]);
	if (type == TAN)
		return (data->f_tan[(int)((alpha) * TRIG_TABLE / 2)]);
	return (0);
}
