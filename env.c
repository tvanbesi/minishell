/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:10:12 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/08 15:17:39 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_env(t_token *argv, char **env)
{
	if (argv && argv->type == WORD)
	{
		printf("too many argv\n");
		return (-1);
	}
	while (*env)
		ft_putendl_fd(*env++, 1);
	return (0);
}
