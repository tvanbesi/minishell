/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:23:53 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/09 11:44:34 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token
	*ft_new_token(int type, char *s, int qt)
{
	t_token	*newtoken;

	if (!(newtoken = (t_token*)malloc(sizeof(*newtoken))))
		return (NULL);
	*newtoken = (t_token){type, s, qt};
	return (newtoken);
}

