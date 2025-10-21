/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:09:29 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/21 11:52:02 by lpaysant         ###   ########.fr       */
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

void	get_screen_size(t_all *all)
{
	int	x;
	int	y;

	all->mlx->mlx_ptr = mlx_init();
	mlx_get_screen_size(all->mlx->mlx_ptr, &x, &y);
	all->data->screen_height = y;
	all->data->screen_width = x;
}

void	struct_init(t_all *all)
{
	all->data = ft_calloc(1, sizeof(t_data));
	if (!all->data)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->data->all = all;
	all->mlx = ft_calloc(1, sizeof(t_mlx));
	if (!all->mlx)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->texture = ft_calloc(1, sizeof(t_texture));
	if (!all->texture)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->data->texture = all->texture;
	all->data->ray = malloc(sizeof(t_ray));
	if (!all->data->ray)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->data->render = malloc(sizeof(t_render));
	if (!all->data->render)
		error_exit("Error\nMalloc failure\n", all, NULL);
}

void	open_game(t_all *all, t_mlx *mlx)
{
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			all->data->screen_width, all->data->screen_height, "cub3D");
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->fc_image, 0, 0);
	mlx_hook(mlx->win_ptr, 17, 0, exit_game, all);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, key_press, all);
	mlx_hook(mlx->win_ptr, 3, 1L << 1, key_release, all);
	mlx_loop_hook(mlx->mlx_ptr, key_check, all);
	mlx_loop(mlx->mlx_ptr);
	free_map_tab(all->data->map);
	free(all->data);
}

int	main(int argc, char **argv)
{
	t_all	*all;
	int		fd;

	all = ft_calloc(1, sizeof(t_all));
	if (!all)
	{
		ft_putstr_fd("Error\nMalloc failure\n", 2);
		return (1);
	}
	arg_nbr_and_extension_check(all, argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error\nFile opening failure\n", all, NULL);
	struct_init(all);
	parsing_servo(all, fd);
	find_map(fd, all);
	map_parsing(all->data, all);
	get_screen_size(all);
	display_game(all, all->mlx);
	fast_trig(all->data);
	create_player(all->data);
	ray_servo(all->data, 0);
	open_game(all, all->mlx);
	return (0);
}
