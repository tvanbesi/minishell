/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:09:51 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/10 09:50:25 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_echo(t_list *argv, t_shell *shell)
{
	t_list	*current;
	t_token	*content;
	int		nl;
	char	*s;
	int		metachar;

	current = argv;
	if (!current)
		ft_putendl_fd("", 1);
	nl = 1;
	metachar = 0;
	content = (t_token*)current->content;
	if (content->type == OPERATOR)
	{
		ft_putchar_fd('\n', 1);
		return (0);
	}
	else if (content->type == METACHAR)
		current = current->next;
	content = (t_token*)current->content;
	if (!content->qt && !(s = ft_strtrim(content->s, " \t")))
		return (-1);
	else if (content->qt && !(s = ft_strdup(content->s)))
		return (-1);
	if (!(ft_strncmp("-n", s, 3)))
		nl = 0;
	else
		ft_putstr_fd(s, 1);
	free(s);
	current = current->next;
	while (current)
	{
		content = (t_token*)current->content;
		if (content->type == WORD)
		{
			if (!(content->qt && !metachar))
				ft_putchar_fd(' ', 1);
			metachar = 0;
			if (!content->qt && !(s = ft_strtrim(content->s, " \t")))
				return (-1);
			else if (content->qt && !(s = ft_strdup(content->s)))
				return (-1);
			ft_putstr_fd(s, 1);
			free(s);
		}
		else if (content->type == METACHAR)
			metachar = 1;
		else if (content->type == OPERATOR)
		{
			if (nl)
				ft_putchar_fd('\n', 1);
			return (0);
		}
		current = current->next;
	}
	if (nl)
		ft_putchar_fd('\n', 1);
	return (0);
}
