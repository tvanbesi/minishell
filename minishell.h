/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasvanbesien <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:09:24 by thomasvan         #+#    #+#             */
/*   Updated: 2020/12/08 17:08:31 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "get_next_line.h"

// TEMPORARY
#include <stdio.h>
// TEMPORARY

typedef struct	s_token
{
	int					type;
	char				*s;
	int					qt;
	struct	s_token		*next;
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

t_token	*ft_get_tokens(char *line);
t_token	*ft_new_token(int type, char *s, int qt);
t_token	*ft_get_last_token(t_token *lst);
void	ft_clear_tokens(t_token **atoken);
void	ft_add_token(t_token **atoken, t_token *new);

char	*ft_get_envvar(char **env, char *varname);
char	*ft_get_pwdvar(void);

int		ft_minishell(t_shell *shell);

int		ft_parsing_oquote(t_token **atoken, t_parse_data *pd, char *line);
int		ft_parsing_cquote(t_token **atoken, t_parse_data *pd, char *line);
int		ft_parsing_oper(t_token **atoken, t_parse_data *pd, char *line);
int		ft_parsing_end(t_token **atoken, t_parse_data *pd, char *line);
int		ft_parsing_word(t_token **atoken, char *word);

int		ft_execute(t_token *cmd, t_shell *shell);

void	ft_builtin(char *cmd, t_token *argv, t_shell *shell);
int		ft_pwd(t_token *argv, t_shell *shell);
int		ft_cd(t_token *argv, t_shell *shell);
int		ft_env(t_token *argv, t_shell *shell);
int		ft_export(t_token *argv, t_shell *shell);

#endif
