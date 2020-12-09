#include "minishell.h"

void
	ft_puttoken(void *content)
{
	t_token	*token;

	token = (t_token*)content;
	if (token->qt)
		printf("QUOTED\t\t");
	else
		printf("UNQUOTED\t");
	if (token->type == WORD)
		printf("WORD\t\t");
	else if (token->type == OPERATOR)
		printf("OPERATOR\t");
	else if (token->type == METACHAR)
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
