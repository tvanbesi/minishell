/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:36:01 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/09 12:55:44 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_cd(t_list *argv, t_shell *shell)
{
	char	*s;
	int		r;
	int		i;
	t_token	*content;

	if (argv && ((t_token*)(argv->content))->type == METACHAR)
		argv = argv->next;
	if (argv && argv->next && ((t_token*)(argv->next->content))->type != OPERATOR)
	{
		printf("too many argv\n");
		return (-1);
	}
	content = (t_token*)argv->content;
	if (!argv || (argv && content->type != WORD))
	{
		printf("where at?\n");
		return (-1);
	}
	else
	{
		if (!content->qt)
			s = ft_strtrim(content->s, " \t");
		else
			s = ft_strdup(content->s);
	}
	r = chdir(s);
	free(s);
	if (r)
		printf("no such file or directory\n");
	else
	{
		i = ft_get_envvaridx(shell->env, "PWD");
		free(shell->env[i]);
		//TODO: ? Could create error if malloc fails, directory will change but 
		//PWD won't be set and error will be returned. Will get through defense
		//but isn't properly protected.
		if (!(s = getcwd(NULL, 0)))
			return (-1);
		if (!(shell->env[i] = ft_mkenvvar("PWD=", s)))
			return (-1);
	}
	return (r);
}
