/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:17:14 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/09 09:52:30 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Returns the idx of env var named varname, -1 if it doesn't exist
*/

int
	ft_get_envvaridx(char **env, const char *varname)
{
	int		i;
	size_t	l;

	i = 0;
	l = ft_strlen(varname);
	while (env[i])
	{
		if (!ft_strncmp(varname, env[i], l) && env[i][l] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char
	*ft_get_envvarval(char **env, const char *varname)
{
	int		i;
	char	*r;

	if ((i = ft_get_envvaridx(env, varname)) == -1)
		return (NULL);
	r = ft_strchr(env[i], '=');
	return (ft_strdup(r + 1));
}

/*
**	varname should include '='
*/

char
	*ft_mkenvvar(const char *varname, const char *varval)
{
	char	*r;
	size_t	l;

	l = ft_strlen(varname) + ft_strlen(varval) + 1;
	if (!(r = (char*)malloc(l)))
		return (NULL);
	ft_strlcpy(r, varname, l);
	ft_strlcat(r, varval, l);
	return (r);
}
