/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_dispatcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:18:51 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/28 17:24:32 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

bool	all_textures_valid(t_texture *texture)
{
	if (texture->valid_north == true && texture->valid_south == true
		&& texture->valid_west == true && texture->valid_east == true
		&& texture->valid_floor == true && texture->valid_ceiling == true
		&& texture->valid_door == true)
		return (1);
	else
		return (0);
}

int	first_dispatch(char *line, int fd, t_texture *texture)
{
	if (ft_strnstr(line, "NO ", ft_strlen(line)) != NULL
		&& texture->valid_north == false)
	{
		get_no(fd, texture, line);
		return (1);
	}
	else if (ft_strnstr(line, "SO ", ft_strlen(line)) != NULL
		&& texture->valid_south == false)
	{
		get_so(fd, texture, line);
		return (1);
	}
	else if (ft_strnstr(line, "WE ", ft_strlen(line)) != NULL
		&& texture->valid_west == false)
	{
		get_we(fd, texture, line);
		return (1);
	}
	else if (ft_strnstr(line, "EA ", ft_strlen(line)) != NULL
		&& texture->valid_east == false)
	{
		get_ea(fd, texture, line);
		return (1);
	}
	return (0);
}

int	second_dispatch(char *line, t_texture *texture, int fd)
{
	if (ft_strnstr(line, "EA ", ft_strlen(line)) != NULL
		&& texture->valid_east == false)
	{
		get_ea(fd, texture, line);
		return (1);
	}
	else if (ft_strnstr(line, "DO ", ft_strlen(line)) != NULL
		&& texture->valid_door == false)
	{
		get_do(fd, texture, line);
		return (1);
	}
	else if (ft_strnstr(line, "F ", ft_strlen(line)) != NULL
		&& texture->valid_floor == false)
	{
		get_f(fd, texture, line);
		return (1);
	}
	else if (ft_strnstr(line, "C ", ft_strlen(line)) != NULL
		&& texture->valid_ceiling == false)
	{
		get_c(fd, texture, line);
		return (1);
	}
	return (0);
}

int	dispatcher_loop(int fd, t_texture *texture, int error, char *line)
{
	line = get_next_line(fd, &error);
	if (error)
		return (1);
	while (line)
	{
		if (first_dispatch(line, fd, texture) == 1)
			;
		else if (second_dispatch(line, texture, fd) == 1)
			;
		else if (all_textures_valid(texture))
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
