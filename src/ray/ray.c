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

void	print_side(t_ray *ray)
{
	if (ray->side == 0)
		printf(RED"EAST\n"RESET);
	if (ray->side == 1)
		printf(RED"NORTH\n"RESET);
	if (ray->side == 2)
		printf(RED"WEST\n"RESET);
	if (ray->side == 3)
		printf(RED"SOUTH\n"RESET);
}

void	direction(t_data *data)
{
	float	angle;

	angle = fmod(data->player->radian, 2);
	if (angle >= 0 && angle < 0.5)

}

void	send_ray(t_data *data)
{
	float	pos_x;
	float	pos_y;
	float	side_x;
	float	side_y;
	float	dir;

	if (data->player->radian > )
	pos_x = data->player->pos_x;
	pos_y = data->player->pos_y;
	side_x = fabs(data->player->pos_x - (int)data->player->pos_x);
	side_y = fabs(data->player->pos_y - (int)data->player->pos_y);
	if (side_x >= side_y)
	{
		pos_x += side_x;
	}
}

// void	send_ray(t_data *data)
// {
// 	t_ray	*ray;
// 	int		x;
// 	int		y;
//
// 	ray = data->ray;
// 	ray->end_x = data->player->pos_x;
// 	ray->end_y = data->player->pos_y;
// 	while (data->map[(int)ray->end_x][(int)ray->end_y] != '1')
// 	{
// 		ray->end_y -= 0.01 * sin((data->player->radian + 1.5) * PI);
// 		ray->end_x -= 0.01 * cos((data->player->radian + 1.5) * PI);
// 	}
// 	x = roundf(ray->end_x);
// 	y = roundf(ray->end_y);
// 	if (data->map[(int)ray->end_x][(int)ray->end_y] == '1' && data->map[x][(int)ray->end_y] == '0')
// 		ray->side = NORTH;
// 	else if (data->map[x][(int)ray->end_y] == '1' && data->map[(int)ray->end_x][y] == '0')
// 		ray->side = WEST;
// 	else if (data->map[x - 1][(int)ray->end_y] == '1')
// 		ray->side = EAST;
// 	else
// 		ray->side = SOUTH;
// }

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
	float	y;

	y = 0;
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		return ;
	print_pos(data->player);
	data->player->radian = 1.75;
	send_ray(data);
	y = ray_length(data);
	while (data->player->radian > 1)
	{
		send_ray(data);
		x = ray_length(data);
		printf(CYAN"%.2f "RESET, x);
		if (fabs(y - x) > 0.1)
			print_side(data->ray);
		y = x;
		// print_side(data->ray);
		data->player->radian -= 0.001;
	}
	print_side(data->ray);

		// 	send_ray(data);
	// 	x = ray_length(data);
	// 	printf(CYAN"%.2f "RESET, x);
	// 	print_side(data->ray);
}
