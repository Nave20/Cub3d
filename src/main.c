/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:09:29 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/09 18:26:39 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	arg_nbr_and_extension_check(t_all *all, int argc, char **argv)
{
	int	nb;

	if (argc != 2)
		error_exit("Error\nThere must be only one arg\n", all, NULL);
	(void)argv;
	nb = ft_strlen(argv[1]);
	if (ft_strncmp(".cub", argv[1] + ft_strlen(argv[1]) - 4, 5) != 0)
		error_exit("Error\nWrong file extension\n", all, NULL);
}

int	main(int argc, char **argv)
{
	t_all	*all;
	int		fd;

	all = ft_calloc(1, sizeof(t_all));
	arg_nbr_and_extension_check(all, argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error\nFile opening failure\n", all, NULL);
	all->data = ft_calloc(1, sizeof(t_data));
	if (!all->data)
		error_exit("Error\nMalloc failure\n", all, NULL);
	parsing_servo(fd);
	find_map(fd, all);
	map_parsing(all->data, all);
	all->mlx = ft_calloc(1, sizeof(t_mlx));
	if (!all->mlx)
		error_exit("Error\nMalloc failure\n", all, NULL);
	free_map_tab(all->data->map);
	free(all->data);
	return (0);
}
