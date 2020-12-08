/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:36:01 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/08 17:22:00 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_cd(t_token *argv, t_shell *shell)
{
	char	*s;
	int		r;

	while (argv && argv->type == METACHAR)
		argv = argv->next;
	if (argv && argv->next && argv->next->type == WORD)
	{
		printf("too many argv\n");
		return (-1);
	}
	if (!argv || (argv && argv->type != WORD))
	{
		printf("where at?\n");
		return (-1);
	}
	else
	{
		if (!argv->qt)
			s = ft_strtrim(argv->s, " \t");
		else
			s = ft_strdup(argv->s);
	}
	r = chdir(s);
	free(s);
	if (r)
		printf("no such file or directory\n");
	else
	{
		//TODO: SHOULD CHANGE PWD ENV VARIABLE CORRECTLY
		free(shell->env[0]);
		shell->env[0] = ft_get_pwdvar();
		//TEMPORARY
	}
	return (r);
}
