/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:31:36 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/06 15:23:10 by lpaysant         ###   ########.fr       */
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

typedef struct s_data		t_data;
struct 			s_data
{
	char	**map;
};

void	get_map(char **map, t_data *data);
void	char_check(t_data *data);

#endif
