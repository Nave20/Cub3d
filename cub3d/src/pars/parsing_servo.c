/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_servo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:04:00 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/12 12:01:55 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	texture_init(t_texture *texture)
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
}

static void	texture_alloc(t_all *all)
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
		err_malloc(all, fd);
	if (dispatcher_loop(fd, all, 0, NULL))
		return (1);
	arg_validation(all, all->texture);
	return (0);
}
