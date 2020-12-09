/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasvanbesien <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:08:43 by thomasvan         #+#    #+#             */
/*   Updated: 2020/12/09 09:49:50 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char
	**ft_init_env(void)
{
	char	**r;
	char	*path;

	if (!(r = ft_calloc(2, sizeof(*r))))
		return (NULL);
	if (!(path = getcwd(NULL, 0)))
		return (NULL);
	if (!(r[0] = ft_mkenvvar("PWD=", path)))
		return (NULL);
	free(path);
	r[1] = NULL;
	return (r);
}

static int
	ft_init_shell(t_shell *shell)
{
	if (!(shell->env = ft_init_env()))
		return (-1);
	return (0);
}

int
	main(void)
{
	t_shell	shell;

	if (ft_init_shell(&shell) == -1)
	{
		printf("error\n");
		return (-1);
	}
	return (ft_minishell(&shell));
}
