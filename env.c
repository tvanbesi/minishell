/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:10:12 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/09 12:56:03 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_env(t_list *argv, t_shell *shell)
{
	size_t	i;

	if (argv && ((t_token*)(argv->content))->type != OPERATOR)
	{
		printf("too many argv\n");
		return (-1);
	}
	i = 0;
	while (shell->env[i])
		ft_putendl_fd(shell->env[i++], 1);
	return (0);
}
