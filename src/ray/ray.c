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

// void	print_ray_touch(t_data *data, int x, int y)
// {
// 	int	i;
// 	int	j;
//
// 	i = 0;
// 	j = 0;
// 	while (data->map[i])
// 	{
// 		j = 0;
// 		while (data->map[i][j])
// 		{
// 			if (i == x && j == y)
// 				printf(RED"%c"RESET, data->map[i][j]);
// 			else
// 				printf("%c", data->map[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

float	pre_dda(t_data *data, float ray)
{
	float	res;

	if (ray < 0)
		ray = 2.0f - fabsf(ray);
	if (ray > 2.0f)
		ray = fmodf(ray, 2.0f);
	data->ray->dir_x = ft_trig(data, ray, COS);
	data->ray->dir_y = ft_trig(data, ray, SIN);

	printf("\nRay info:\n");
	printf("angle factor: %.2fπ\n", ray);
	printf("dir_x: %.6f | dir_y: %.6f\n", data->ray->dir_x, data->ray->dir_y);

	res = dda(data, data->ray->dir_x, data->ray->dir_y);
	side_touched(data, data->ray->last_side, data->ray->dir_x, data->ray->dir_y);

	printf("→ distance: %.6f\n", res);
	return (res);
}

void	side_touched(t_data *data, int side, float dir_x, float dir_y)
{
	if (side == 0)
	{
		if (dir_x > 0)
		{
			printf("EAST\n");
			data->ray->side = EAST;
		}
		else
		{
			printf("WEST\n");
			data->ray->side = WEST;
		}
	}
	else
	{
		if (dir_y > 0)
		{
			printf("NORTH\n");
			data->ray->side = NORTH;
		}
		else
		{
			printf("SOUTH\n");
			data->ray->side = SOUTH;
		}
	}
}

void	ray_servo(t_data *data, int i)
{
	float	ray_start;
	float	ray_end;
	float	incr;
	float	wall_dist;

	incr = 0.5f / (float) data->screen_width;
	ray_start = data->player->radian - 0.25f;
	if (ray_start < 0)
		ray_start = 2.0f - fabsf(ray_start);
	if (ray_start > 2.0f)
		ray_start = fmodf(ray_start, 2.0f);
	ray_end = data->player->radian + 0.25f;
	if (ray_end < 0)
		ray_end = 2.0f - fabsf(ray_end);
	if (ray_end > 2.0f)
		ray_end = fmodf(ray_end, 2.0f);
	while (ray_start < ray_end)
	{
		wall_dist = pre_dda(data, ray_start);
		wall_height(data, wall_dist, i, ray_start);
		ray_start += incr;
		i++;
	}
}
