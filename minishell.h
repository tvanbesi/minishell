/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasvanbesien <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:09:24 by thomasvan         #+#    #+#             */
/*   Updated: 2020/12/09 12:21:29 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "get_next_line.h"

// TEMPORARY
#include <stdio.h>
// TEMPORARY

typedef	struct	s_token
{
	int				type;
	char			*s;
	int				qt;
}				t_token;

typedef	enum	e_token_type
{
	WORD,
	OPERATOR,
	METACHAR
}				t_token_type;

typedef	struct	s_parse_data
{
	unsigned int	i;
	size_t			len;
	int				qt;
}				t_parse_data;

typedef	struct	s_shell
{
	char			**env;
}				t_shell;

t_list	*ft_get_tokens(char *line);
t_token	*ft_new_token(int type, char *s, int qt);

int		ft_get_envvaridx(char **env, const char *varname);
char	*ft_get_envvarval(char **env, const char *varname);
char	*ft_mkenvvar(const char *varname, const char *varval);

int		ft_minishell(t_shell *shell);

int		ft_parsing_oquote(t_list **atoken, t_parse_data *pd, char *line);
int		ft_parsing_cquote(t_list **atoken, t_parse_data *pd, char *line);
int		ft_parsing_oper(t_list **atoken, t_parse_data *pd, char *line);
int		ft_parsing_end(t_list **atoken, t_parse_data *pd, char *line);
int		ft_parsing_word(t_list **atoken, char *word);

int		ft_execute(t_list *token, t_shell *shell);

void	ft_builtin(char *cmd, t_list *argv, t_shell *shell);
int		ft_pwd(t_list *argv, t_shell *shell);
int		ft_cd(t_list *argv, t_shell *shell);
int		ft_env(t_list *argv, t_shell *shell);
int		ft_export(t_list *argv, t_shell *shell);

#endif
