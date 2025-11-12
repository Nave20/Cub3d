/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:31:36 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/12 11:56:15 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define CLEAR "\033[H\033[J"
# define YELLOW "\033[33m"
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[0;32m"
# define CYAN "\033[36m"
# define RED "\033[31m"
# define PURPLE "\033[35m"
# define PINK "\033[38;5;201m"
# define ORANGE "\033[38;5;214m"
# define BOLD "\033[1m"
# define WHITE "\033[0m"
# define UNDER "\033[4m"
# define BLINK "\033[5m"
# define REVERSE "\033[7m"
# define PI 3.14159265358979323846
# define TWOPI 6.28318530717958647692
# define POV_INCR 0.0625
# define TRIG_TABLE 8192
# define SIZE 100
# define POV 0.5f
# define STEP 0.15

//-------------------------------INCLUDE-------------------------------
# include "../src/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include "struct.h"

//---------------------------------------------------------------------
//-------------------------------PARSING-------------------------------
//---------------------------------------------------------------------

//--------------------------------SERVO--------------------------------
int		parsing_servo(t_all *all, int fd);
int		dispatcher_loop(int fd, t_all *all, int error, char *line);

//-----------------------------GET_TEXTURE-----------------------------
void		get_no(int fd, t_all *all, char *line);
void		get_so(int fd, t_all *all, char *line);
void		get_we(int fd, t_all *all, char *line);
void		get_ea(int fd, t_all *all, char *line);

//------------------------------GET_COLOR------------------------------
void		get_f(int fd, t_all *all, char *line);
void		get_c(int fd, t_all *all, char *line);

//------------------------------VALIDATION-----------------------------
void		arg_validation(t_all *all, t_texture *texture);

//--------------------------------UTILS--------------------------------
int		strnstr_int(const char *src, const char *tofind, size_t size);
void	texture_print(t_texture *texture);

//--------------------------------FREE---------------------------------
int		free_textures(t_texture *texture, char *line);
int		free_double_tab(char **tab);

//-----------------------------ERR_MESSAGE-----------------------------
void	err_gnl(t_all *all);
void	err_split(t_all *all);
void	err_strdup(t_all *all);
void	wrong_format(t_all *all);
void	err_malloc(t_all *all, int fd);
void	free_mlx(t_mlx *mlx);
void	destroy_images(t_mlx *mlx);
int		exit_game(t_all *all);
void	free_texture(t_texture *texture);
void	free_anim(t_all *all);
void	free_addr(t_texture *texture);

//---------------------------------MAP---------------------------------
void	print_lst(t_list *lst);
void	find_map(int fd, t_all *all);
void	error_exit(char *err_msg, t_all *all, t_list *lst);
void	free_lst(t_list *lst);
void	free_map_tab(char **tab);
void	print_map(char **tab);
bool	is_map_line(char *str);
bool	is_good_char(char c);
bool	is_player(char c);
bool	is_invalid_char(char c);
void	find_cols_nb_map(t_data *data, t_list *lst);
void	add_fist_border_to_tab(t_list *lst, t_all *all);
void	add_last_border_to_tab(t_list *lst, t_all *all, int i);
void	map_parsing(t_data *data, t_all *all);
void	check_file_ending(int fd, t_all *all, char *buffer, t_list *lst);

//-------------------------------MLX----------------------------------
void	init_mlx(t_all *all, t_mlx *mlx);
void	get_screen_size(t_all *all);



//-------------------------------MINIMAP-------------------------------
void	get_minimap(t_all *all);
void	init_minimap(t_all *all);
void	fill_minimap_image(t_all *all);
//---------------------------------------------------------------------
//-------------------------------MOVEMENT------------------------------
//---------------------------------------------------------------------

//-------------------------------PLAYER--------------------------------
int		create_player(t_all *all);

//--------------------------------WASD---------------------------------
void	w_key(t_data *data, float new_x, float new_y);
void	a_key(t_data *data, float new_x, float new_y);
void	s_key(t_data *data, float new_x, float new_y);
void	d_key(t_data *data, float new_x, float new_y);
int		key_event(int keycode, t_all *all);
int		key_press(int keycode, t_all *all);
int		key_release(int keycode, t_all *all);
int		key_check(t_all *all);
int		mouse_hook(int x, int y, t_all *all);

//---------------------------------POV---------------------------------
void	letf_arr(t_data *data);
void	right_arr(t_data *data);

//--------------------------------UTILS--------------------------------
void	print_pos(t_player *player);

//---------------------------------------------------------------------
//----------------------------------RAY--------------------------------
//---------------------------------------------------------------------

void	ray_servo(t_data *data, int i);
float	dda(t_data *data, float dir_x, float dir_y);
void	side_touched(t_data *data, int side, float dir_x, float dir_y);
void	fast_trig(t_data *data);
float	ft_trig(t_data *data, float angle, t_trig type);
void	print_ray_touch(t_data *data, int x, int y);
void	wall_height(t_data *data, float wall_dist, int col,float ray);
float	select_impact(t_data *data);
float	side_y(t_data *data, float dir_y, float delta_y);
float	side_x(t_data *data, float dir_x, float delta_x);

//-------------------------------------------------------------------------
//----------------------------------RENDER---------------------------------
//-------------------------------------------------------------------------

t_argb	yx_back_converter(t_addr *addr, int y, int x);
void	yx_converter(t_all *all, t_argb color, int y, int x);
void	rendering(t_all *all, t_render *render, int x);
void	render_north(t_all *all, t_render *render, int x, int z);
void	render_south(t_all *all, t_render *render, int x, int z);
void	render_west(t_all *all, t_render *render, int x, int z);
void	render_east(t_all *all, t_render *render, int x, int z);

void	update(t_all *all);

void	get_images(t_all *all, t_mlx *mlx);
void	render_w(t_all *all, t_render *render, int x);
void	render_n(t_all *all, t_render *render, int x);
void	render_e(t_all *all, t_render *render, int x);
void	render_s(t_all *all, t_render *render, int x);

void	draw_ceiling(t_all *all, int max, int z);
void	draw_floor(t_all *all, int start, int z);

void	ray_values(t_data *data, float dir_x, float dir_y);
float	dda_return(t_data *data, float dir_x, float dir_y);

void	f_key(t_all *all);
float	door_dda(t_data *data, float dir_x, float dir_y);
void	get_do(int fd, t_all *all, char *line);
void	render_d(t_all *all, t_render *render, int x);
float	door_detect(t_data *data, float ray);
void	change_anim(t_all *all, int x);
void	load_anim(t_all *all);
void	anim_void_error(t_all *all, int end);

void	put_txt_to_window(t_all *all, t_addr *addr, int height, int width);
void	get_d_image(t_all *all, t_mlx *mlx, int w, int h);
void	get_txt_image(t_all *all, t_mlx *mlx, int w, int h);


#endif
