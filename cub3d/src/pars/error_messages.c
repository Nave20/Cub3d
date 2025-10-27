/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:11:51 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/06 16:11:51 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	err_malloc(int fd)
{
	if (fd != -1)
		close(fd);
	perror(RED"Error\n -> allocating memory"RESET);
	exit(errno);
}

int	err_gnl(void)
{
	perror(RED"Error\n -> get_next_line"RESET);
	return (1);
}

int	err_strdup(void)
{
	perror(RED"Error\n -> ft_strdup"RESET);
	return (1);
}

int	wrong_format(void)
{
	perror(RED"Error\n -> all texture files must be terminated by .xpm"RESET);
	return (1);
}

int	err_split(void)
{
	perror(RED"Error\n -> ft_split"RESET);
	return (1);
}
