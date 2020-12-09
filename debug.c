#include "minishell.h"

void
	ft_puttoken(void *content)
{
	t_token	*token;

	token = (t_token*)content;
	if (token->type == WORD)
		printf("WORD\t\t");
	if (token->type == OPERATOR)
		printf("OPERATOR\t");
	if (token->type == METACHAR)
		printf("METACHAR\t");
	printf("|%s|\n", token->s);
}

void
	ft_putenv(void *content)
{
	t_env	*env;

	env = (t_env*)content;
	printf("%s=%s\n", env->name, env->val);
}
