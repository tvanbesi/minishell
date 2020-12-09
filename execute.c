/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:58:45 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/09 12:56:15 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_execute(t_list *token, t_shell *shell)
{
	char	*s;
	t_token	*content;

	//TODO: REMOVE ALL STARTING HT AND SPACES
	// IF TRIM RETURN NULL STRING GO TO NEXT TOKEN

	if (!token)
		return (0);
	content = (t_token*)(token->content);
	if (!content->qt)
	{
		if (!(s = ft_strtrim(content->s, " \t")))
			return (-1);
	}
	else if (!(s = ft_strdup(content->s)))
		return (-1);
	ft_builtin(s, token->next, shell);
	free(s);
	return (0);
}
