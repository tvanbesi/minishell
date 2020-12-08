/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:23:53 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/08 12:04:02 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token
	*ft_new_token(int type, char *s, int qt)
{
	t_token	*newtoken;

	if (!(newtoken = (t_token*)malloc(sizeof(*newtoken))))
		return (NULL);
	*newtoken = (t_token){type, s, qt, NULL};
	return (newtoken);
}

t_token
	*ft_get_last_token(t_token *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void
	ft_add_token(t_token **atoken, t_token *newtoken)
{
	t_token	*lasttoken;

	lasttoken = ft_get_last_token(*atoken);
	if (!lasttoken)
		*atoken = newtoken;
	else
		lasttoken->next = newtoken;
}

void
	ft_clear_tokens(t_token **atoken)
{
	t_token	*current;
	t_token	*tmp;

	current = *atoken;
	while (current)
	{
		free(current->s);
		tmp = current;
		current = current->next;
		free(tmp);
	}
}
