/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:54:38 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/07 14:54:38 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	print_ray_touch(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (i == x && j == y)
				printf(RED"%c"RESET, data->map[i][j]);
			else
				printf("%c", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	send_ray(t_data *data)
{
	t_ray	*ray;

	ray = data->ray;
	ray->end_x = data->player->pos_x;
	ray->end_y = data->player->pos_y;
	while (data->map[(int)ray->end_x][(int)ray->end_y] != '1')
	{
		ray->end_y -= 0.01 * sin((data->player->radian + 1.5) * PI);
		ray->end_x -= 0.01 * cos((data->player->radian + 1.5) * PI);
	}
}

float	ray_length(t_data *data)
{
	float	res;
	float	x;
	float	y;

	res = 0;
	x = fabs(data->ray->end_x - data->player->pos_x);
	y = fabs(data->ray->end_y - data->player->pos_y);
	res = sqrt(x * x + y * y);
	return (res);
}

void	ray_servo(t_data *data)
{
	float	x;
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		return ;
	print_pos(data->player);
	data->player->radian = 0.75;
	while (data->player->radian > 0.25)
	{
		send_ray(data);
		x = ray_length(data);
		printf(CYAN"%.2f\n"RESET, x);
		data->player->radian -= 0.01;
	}
}
