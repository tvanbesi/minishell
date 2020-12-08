/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:18:15 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/08 11:35:57 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int
	ft_isoperator(int c)
{
	return (c == '|' || c == ';' || c == '<' || c == '>');
}

t_token
	*ft_get_tokens(char *line)
{
	t_token			*tokens;
	t_parse_data	pd;

	// TODO: CLEAR AND RETURN NULL IF PARSING RETURNS -1
	tokens = NULL;
	pd = (t_parse_data){0, 0, 0};
	while (line[pd.i])
	{
		pd.len++;
		if (!pd.qt && (line[pd.i] == 34 || line[pd.i] == 39))
		{
			if (ft_parsing_oquote(&tokens, &pd, line) == -1)
				return (NULL);
		}
		else if (!pd.qt && ft_isoperator(line[pd.i]))
		{
			if (ft_parsing_oper(&tokens, &pd, line) == -1)
				return (NULL);
		}
		else if (pd.qt && line[pd.i] == pd.qt)
		{
			if (ft_parsing_cquote(&tokens, &pd, line) == -1)
				return (NULL);
		}
		pd.i++;
	}
	if (pd.len && ft_parsing_end(&tokens, &pd, line) == -1)
		return (NULL);
	// IF PD.QT = 1 ERROR UNCLOSED QUOTE
	return (tokens);
}
