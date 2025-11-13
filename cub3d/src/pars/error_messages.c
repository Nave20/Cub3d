/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:11:51 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/12 12:01:55 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	err_malloc(t_all *all, int fd)
{
	if (fd != -1)
		close(fd);
	ft_putendl_fd(RED"Error\n -> allocating memory"RESET, 2);
	exit_game(all);
}

void	err_gnl(t_all *all)
{
	ft_putendl_fd(RED"Error\n -> get_next_line"RESET, 2);
	exit_game(all);
}

void	err_strdup(t_all *all)
{
	ft_putendl_fd(RED"Error\n -> ft_strdup"RESET, 2);
	exit_game(all);
}

void	wrong_format(t_all *all)
{
	ft_putendl_fd(RED"Error\n -> all texture files must be terminated "
		"by .xpm"RESET, 2);
	exit_game(all);
}

void	err_split(t_all *all)
{
	ft_putendl_fd(RED"Error\n -> ft_split"RESET, 2);
	exit_game(all);
}
