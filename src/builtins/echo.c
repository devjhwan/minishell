#include "minishell.h"
#include "libft.h"

static int is_n(char *str)
{
	if (!ft_strncmp(str, "-n", 3))
		return (1);
	return (0);
}

int echo(char **args)
{
	int	i;

	i = 1;
	if (args[1] == NULL)
	{
		printf ("\n");
		return (0);
	}
	while (args[i] && is_n(args[i]))
		i++;
	while (args[i])
		printf("%s ", args[i++]);
	if (is_n(args[1]) == 0)
		printf ("\n");
	return (0);
}