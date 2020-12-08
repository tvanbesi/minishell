/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:36:01 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/08 14:46:48 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_cd(t_token *argv, char **env)
{
	char	*s;
	int		r;

	if (argv && argv->next && argv->next->type == WORD)
	{
		printf("too many argv\n");
		return (-1);
	}
	if (!argv || (argv && argv->type != WORD))
		s = ft_strdup(ft_get_envvar(env, "HOME"));
	else
		s = ft_strtrim(argv->s, " \t");
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
