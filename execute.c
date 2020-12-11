/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:04:49 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/11 10:45:57 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int
	ft_get_argc(t_list *argv)
{
	int		argc;
	t_list	*current;
	t_token	*content;

	argc = 0;
	current = argv;
	while (current)
	{
		content = (t_token*)current->content;
		if (content->type == WORD)
			argc++;
		else if (content->type == OPERATOR)
			break ;
		current = current->next;
	}
	return (argc);
}

static char
	**ft_get_argv(t_list *argv)
{
	char	**r;
	int		l;
	int		i;
	t_list	*current;
	t_token	*content;

	//TODO: Clear all before returning NULL when malloc fails

	l = ft_get_argc(argv);
	if (!l)
	{
		if (!(r = (char**)ft_calloc(3, sizeof(*r))))
			return (NULL);
		if (!(r[0] = ft_strdup("minishell")))
			return (NULL);
		if (!(r[1] = ft_strdup("")))
			return (NULL);
		r[2] = NULL;
		return (r);
	}
	if (!(r = (char**)ft_calloc(l + 2, sizeof(*r))))
		return (NULL);
	if (!(r[0] = ft_strdup("minishell")))
		return (NULL);
	r[l] = NULL;
	current = argv;
	i = 0;
	while (i < l)
	{
		content = (t_token*)current->content;
		if (content->type == WORD)
		{
			if (content->qt && !(r[i + 1] = ft_strdup(content->s)))
				return (NULL);
			else if (!content->qt && !(r[i + 1] = ft_strtrim(content->s, " \t")))
				return (NULL);
			i++;
		}
		current = current->next;
	}
	return (r);
}

static char
	**ft_get_aenv(t_list *env)
{
	char	**r;
	int		l;
	int		i;
	t_list	*current;
	t_env	*content;
	char	*tmp;
	size_t	tmplen;

	//TODO: Clear all before returning NULL when malloc fails

	l = ft_lstsize(env);
	if (!(r = (char**)ft_calloc(l + 1, sizeof(*r))))
		return (NULL);
	r[l] = NULL;
	current = env;
	i = 0;
	while (i < l)
	{
		content = (t_env*)current->content;
		tmplen = ft_strlen(content->name) + ft_strlen(content->val) + 2;
		if (!(tmp = (char*)malloc(tmplen)))
			return (NULL);
		tmp[0] = '\0';
		ft_strlcpy(tmp, content->name, tmplen);
		ft_strlcat(tmp, "=", tmplen);
		ft_strlcat(tmp, content->val, tmplen);
		r[i] = tmp;
		i++;
		current = current->next;
	}
	return (r);
}

void
	ft_free_arr(char **a)
{
	while (*a)
		free(*a++);
}

int
	ft_execute(char *path, t_list *token, t_list *env)
{
	char	**argv;
	char	**envp;
	pid_t	pid;
	int		r;

	//TODO: Doesn't check if directory exits ...

	if (!(argv = ft_get_argv(token)))
		return (-1);
	if (!(envp = ft_get_aenv(env)))
		return (-1);
	pid = fork();
	r = 0;
	if (!pid)
		execve(path, argv, envp);
	else
		waitpid(pid, &r, 0);
	ft_free_arr(argv);
	ft_free_arr(envp);
	return (0);
}
