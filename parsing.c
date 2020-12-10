/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:18:15 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/10 13:14:10 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int
	ft_isoperator(int c)
{
	return (c == '|' || c == ';' || c == '<' || c == '>');
}

t_list
	*ft_get_tokens(char *line, t_shell *shell)
{
	t_list			*token;
	t_parse_data	pd;

	//TODO: CLEAR AND RETURN NULL IF PARSING RETURNS -1
	//AND put error message somewhere to differenciate
	//between no token and error in parsing (rn both
	//return null ...
	token = NULL;
	pd = (t_parse_data){0, 0, 0};
	while (line[pd.i])
	{
		pd.len++;
		if (!pd.qt && (line[pd.i] == 34 || line[pd.i] == 39))
		{
			if (pd.i > 0 && line[pd.i - 1] == '=')
				ft_parsing_equalquote(&token, &pd, line, shell);
			else if (ft_parsing_oquote(&token, &pd, line, shell) == -1)
				return (NULL);
		}
		else if (!pd.qt && ft_isoperator(line[pd.i]))
		{
			if (ft_parsing_oper(&token, &pd, line, shell) == -1)
				return (NULL);
		}
		else if (pd.qt && line[pd.i] == pd.qt)
		{
			if (ft_parsing_cquote(&token, &pd, line, shell) == -1)
				return (NULL);
		}
		pd.i++;
	}
	if (pd.len && ft_parsing_end(&token, &pd, line, shell) == -1)
		return (NULL);
	//TODO: IF PD.QT != 0 ERROR UNCLOSED QUOTE
	return (token);
}
