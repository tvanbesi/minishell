/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:28:11 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/11 14:33:18 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	ft_builtin(char	*cmd, t_list *argv, t_shell *shell)
{
	//TODO: return values
	if (!ft_strncmp(cmd, "pwd", 4))
		ft_pwd(argv, shell);
	else if (!ft_strncmp(cmd, "cd", 3))
		ft_cd(argv, shell);
	else if (!ft_strncmp(cmd, "env", 4))
		ft_env(argv, shell);
	else if (!ft_strncmp(cmd, "export", 7))
		ft_export(argv, shell);
	else if (!ft_strncmp(cmd, "unset", 6))
		ft_unset(argv, shell);
	else if (!(ft_strncmp(cmd, "echo", 5)))
		ft_echo(argv, shell);
	else if (!ft_strncmp(cmd, "exit", 5))
		exit(0);
	else if (cmd[0] == '/')
		ft_execute(cmd, argv, shell->env);
	else
		printf("command not found\n");
}
