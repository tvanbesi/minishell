/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:17:14 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/08 17:34:24 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t
	ft_get_namelen(char *s)
{
	size_t	r;

	r = 0;
	while (*s)
	{
		if (*s == '=')
			return (r);
		r++;
		s++;
	}
	return (0);
}

char
	*ft_get_envvar(char **env, char *varname)
{
	char	*s;
	size_t	namelen;

	while (*env)
	{
		namelen = ft_get_namelen(*env);
		s = ft_substr(*env, 0, namelen - 1);
		if (!ft_strncmp(s, varname, namelen - 1))
			return (ft_substr(*env, namelen + 1, ft_strlen(*env)));
		free(s);
		env++;
	}
	return (NULL);
}

char
	*ft_get_pwdvar(void)
{
	char	*cwd;
	char	*r;

	if (!(cwd = getcwd(NULL, 0)))
		return (NULL);
	if (!(r = ft_strjoin("PWD=", cwd)))
	{
		free(cwd);
		return (NULL);
	}
	free(cwd);
	return (r);
}

