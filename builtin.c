/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:28:11 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/08 17:08:58 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	ft_builtin(char	*cmd, t_token *argv, t_shell *shell)
{
	if (!ft_strncmp(cmd, "pwd", 4))
		ft_pwd(argv, shell);
	else if (!ft_strncmp(cmd, "cd", 3))
		ft_cd(argv, shell);
	else if (!ft_strncmp(cmd, "env", 4))
		ft_env(argv, shell);
	else if (!ft_strncmp(cmd, "export", 7))
		ft_env(argv, shell);
	else
		printf("command not found\n");
}
