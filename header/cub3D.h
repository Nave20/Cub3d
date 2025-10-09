/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:31:36 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/08 17:21:39 by lpaysant         ###   ########.fr       */
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
# define BOLD "\033[1m"
# define UNDER "\033[4m"
# define BLINK "\033[5m"
# define REVERSE "\033[7m"
# define PI 3.14159265358979323846
# define SIZE 60
# define STEP 5

//-------------------------------INCLUDE-------------------------------
# include "../src/libft/libft.h"
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

//-------------------------------STRUCTS-------------------------------

typedef struct  s_texture		t_texture;
typedef struct  s_data			t_data;
typedef struct	s_color			t_color;
typedef struct	s_player		t_player;

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
	char			*south_texture;
	bool			valid_south;
	char			*west_texture;
	bool			valid_west;
	char			*east_texture;
	bool			valid_east;
	t_color			*floor_color;
	bool			valid_floor;
	t_color			*ceiling_color;
	bool			valid_ceiling;
};

struct					s_data
{
	char				**map;
	int					lines;
	int					cols;
	t_player			*player;
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

//---------------------------------------------------------------------
//-------------------------------PARSING-------------------------------
//---------------------------------------------------------------------

//--------------------------------SERVO--------------------------------
int		parsing_servo(char *file);

//-----------------------------GET_TEXTURE-----------------------------
int		get_no(int fd, t_texture *texture, char *line);
int		get_so(int fd, t_texture *texture, char *line);
int		get_we(int fd, t_texture *texture, char *line);
int		get_ea(int fd, t_texture *texture, char *line);

//------------------------------GET_COLOR------------------------------
int		get_f(int fd, t_texture *texture, char *line);
int		get_c(int fd, t_texture *texture, char *line);

//------------------------------VALIDATION-----------------------------
int		arg_validation(t_texture *texture);

//--------------------------------UTILS--------------------------------
int		strnstr_int(const char *src, const char *tofind, size_t size);
void	texture_print(t_texture *texture);

//--------------------------------FREE---------------------------------
int		free_textures(t_texture *texture, char *line);
int		free_double_tab(char **tab);

//-----------------------------ERR_MESSAGE-----------------------------
int		err_gnl(void);
int		err_split(void);
int		err_strdup(void);
int		wrong_format(void);
void	err_malloc(int fd);

//---------------------------------MAP---------------------------------
void	print_lst(t_list *lst);
void	find_map(int fd, t_data *data);
void	char_check(t_data *data);
void	error_exit(char *err_msg, t_list *lst, t_data *data);
void	free_lst(t_list *lst);
void	free_map_tab(char **tab);
void	print_map(char **tab);
bool	is_map_line(char *str);
bool	is_good_char(char c);
void	find_cols_nb_map(t_data *data, t_list *lst);
void	add_fist_border_to_tab(t_list *lst, t_data *data);
void	add_last_border_to_tab(t_list *lst, t_data *data, int i);
void	map_parsing(t_data *data);
void	check_file_ending(int fd, t_data *data, char *buffer, t_list *lst);

//---------------------------------------------------------------------
//-------------------------------MOVEMENT------------------------------
//---------------------------------------------------------------------

//--------------------------------SERVO--------------------------------

//-------------------------------PLAYER--------------------------------
int		create_player(t_data *data);

#endif
