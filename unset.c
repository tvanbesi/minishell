/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:27:15 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/09 15:51:22 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_unset(t_list *argv, t_shell *shell)
{
	t_list	*current;
	t_token	*content;
	char	*s;

	if (!argv || ((t_token*)(argv->content))->type == OPERATOR)
	{
		printf("not enough argv\n");
		return (-1);
	}
	current = argv;
	while (current)
	{
		content = current->content;
		if (content->type == WORD)
		{
			if (!content->qt && !(s = ft_strtrim(content->s, " \t")))
				return (-1);
			else if (content->qt && !(s = ft_strdup(content->s)))
				return (-1);
			ft_remove_env(s, shell);
			free(s);
		}
		else if (content->type == OPERATOR)
			return (0);
		current = current->next;
	}
	return (0);
}
