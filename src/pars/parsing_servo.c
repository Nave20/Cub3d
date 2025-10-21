/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_servo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:04:00 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/21 11:26:28 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

// int	dispatcher(char *line, int fd, t_texture *texture, int error)
// {

// }

int	dispatcher_loop(int fd, t_texture *texture, int error, char *line)
{
	line = get_next_line(fd, &error);
	if (error)
		return (1);
	while (line)
	{
		if (ft_strnstr(line, "NO ", ft_strlen(line)) != NULL
			&& texture->valid_north == false)
			get_no(fd, texture, line);
		else if (ft_strnstr(line, "SO ", ft_strlen(line)) != NULL
			&& texture->valid_south == false)
			get_so(fd, texture, line);
		else if (ft_strnstr(line, "WE ", ft_strlen(line)) != NULL
			&& texture->valid_west == false)
			get_we(fd, texture, line);
		else if (ft_strnstr(line, "EA ", ft_strlen(line)) != NULL
			&& texture->valid_east == false)
			get_ea(fd, texture, line);
		else if (ft_strnstr(line, "F ", ft_strlen(line)) != NULL
			&& texture->valid_floor == false)
			get_f(fd, texture, line);
		else if (ft_strnstr(line, "C ", ft_strlen(line)) != NULL
			&& texture->valid_ceiling == false)
			get_c(fd, texture, line);
		else if (texture->valid_north == true && texture->valid_south == true && texture->valid_west == true && texture->valid_east == true && texture->valid_floor == true && texture->valid_ceiling == true)
		{
			free(line);
			return (0);
		}
		else
		{
			free(line);
			line = get_next_line(fd, &error);
			if (error)
				return (1);
		}
	}
	if (line == NULL)
		return (1);
	return (0);
}

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

