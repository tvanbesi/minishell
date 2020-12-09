/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:17:14 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/09 13:58:36 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env
	*ft_new_env(char *name, char *val, int set)
{
	t_env	*newenv;

	if (!(newenv = (t_env*)malloc(sizeof(*newenv))))
		return (NULL);
	*newenv = (t_env){name, val, set};
	return (newenv);
}

int
	ft_edit_env(char *name, char *newval, t_shell *shell)
{
	t_list	*current;
	t_env	*content;

	if (!newval)
		return (-1);
	current = shell->env;
	while (current)
	{
		content = (t_env*)current->content;
		if (!ft_strncmp(content->name, name, ft_strlen(name)))
		{
			free(content->val);
			content->val = newval;
			return (0);
		}
		current = current->next;
	}
	return (-1);
}

char
	*ft_get_env(char *name, t_shell *shell)
{
	t_list	*current;
	t_env	*content;

	current = shell->env;
	while (current)
	{
		content = (t_env*)current->content;
		if (!ft_strncmp(content->name, name, ft_strlen(name)))
			return (content->val);
		current = current->next;
	}
	return (NULL);
}
