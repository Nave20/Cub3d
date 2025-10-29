/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_dispatcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:55:07 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/29 17:11:41 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

bool	all_textures_valid(t_texture *texture)
{
	if (texture->valid_north == true && texture->valid_south == true
		&& texture->valid_west == true && texture->valid_east == true
		&& texture->valid_floor == true && texture->valid_ceiling == true)
		return (1);
	else
		return (0);
}

int	wall_dispatcher(char *line, t_all *all, int fd)
{
	if (ft_strnstr(line, "NO ", ft_strlen(line)) != NULL
		&& all->texture->valid_north == false)
	{
		get_no(fd, all, line);
		return (1);
	}
	else if (ft_strnstr(line, "SO ", ft_strlen(line)) != NULL
		&& all->texture->valid_south == false)
	{
		get_so(fd, all, line);
		return (1);
	}
	else if (ft_strnstr(line, "WE ", ft_strlen(line)) != NULL
		&& all->texture->valid_west == false)
	{
		get_we(fd, all, line);
		return (1);
	}
	else if (ft_strnstr(line, "EA ", ft_strlen(line)) != NULL
		&& all->texture->valid_east == false)
	{
		get_ea(fd, all, line);
		return (1);
	}
	return (0);
}

int	floor_ceiling_dispatcher(char *line, t_all *all, int fd)
{
	if (ft_strnstr(line, "F ", ft_strlen(line)) != NULL
		&& all->texture->valid_floor == false)
	{
		get_f(fd, all, line);
		return (1);
	}
	else if (ft_strnstr(line, "C ", ft_strlen(line)) != NULL
		&& all->texture->valid_ceiling == false)
	{
		get_c(fd, all, line);
		return (1);
	}
	return (0);
}

int	dispatcher_loop(int fd, t_all *all, int error, char *line)
{
	line = get_next_line(fd, &error);
	if (error)
		return (1);
	while (line)
	{
		if (wall_dispatcher(line, all, fd) == 1)
			;
		else if (floor_ceiling_dispatcher(line, all, fd) == 1)
			;
		else if (all_textures_valid(all->texture))
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
