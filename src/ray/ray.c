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

// void	print_side(t_ray *ray)
// {
// 	if (ray->side == 0)
// 		printf(RED"EAST\n"RESET);
// 	if (ray->side == 1)
// 		printf(RED"NORTH\n"RESET);
// 	if (ray->side == 2)
// 		printf(RED"WEST\n"RESET);
// 	if (ray->side == 3)
// 		printf(RED"SOUTH\n"RESET);
// }

void	side_touched(t_data *data)
{
	t_ray	*ray = data->ray;

	if (ray->last_side == 0)
	{
		if (ray->step_x > 0)
			printf("EAST\n");
		else
			printf("WEST\n");
	}
	else
	{
		if (ray->step_y > 0)
			printf("SOUTH\n");
		else
			printf("NORTH\n");
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
	data->player->radian = 0;
	for (int i = 0; i < 4; i++)
	{
		wall_dist = pre_dda(data);
		printf("dist : %f\n", wall_dist);
		printf("angle radian %f\n", data->player->radian);
		// print_side(data->ray);
		data->player->radian += 0.5f;
	}
	// data->player->radian = 1.75f;
	// wall_dist = pre_dda(data);
	// printf("dist : %f\n", wall_dist);
	// printf("angle : %f\n", data->player->radian);
	// print_side(data->ray);
}
