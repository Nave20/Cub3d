/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:09:29 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/08 17:35:51 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	arg_nbr_and_extension_check(int argc, char **argv)
{
	int	nb;

	if (argc != 2)
		error_exit("Error\nThere must be only one arg\n", NULL, NULL);
	(void)argv;
	nb = ft_strlen(argv[1]);
	if (ft_strncmp(".cub", argv[1] + ft_strlen(argv[1]) - 4, 5) != 0)
		error_exit("Error\nWrong file extension\n", NULL, NULL);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	arg_nbr_and_extension_check(argc, argv);
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
