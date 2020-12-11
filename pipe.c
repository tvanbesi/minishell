/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:41:04 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/11 14:39:35 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	ft_pipe(t_list *token, t_shell *shell)
{
	pid_t	pid;
	int		fd[2];
	int		r;
	char	*cmd;
	t_list	*current;
	t_token	*content;

	// literally nothing is protected here
	// all bets are off lol
	//TODO: do a cmd generator for here and ft_builtin input in other files
	//even better do it while parsing...

	r = 0;
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		current = token;
		content = (t_token*)current->content;
		cmd = content->qt ? ft_strdup(content->s) : ft_strtrim(content->s, " \t");
		ft_builtin(cmd, current->next, shell);
		free(cmd);
		return ;
	}
	else
	{
		waitpid(pid, &r, 0);
		close(fd[1]);
		dup2(fd[0], 0);
		current = token;
		while (current)
		{
			content = (t_token*)current->content;
			if (content->type == OPERATOR)
				break ;
			current = current->next;
		}
		current = current->next;
		content = (t_token*)current->content;
		cmd = content->qt ? ft_strdup(content->s) : ft_strtrim(content->s, " \t");
		ft_builtin(cmd, current->next, shell);
		free(cmd);
	}
}
