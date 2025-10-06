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