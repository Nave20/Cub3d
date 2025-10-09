/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:09:29 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/09 16:55:10 by lpaysant         ###   ########.fr       */
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
	// t_data	*data;
	t_all	*all;
	int		fd;

	all = ft_calloc(1, sizeof(t_all));
	arg_nbr_and_extension_check(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error\nFile opening failure\n", NULL, NULL);
	all->data = ft_calloc(1, sizeof(t_data));
	if(!all->data)
		error_exit("Error\nMalloc failure\n", NULL, NULL);
	// parsing_servo(argv[1]);
	find_map(fd, all->data);
	map_parsing(all->data);
	all->mlx = ft_calloc(1, sizeof(t_mlx));
	fill_color_struct(all);
	free_map_tab(all->data->map);
	free(all->data);
	return (0);
}
