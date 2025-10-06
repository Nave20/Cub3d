/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_servo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:04:00 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/06 14:04:00 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	dispatcher(int fd, t_texture *texture, int error, char *line)
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
		else
		{
			free(line);
			line = get_next_line(fd, &error);
			if (error)
				return (1);
		}
	}
	return (0);
}

void	texture_init(t_texture *texture)
{
	texture->valid = false;
	texture->north_texture = NULL;
	texture->south_texture = NULL;
	texture->west_texture = NULL;
	texture->east_texture = NULL;
	texture->valid_north = false;
	texture->valid_south = false;
	texture->valid_west = false;
	texture->valid_east = false;
}

int	parsing_servo(char *file)
{
	int			fd;
	t_texture	*texture;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(RED"Error\n opening file"RESET);
		exit(errno);
	}
	texture = malloc(sizeof(t_texture));
	if (!texture)
	{
		close(fd);
		perror(RED"Error\n allocating memory"RESET);
		exit(errno);
	}
	texture_init(texture);
	if (dispatcher(fd, texture, 0, NULL))
		return (1);
	texture_print(texture);
	free_textures(texture, NULL);
	return (0);
}