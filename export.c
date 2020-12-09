/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:32:24 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/09 16:52:42 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int
	ft_parse_export(int qt, char *word, t_shell *shell)
{
	char	*val;
	char	*name;
	t_env	*content;
	t_list	*newenv;

	val = ft_strchr(word, '=');
	if (val)
	{
		if (qt && !(val = ft_strdup(val + 1)))
			return (-1);
		else if (!qt && !(val = ft_substr(val, 2, ft_strlen(val) - 3)))
			return (-1);
		if (!(name = ft_substr(word, 0, ft_strlen(word) - (ft_strlen(val) + 1) - !qt * 2)))
			return (-1);
		printf("|%s|\t|%s|\n", name, val);
		if (!(content = ft_new_env(name, val, 1)))
			return (-1);
		if (!(newenv = ft_lstnew(content)))
			return (-1);
		if (ft_get_env(name, shell))
		{
			if (ft_edit_env(name, val, shell) == -1)
				return (-1);
		}
		else
			ft_lstadd_back(&shell->env, newenv);
	}
	return (0);
}

int
	ft_export(t_list *argv, t_shell *shell)
{
	t_list	*current;
	t_token	*content;
	char	*s;

	if (!argv || (argv && ((t_token*)(argv->content))->type == OPERATOR))
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
			if (ft_parse_export(content->qt, s, shell) == -1)
				return (-1);
			free(s);
		}
		else if (content->type == OPERATOR)
			return (0);
		current = current->next;
	}
	return (0);
}
