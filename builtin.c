/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:28:11 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/08 12:28:29 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	ft_builtin(char	*cmd, t_token *argv)
{
	if (!ft_strncmp(cmd, "pwd", 4))
		ft_pwd(argv);
	else
		printf("command not found\n");
}
