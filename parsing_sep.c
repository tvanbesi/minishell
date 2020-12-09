/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 09:37:29 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/09 12:01:01 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_parsing_oquote(t_list **atoken, t_parse_data *pd, char *line)
{
	char	*s;

	if (pd->len > 1)
	{
		if (!(s = ft_substr(line, pd->i - pd->len + 1, pd->len - 1)))
			return (-1);
		if (ft_parsing_word(atoken, s) == -1)
			return (-1);
	}
	pd->qt = line[pd->i];
	pd->len = 0;
	return (0);
}

int
	ft_parsing_cquote(t_list **atoken, t_parse_data *pd, char *line)
{
	char	*s;
	t_token	*content;
	t_list	*token;

	if (!(s = ft_substr(line, pd->i - pd->len + 1, pd->len - 1)))
		return (-1);
	if (!(content = ft_new_token(WORD, s, 1)))
		return (-1);
	if (!(token = ft_lstnew(content)))
		return (-1);
	ft_lstadd_back(atoken, token);
	pd->qt = 0;
	pd->len = 0;
	return (0);
}

int
	ft_parsing_oper(t_list **atoken, t_parse_data *pd, char *line)
{
	char	*s;
	t_token	*content;
	t_list	*token;

	if (pd->len > 1)
	{
		if (!(s = ft_substr(line, pd->i - pd->len + 1, pd->len - 1)))
			return (-1);
		if (ft_parsing_word(atoken, s) == -1)
			return (-1);
	}
	if (line[pd->i] == '>' && line[pd->i + 1] == '>')
	{
		if (!(s = ft_substr(line, pd->i, 2)))
			return (-1);
		if (!(content = ft_new_token(OPERATOR, s, 0)))
			return (-1);
		if (!(token = ft_lstnew(content)))
			return (-1);
		ft_lstadd_back(atoken, token);
		pd->i++;
	}
	else
	{
		if (!(s = ft_substr(line, pd->i, 1)))
			return (-1);
		if (!(content = ft_new_token(OPERATOR, s, 0)))
			return (-1);
		if (!(token = ft_lstnew(content)))
			return (-1);
		ft_lstadd_back(atoken, token);
		pd->len = 0;
	}
	return (0);
}

int
	ft_parsing_end(t_list **atoken, t_parse_data *pd, char *line)
{
	char	*s;

	if (!(s = ft_substr(line, pd->i - pd->len, pd->len)))
		return (-1);
	if (ft_parsing_word(atoken, s) == -1)
		return (-1);
	return (0);
}
