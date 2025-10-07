/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:09:29 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/07 12:43:36 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int	fd;
	int	nb;

	if (argc != 2)
	{
		perror(RED "Error\nThere must be exactly one map file as argument\n" RESET);
		return (1);
	}
	(void)argv;
	nb = ft_strlen(argv[1]);
	if (ft_strncmp(".cub", argv[1] + ft_strlen(argv[1]) - 4, 5) != 0)
	{
		ft_putstr_fd("Error\nWrong file extension\n", 2);
		return (1);
	}
	data = NULL;
	fd = open("test.txt", O_RDONLY);
	if(fd == -1)
		error_exit("Error\nFile opening failure\n");
	find_map(fd, data);

	// char_check(data);
}
