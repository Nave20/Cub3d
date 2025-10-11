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

void	ray_servo(t_data *data)
{
	float	y;

	y = 0;
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		return ;
	print_pos(data->player);
	data->player->radian = 1.75f;
	y = pre_dda(data);
	printf(YELLOW"length : %f\n"RESET, y);
	// while (data->player->radian > 0.75f)
	// {
	// 	y = pre_dda(data);
	// 	printf(YELLOW"length : %f\n"RESET, y);
	// 	data->player->radian -= 0.01f;
	// }
}
