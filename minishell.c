/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasvanbesien <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:09:01 by thomasvan         #+#    #+#             */
/*   Updated: 2020/12/09 17:52:16 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char
	*ft_read_line(void)
{
	char	*line;
	char	*r;
	int		gnl;

	r = NULL;
	while ((gnl = get_next_line(0, &line)) > 0)
	{
		r = ft_strdup(line);
		free(line);
	}
	free(line);
	return (r);
}


int
	ft_minishell(t_shell *shell)
{
	char	*line;
	t_list	*token;

	while (1)
	{
		ft_putstr("> ");
		line = ft_read_line();
		token = ft_get_tokens(line);
		free(line);
		//ft_lstiter(token, ft_puttoken);
		ft_execute(token, shell);
		// CLEAR TOKENS
	}
	return (0);
}
