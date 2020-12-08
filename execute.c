/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:58:45 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/08 17:06:27 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_execute(t_token *cmd, t_shell *shell)
{
	char	*s;

	//TODO: REMOVE ALL STARTING HT AND SPACES
	// IF TRIM RETURN NULL STRING GO TO NEXT TOKEN

	if (!cmd)
		return (0);
	if (!cmd->qt)
	{
		if (!(s = ft_strtrim(cmd->s, " \t")))
			return (-1);
	}
	else if (!(s = ft_strdup(cmd->s)))
		return (-1);
	ft_builtin(s, cmd->next, shell);
	free(s);
	return (0);
}
