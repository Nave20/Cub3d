/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:09:29 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/08 15:05:26 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		fd;
	int		nb;

	if (argc != 2)
	{
		perror(RED "Error\nThere must be only one arg\n" RESET);
		return (1);
	}
	(void)argv;
	nb = ft_strlen(argv[1]);
	if (ft_strncmp(".cub", argv[1] + ft_strlen(argv[1]) - 4, 5) != 0)
	{
		perror(RED "Error\nWrong file extension\n" RESET);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error\nFile opening failure\n", NULL, NULL);
	data = ft_calloc(1, sizeof(t_data));
	// parsing_servo("test.txt");
	find_map(fd, data);
	map_parsing(data);
	free_map_tab(data->map);
	free(data);
	return (0);
}
