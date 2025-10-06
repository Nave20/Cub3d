/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:09:29 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/06 15:23:20 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		perror(RED "Error\nThere must be exactly one map file as argument\n" RESET);
		return (1);
	}
	get_map(argv[1], data);
	char_check(data);
}
