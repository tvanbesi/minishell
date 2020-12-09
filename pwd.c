/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:20:05 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/09 12:56:27 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_pwd(t_list *argv, t_shell *shell)
{
	char	*s;
	
	if (argv && ((t_token*)(argv->content))->type != OPERATOR)
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
