/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:31:36 by vpirotti          #+#    #+#             */
/*   Updated: 2025/08/07 12:46:22 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
typedef struct	s_color			t_color;

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

#endif
