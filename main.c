/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasvanbesien <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:08:43 by thomasvan         #+#    #+#             */
/*   Updated: 2020/12/09 13:59:13 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list
	*ft_init_env(void)
{
	t_list	*env;
	t_env	*pwd;
	char	*path;

	if (!(path = getcwd(NULL, 0)))
		return (NULL);
	if (!(pwd = ft_new_env("PWD", path, 1)))
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

	//ft_lstiter(shell.env, ft_putenv);

	return (ft_minishell(&shell));
}
