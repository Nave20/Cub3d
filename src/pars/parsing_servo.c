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
	texture->valid = false;
}