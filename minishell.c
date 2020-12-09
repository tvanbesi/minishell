/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasvanbesien <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:09:01 by thomasvan         #+#    #+#             */
/*   Updated: 2020/12/09 12:42:26 by tvanbesi         ###   ########.fr       */
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

void
	ft_puttoken(void *content)
{
	t_token	*token;

	token = (t_token*)content;
	if (token->type == WORD)
		printf("WORD\t\t");
	if (token->type == OPERATOR)
		printf("OPERATOR\t");
	if (token->type == METACHAR)
		printf("METACHAR\t");
	printf("|%s|\n", token->s);
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
		
		ft_lstiter(token, ft_puttoken);

		ft_execute(token, shell);
		//ft_clear_tokens(&tokens);
	}
	return (0);
}
