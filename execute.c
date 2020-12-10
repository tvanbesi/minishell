/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:58:45 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/10 10:47:39 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_execute(t_list *token, t_shell *shell)
{
	char	*s;
	t_list	*current;
	t_token	*content;

	//TODO: remove whitespaces at beggining (try |    'echo'  truc|)

	current = token;
	while (current)
	{
		content = (t_token*)current->content;
		if (content->type == WORD)
		{
			if (!content->qt && (!(s = ft_strtrim(content->s, " \t"))))
				return (-1);
			else if (content->qt && (!(s = ft_strdup(content->s))))
				return (-1);
			current = current->next;
			ft_builtin(s, current, shell);
			free(s);
		}
		while (current)
		{
			content = (t_token*)current->content;
			if (content->type == OPERATOR)
			{
				if (content->s[0] == ';')
				{
					current = current->next;
					break;
				}
				else
				{
					printf("unsuported operator\n");
					return (-1);
				}
			}
			current = current->next;
		}
	}
	return (0);
}
