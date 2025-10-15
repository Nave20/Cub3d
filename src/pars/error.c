/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:27:54 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/15 10:55:05 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	free_map_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	error_exit(char *err_msg, t_all *all, t_list *lst)
{
	if (lst)
		free_lst(lst);
	// if (all->data)
	// {
	// 	if (all->data->map)
	// 		free_map_tab(all->data->map);
	// 	free(all->data);
	// }
	ft_putstr_fd(err_msg, 2);
	if(all)
		exit_game(all);
	exit(errno);
}

void	free_lst(t_list *lst)
{
	t_list	*ptr;

	while (lst->next)
	{
		ptr = lst->next;
		if (lst->content)
		{
			free(lst->content);
			lst->content = NULL;
		}
		free(lst);
		lst = ptr;
	}
	if (lst->content)
	{
		free(lst->content);
		lst->content = NULL;
	}
	free(lst);
}
