/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:32:33 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/09 10:32:33 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	print_pos(t_player *player)
{
	printf(BLUE"POS x :"RESET);
	printf(BOLD " %f\n"RESET, player->pos_x);
	printf(RED"POS y :"RESET);
	printf(BOLD " %f\n"RESET, player->pos_y);
	printf("\n");
}