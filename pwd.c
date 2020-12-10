/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:20:05 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/10 10:54:26 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_pwd(t_list *argv, t_shell *shell)
{
	char	*s;
	t_list	*current;
	t_token	*content;
	
	current = argv;
	if (current)
	{
		content = (t_token*)current->content;
		if (content->type == METACHAR)
			current = current->next;
		content = (t_token*)current->content;
		if (content->type == WORD)
		{
			printf("too many argv\n");
			return (-1);
		}
	}
	if (!(s = ft_get_env("PWD", shell)))
	{
		printf("no PWD env var found or malloc failed\n");
		return (-1);
	}
	ft_putendl_fd(s, 1);
	return (0);
}
