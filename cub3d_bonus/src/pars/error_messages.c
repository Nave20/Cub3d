/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:11:51 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/29 14:02:05 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	err_malloc(t_all *all, int fd)
{
	if (fd != -1)
		close(fd);
	perror(RED"Error\n -> allocating memory"RESET);
	exit_game(all);
}

int	err_gnl(t_all *all)
{
	perror(RED"Error\n -> get_next_line"RESET);
	exit_game(all);
	return (1);
}

int	err_strdup(t_all *all)
{
	perror(RED"Error\n -> ft_strdup"RESET);
	exit_game(all);
	return (1);
}

int	wrong_format(t_all* all)
{
	perror(RED"Error\n -> all texture files must be terminated by .xpm"RESET);
	exit_game(all);
	return (1);
}

int	err_split(t_all *all)
{
	perror(RED"Error\n -> ft_split"RESET);
	exit_game(all);
	return (1);
}
