/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:09:29 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/12 12:40:40 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	arg_nbr_and_extension_check(t_all *all, int argc, char **argv)
{
	int	nb;

	if (argc != 2)
		error_exit(RED"Error\nThere must be only one arg\n"RESET, all, NULL);
	(void)argv;
	nb = (int)ft_strlen(argv[1]);
	if (ft_strncmp(".cub", argv[1] + ft_strlen(argv[1]) - 4, 5) != 0)
		error_exit(RED"Error\nWrong file extension\n"RESET, all, NULL);
}

static void	struct_init(t_all *all)
{
	all->data = ft_calloc(1, sizeof(t_data));
	if (!all->data)
		error_exit(RED"Error\nMalloc failure\n"RESET, all, NULL);
	all->data->all = all;
	all->mlx = ft_calloc(1, sizeof(t_mlx));
	if (!all->mlx)
		error_exit(RED"Error\nMalloc failure\n"RESET, all, NULL);
	all->texture = ft_calloc(1, sizeof(t_texture));
	if (!all->texture)
		error_exit(RED"Error\nMalloc failure\n"RESET, all, NULL);
	all->data->texture = all->texture;
	all->data->ray = malloc(sizeof(t_ray));
	if (!all->data->ray)
		error_exit(RED"Error\nMalloc failure\n"RESET, all, NULL);
	all->data->render = malloc(sizeof(t_render));
	if (!all->data->render)
		error_exit(RED"Error\nMalloc failure\n"RESET, all, NULL);
	all->mouse = ft_calloc(1, sizeof(t_mouse));
	if (!all->mouse)
		error_exit(RED"Error\nMalloc failure\n"RESET, all, NULL);
	all->string_color.a = 255;
	all->string_color.r = 0;
	all->string_color.g = 255;
	all->string_color.b = 0;
}

static void	open_game(t_all *all, t_mlx *mlx)
{
	all->mouse->mid_x = all->data->screen_width / 2;
	all->mouse->mid_y = all->data->screen_height / 2;
	all->mouse->x = all->mouse->mid_x;
	all->mouse->y = all->mouse->mid_y;
	load_anim(all);
	init_minimap(all);
	fill_minimap_image(all);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			all->data->screen_width, all->data->screen_height, "cub3D");
	if (!mlx->win_ptr)
	{
		ft_putendl_fd(RED"Error\nmlx_new_window failed"RESET, 2);
		exit_game(all);
	}
	mlx_mouse_hide(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->fc_image, 0, 0);
	mlx_put_image_to_window(all->mlx->mlx_ptr, all->mlx->win_ptr,
		all->minimap->image, 0, 0);
	mlx_hook(mlx->win_ptr, 17, 0, exit_game, all);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, key_press, all);
	mlx_hook(mlx->win_ptr, 3, 1L << 1, key_release, all);
	mlx_hook(mlx->win_ptr, 6, 1L << 6, mouse_hook, all);
	mlx_loop_hook(mlx->mlx_ptr, key_check, all);
	mlx_loop(mlx->mlx_ptr);
}

static void	main_dispatcher(t_all *all, int fd)
{
	struct_init(all);
	parsing_servo(all, fd);
	find_map(fd, all);
	map_parsing(all->data, all);
	get_screen_size(all);
	init_mlx(all, all->mlx);
	fast_trig(all->data);
	create_player(all);
	open_game(all, all->mlx);
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
	main_dispatcher(all, fd);
	return (0);
}
