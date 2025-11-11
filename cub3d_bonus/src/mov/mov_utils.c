/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:32:33 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/11 12:14:44 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	print_pos(t_player *player) // a enlever avant de push
{
	printf(BLUE"POS x :"RESET);
	printf(BOLD " %f\n"RESET, player->pos_x);
	printf(RED"POS y :"RESET);
	printf(BOLD " %f\n"RESET, player->pos_y);
	printf("\n");
}
