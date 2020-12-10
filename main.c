/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasvanbesien <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:08:43 by thomasvan         #+#    #+#             */
/*   Updated: 2020/12/10 13:11:12 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list
	*ft_init_env(void)
{
	t_list	*env;
	t_env	*pwd;
	char	*path;
	char	*name;

	if (!(path = getcwd(NULL, 0)))
		return (NULL);
	if (!(name = ft_strdup("PWD")))
		return (NULL);
	if (!(pwd = ft_new_env(name, path, 1)))
		return (NULL);
	if (!(env = ft_lstnew(pwd)))
		return (NULL);
	return (env);
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
	//TEST
	//printf("|%s|\n", ft_expand_alias(ft_strdup("abcde$PWD"), &shell));
	//TEST
	return (ft_minishell(&shell));
}
