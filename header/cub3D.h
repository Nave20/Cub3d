/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:31:36 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/07 13:13:03 by lpaysant         ###   ########.fr       */
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
# define MAP_MAX 100

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

//---------------------------GLOBAL VARIABLES--------------------------

//-------------------------------STRUCTS-------------------------------

typedef struct s_data	t_data;
typedef struct s_lst	t_lst;
struct					s_data
{
	char				**map;
	int					lines;
	int					cols;
};

// void					get_map(int fd, t_data *data);

void					print_lst(t_list *lst);
void					find_map(int fd, t_data *data);
void					char_check(t_data *data);
void					error_exit(char *err_msg);
void					free_lst(t_list *lst);

#endif
