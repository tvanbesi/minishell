/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasvanbesien <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:09:24 by thomasvan         #+#    #+#             */
/*   Updated: 2020/12/09 16:20:05 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "get_next_line.h"

// TEMPORARY
#include <stdio.h>
// TEMPORARY

typedef	struct		s_shell
{
	t_list			*env;
}					t_shell;

typedef	struct		s_env
{
	char			*name;
	char			*val;
	int				set;
}					t_env;

typedef	enum		e_token_type
{
	WORD,
	OPERATOR,
	METACHAR
}					t_token_type;

typedef	struct		s_token
{
	int				type;
	char			*s;
	int				qt;
}					t_token;

typedef	struct		s_parse_data
{
	unsigned int	i;
	size_t			len;
	int				qt;
}					t_parse_data;

t_list	*ft_get_tokens(char *line);
t_token	*ft_new_token(int type, char *s, int qt);
t_env	*ft_new_env(char *name, char *val, int set);
int		ft_edit_env(char *name, char *newval, t_shell *shell);
char	*ft_get_env(char *name, t_shell *shell);
void	ft_remove_env(char *name, t_shell *shell);

int		ft_minishell(t_shell *shell);

int		ft_parsing_oquote(t_list **atoken, t_parse_data *pd, char *line);
int		ft_parsing_cquote(t_list **atoken, t_parse_data *pd, char *line);
int		ft_parsing_oper(t_list **atoken, t_parse_data *pd, char *line);
int		ft_parsing_end(t_list **atoken, t_parse_data *pd, char *line);
int		ft_parsing_word(t_list **atoken, char *word);
int		ft_parsing_equalquote(t_list **atoken, t_parse_data *pd, char *line);

int		ft_execute(t_list *token, t_shell *shell);

void	ft_builtin(char *cmd, t_list *argv, t_shell *shell);
int		ft_pwd(t_list *argv, t_shell *shell);
int		ft_cd(t_list *argv, t_shell *shell);
int		ft_env(t_list *argv, t_shell *shell);
int		ft_export(t_list *argv, t_shell *shell);
int		ft_unset(t_list *argv, t_shell *shell);

//DEBUGGING
void	ft_puttoken(void *content);
void	ft_putenv(void *content);
//DEBUGGING

#endif
