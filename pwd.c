/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:20:05 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/08 17:49:53 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_pwd(t_token *argv, t_shell *shell)
{
	char	*s;

	if (argv || (argv && argv->type == WORD))
	{
		printf("too many arguments\n");
		return (-1);
	}
	if (!(s = ft_get_envvarval(shell->env, "PWD")))
		return (-1);
	ft_putendl_fd(s, 1);
	free(s);
	return (0);
}
