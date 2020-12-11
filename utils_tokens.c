/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:23:53 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/11 13:57:06 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token
	*ft_get_nextoper(t_list *token)
{
	t_list	*current;
	t_token	*content;

	current = token;
	while (current)
	{
		content = (t_token*)current->content;
		if (content->type == OPERATOR)
			return (content);
		current = current->next;
	}
	return (NULL);
}

t_token
	*ft_new_token(int type, char *s, int qt)
{
	t_token	*newtoken;

	if (!(newtoken = (t_token*)malloc(sizeof(*newtoken))))
		return (NULL);
	*newtoken = (t_token){type, s, qt};
	return (newtoken);
}

