/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:10:12 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/09 13:51:56 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_env(t_list *argv, t_shell *shell)
{
	t_list	*current;
	t_env	*content;

	if (argv && ((t_token*)(argv->content))->type != OPERATOR)
	{
		printf("too many argv\n");
		return (-1);
	}
	current = shell->env;
	while (current)
	{
		content = (t_env*)current->content;
		ft_putstr_fd(content->name, 1);
		ft_putchar_fd('=', 1);
		ft_putendl_fd(content->val, 1);
		current = current->next;
	}
	return (0);
}
