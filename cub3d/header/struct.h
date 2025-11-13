/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:02:09 by lpaysant          #+#    #+#             */
/*   Updated: 2025/11/12 12:03:48 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_texture		t_texture;
typedef struct s_data			t_data;
typedef struct s_color			t_color;
typedef struct s_player			t_player;
typedef struct s_ray			t_ray;
typedef struct s_mlx			t_mlx;
typedef struct s_all			t_all;
typedef enum e_side				t_side;
typedef enum e_trig				t_trig;
typedef union u_argb			t_argb;
typedef struct s_render			t_render;
typedef struct s_addr			t_addr;
typedef struct s_pxl			t_pxl;
typedef struct s_key			t_key;
typedef struct s_mouse			t_mouse;
typedef struct s_minimap		t_minimap;

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

union			u_argb
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

#endif
