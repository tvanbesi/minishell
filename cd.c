/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:36:01 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/08 15:30:55 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_cd(t_token *argv, char **env)
{
	char	*s;
	int		r;

	//TODO: SHOULD CHANGE PWD ENV VARIABLE (SEE PWD TODO)
	while (argv && argv->type == METACHAR)
		argv = argv->next;
	if (argv && argv->next && argv->next->type == WORD)
	{
		printf("too many argv\n");
		return (-1);
	}
	if (!argv || (argv && argv->type != WORD))
		s = ft_strdup(ft_get_envvar(env, "HOME"));
	else
	{
		if (!argv->qt)
			s = ft_strtrim(argv->s, " \t");
		else
			s = ft_strdup(argv->s);
	}
	if (!ft_strncmp(s, "~", 2))
	{
		free(s);
		s = ft_strdup(ft_get_envvar(env, "HOME"));
	}
	r = chdir(s);
	free(s);
	if (r)
		printf("no such file or directory\n");
	return (r);
}
