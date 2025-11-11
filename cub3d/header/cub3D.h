/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:31:36 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/11 17:20:33 by lpaysant         ###   ########.fr       */
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
# include "../../minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/param.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>

//-------------------------------STRUCTS-------------------------------

typedef struct  s_texture		t_texture;
typedef struct  s_data			t_data;
typedef struct	s_color			t_color;
typedef struct	s_player		t_player;
typedef struct	s_ray			t_ray;
typedef struct  s_mlx			t_mlx;
typedef struct  s_all			t_all;
typedef enum    e_side			t_side;
typedef enum    e_trig			t_trig;
typedef union   s_argb			t_argb;
typedef struct	s_render		t_render;
typedef struct	s_addr			t_addr;
typedef struct	s_pxl			t_pxl;
typedef struct	s_key			t_key;
typedef struct	s_mouse			t_mouse;
typedef struct	s_minimap		t_minimap;






enum			e_side
{
	EAST,
	NORTH,
	WEST,
	SOUTH,
};

enum			e_trig
{
	COS,
	SIN,
	TAN,
};

struct			s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left_arrow;
	int	right_arrow;
};


union			s_argb
{
	uint32_t	argb;
	struct
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
		uint8_t	a;
	};
};

struct			s_all
{
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	t_mlx		*mlx;
	t_color		*color;
	t_texture	*texture;
	t_data		*data;
	t_key		*key;
	t_mouse		*mouse;
	t_minimap	*minimap;
};

struct			s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w_win;
	int		h_win;
	void	*n_texture;
	void	*s_texture;
	void	*e_texture;
	void	*w_texture;
	void	*fc_image;
	char	**img_tab;
	t_argb	f_color;
	t_argb	c_color;
};

struct			s_color
{
	char			*color;
	int				r;
	int				g;
	int				b;
};

struct			s_texture
{
	bool			valid;
	char			*north_texture;
	bool			valid_north;
	int				width_n;
	int				height_n;
	t_addr			*addr_n;
	char			*south_texture;
	bool			valid_south;
	int				width_s;
	int				height_s;
	t_addr			*addr_s;
	char			*west_texture;
	bool			valid_west;
	int				width_w;
	int				height_w;
	t_addr			*addr_w;
	char			*east_texture;
	bool			valid_east;
	int				width_e;
	int				height_e;
	t_addr			*addr_e;
	t_color			*floor_color;
	bool			valid_floor;
	t_color			*ceiling_color;
	bool			valid_ceiling;
};

struct					s_data
{
	int					screen_width;
	int					screen_height;
	char				**map;
	int					lines;
	int					cols;
	float				f_sin[TRIG_TABLE];
	float				f_cos[TRIG_TABLE];
	float				f_tan[TRIG_TABLE];
	t_ray				*ray;
	t_player			*player;
	t_all				*all;
	t_render			*render;
	t_texture			*texture;
};

struct					s_render
{
	float				wall_height;
	float				correct_dist;
	float				text_perc;
	float				impact;
	int					draw_start;
	int					draw_end;
	float				to_draw;
	float				text_to_put;
	float				coef_pix;
	float				lost_pix;
	float				start_on_texture;
	int					tex_x;
	int					tex_y;
};

struct					s_ray
{
	int					map_x;
	int					map_y;
	int					step_x;
	int					step_y;
	float				dir_x;
	float				dir_y;
	float				delta_x;
	float				delta_y;
	float				side_x;
	float				side_y;
	float				impact_x;
	float				impact_y;
	bool				last_side;
	t_side				side;
};

struct					s_player
{
	t_data				*data;
	float				radian;
	int					grid_x;
	int					grid_y;
	float				pos_x;
	float				pos_y;
};

struct					s_addr
{
	char				*addr;
	int					line_length;
	int					bpp;
	int					endian;
};

struct					s_pxl
{
	float				to_draw;
	float				text_to_put;
	float				coef_pix;
	float				lost_pix;
	float				start_on_texture;
};



//---------------------------------------------------------------------
//-------------------------------PARSING-------------------------------
//---------------------------------------------------------------------

//--------------------------------SERVO--------------------------------
int		parsing_servo(t_all *all, int fd);
int		dispatcher_loop(int fd, t_all *all, int error, char *line);

//-----------------------------GET_TEXTURE-----------------------------
void	get_no(int fd, t_all *all, char *line);
void	get_so(int fd, t_all *all, char *line);
void	get_we(int fd, t_all *all, char *line);
void	get_ea(int fd, t_all *all, char *line);

//------------------------------GET_COLOR------------------------------
void	get_f(int fd, t_all *all, char *line);
void	get_c(int fd, t_all *all, char *line);

//------------------------------VALIDATION-----------------------------
void	arg_validation(t_all *all, t_texture *texture);

//--------------------------------UTILS--------------------------------
int		strnstr_int(const char *src, const char *tofind, size_t size);
void	texture_print(t_texture *texture);

//--------------------------------FREE---------------------------------
int		free_double_tab(char **tab);

//-----------------------------ERR_MESSAGE-----------------------------
void	err_gnl(t_all *all);
void	err_split(t_all *all);
void	err_strdup(t_all *all);
void	wrong_format(t_all *all);
void	err_malloc(t_all *all, int fd);

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

void	init_mlx(t_all *all, t_mlx *mlx);
void	get_screen_size(t_all *all);
int		exit_game(t_all *all);
void	free_mlx(t_mlx *mlx);

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
void	left_arr_mouse(t_data *data);
void	right_arr_mouse(t_data *data);

//--------------------------------UTILS--------------------------------
void	print_pos(t_player *player);

//---------------------------------------------------------------------
//----------------------------------RAY--------------------------------
//---------------------------------------------------------------------

void	ray_servo(t_data *data, int i);
float	dda(t_data *data, float dir_x, float dir_y);
void	fast_trig(t_data *data);
float	ft_trig(t_data *data, float angle, t_trig type);
void	print_ray_touch(t_data *data, int x, int y);
void	wall_height(t_data *data, float wall_dist, int col,float ray);
float	select_impact(t_data *data);

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


#endif
