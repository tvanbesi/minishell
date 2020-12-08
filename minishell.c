/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasvanbesien <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:09:01 by thomasvan         #+#    #+#             */
/*   Updated: 2020/12/08 15:20:08 by tvanbesi         ###   ########.fr       */
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
	ft_minishell(char **env)
{
	char	*line;
	t_token	*tokens;

	while (1)
	{
		ft_putstr("> ");
		line = ft_read_line();
		tokens = ft_get_tokens(line);
		free(line);
		
		/*
		t_token	*current;
		current = tokens;
		while (current)
		{
			if (current->type == WORD)
				printf("WORD\t\t");
			else if (current->type == OPERATOR)
				printf("OPERATOR\t");
			else if (current->type == METACHAR)
				printf("METACHAR\t");
			printf("|%s|\n", current->s);
			current = current-> next;
		}
		*/
		
		ft_execute(tokens, env);
		ft_clear_tokens(&tokens);
	}
	return (0);
}
