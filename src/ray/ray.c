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

float	pre_dda(t_data *data)
{
	float	res;

	if (data->player->radian < 0)
		data->player->radian = 2.0f - fabsf(data->player->radian);
	data->ray->dir_x = ft_trig(data, data->player->radian, COS);
	data->ray->dir_y = ft_trig(data, data->player->radian, SIN);

	printf("\nRay info:\n");
	printf("angle factor: %.2fπ\n", data->player->radian);
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

void	ray_servo(t_data *data)
{
	float	wall_dist;
	// float	line_height;

	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		return ;
	print_pos(data->player);
	data->player->radian = 1.25f;
	// while (data->player->radian > 0.75f)
	// {
	// 	wall_dist = pre_dda(data);
	// 	data->player->radian -= 0.0001f;
	// }
	for (int i = 0; i < 1920 ; i++)
	{
		wall_dist = pre_dda(data);
	}
}
