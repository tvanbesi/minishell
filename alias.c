/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:22:45 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/10 12:48:14 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char
	*ft_stradd(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (s);
}

char
	*ft_expand_alias(char *word, t_shell *shell)
{
	char	*s;
	char	*tmp;
	char	*name;
	size_t	i;
	size_t	l;

	if (!(s = ft_strdup("")))
		return (NULL);
	i = 0;
	l = 0;
	while (word[i])
	{
		l++;
		if (word[i] == '$' && (ft_isalnum(word[i + 1]) || word[i + 1] == '_'))
		{
			if (!(tmp = ft_substr(word, i - (l - 1), l - 1)))
				return (NULL);
			if (!(s = ft_stradd(s, tmp)))
				return (NULL);
			i++;
			l = 0;
			while (ft_isalnum(word[i]) || word[i] == '_')
			{
				l++;
				i++;
			}
			if (!(name = ft_substr(word, i - l, l)))
				return (NULL);
			if (!ft_get_env(name, shell))
			{
				if (!(tmp = ft_strdup("")))
					return (NULL);
			}
			else
			{
				if (!(tmp = ft_strdup(ft_get_env(name, shell))))
					return (NULL);
			}
			if (!(s = ft_stradd(s, tmp)))
				return (NULL);
			l = 1;
		}
		i++;
	}
	if (!(tmp = ft_substr(word, i - l, l)))
		return (NULL);
	if (!(s = ft_stradd(s, tmp)))
		return (NULL);
	free(word);
	return (s);
}
