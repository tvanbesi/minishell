/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:10:12 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/10 10:57:35 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_env(t_list *argv, t_shell *shell)
{
	t_list	*current;
	t_token	*content;
	t_env	*env;

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
	current = shell->env;
	while (current)
	{
		env = (t_env*)current->content;
		ft_putstr_fd(env->name, 1);
		ft_putchar_fd('=', 1);
		ft_putendl_fd(env->val, 1);
		current = current->next;
	}
	return (0);
}
