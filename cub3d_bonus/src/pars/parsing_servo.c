/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_servo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:04:00 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/28 17:20:42 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	texture_init(t_texture *texture)
{
	texture->valid = false;
	texture->floor_color->color = NULL;
	texture->ceiling_color->color = NULL;
	texture->north_texture = NULL;
	texture->south_texture = NULL;
	texture->west_texture = NULL;
	texture->east_texture = NULL;
	texture->valid_ceiling = false;
	texture->valid_floor = false;
	texture->valid_north = false;
	texture->valid_south = false;
	texture->valid_west = false;
	texture->valid_east = false;
	texture->door_texture = false;
	texture->valid_door = false;
}

void	texture_alloc(t_all *all)
{
	all->texture->floor_color = malloc(sizeof(t_color));
	if (all->texture->floor_color == NULL)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->texture->ceiling_color = malloc(sizeof(t_color));
	if (all->texture->ceiling_color == NULL)
		error_exit("Error\nMalloc failure\n", all, NULL);
	texture_init(all->texture);
}

int	parsing_servo(t_all *all, int fd)
{
	texture_alloc(all);
	if (!all->texture)
		err_malloc(fd);
	if (dispatcher_loop(fd, all->texture, 0, NULL))
		return (1);
	if (arg_validation(all->texture))
		return (1);
	return (0);
}
