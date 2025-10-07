/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:27:54 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/07 12:45:52 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	error_exit(char *err_msg)
{
	perror(err_msg);
	exit(errno);
}

void	free_lst(t_list *lst)
{
	t_list	*ptr;

	while(lst->next)
	{
		ptr = lst->next;
		if(lst->content)
		{
			free(lst->content);
			lst->content = NULL;
		}
		free(lst);
		lst = ptr;
	}
	if(lst->content)
	{
		free(lst->content);
		lst->content = NULL;
	}
	free(lst);
}
