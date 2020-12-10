/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:28:22 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/10 13:08:14 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_parsing_word(t_list **atoken, int qt, char *word, t_shell *shell)
{
	char			*s;
	t_parse_data	pd;
	t_token			*content;
	t_list			*token;

	//TODO: RENAME QT TO T (I.E. TOGGLE) IN T_PARSE_DATA STRUCT

	pd = (t_parse_data){0, 0, 0};
	while (word[pd.i])
	{
		pd.len++;
		if (!pd.qt && !ft_isspht(word[pd.i]))
			pd.qt = 1;
		else if (pd.qt && ft_isspht(word[pd.i]))
		{
			if (!(s = ft_substr(word, pd.i - pd.len + 1, pd.len - 1)))
				return (-1);
			if (qt != 39 && !(s = ft_expand_alias(s, shell)))
				return (-1);
			if (!(content = ft_new_token(WORD, s, 0)))
				return (-1);
			if (!(token = ft_lstnew(content)))
				return (-1);
			ft_lstadd_back(atoken, token);
			pd.qt = 0;
			pd.len = 1;
		}
		pd.i++;
	}
	if (pd.qt)
	{
		if (!(s = ft_substr(word, pd.i - pd.len, pd.len)))
			return (-1);
		if (qt != 39 && !(s = ft_expand_alias(s, shell)))
			return (-1);
		if (!(content = ft_new_token(WORD, s, 0)))
			return (-1);
		if (!(token = ft_lstnew(content)))
			return (-1);
		ft_lstadd_back(atoken, token);
	}
	else if (word[0])
	{
		if (!(s = ft_substr(word, pd.i - pd.len, pd.len)))
			return (-1);
		if (!(content = ft_new_token(METACHAR, s, 0)))
			return (-1);
		if (!(token = ft_lstnew(content)))
			return (-1);
		ft_lstadd_back(atoken, token);
	}
	free(word);
	return (0);
}
