#include "minishell.h"
#include "libft.h"

/* static int	is_int(char *str)
{
	long long comp;

	//atoli
	comp = ft_atoli(str);
	if (comp > LLONG_MAX || comp < LLONG_MIN)
		return (1);
	return (0);
} */
/* 
int exit_sh(char **args, int *exit_code)
{
	if (args[1])
	{
		if (is_int(args[1]))
		{
			ft_printf_fd(2, "exit\n");
			ft_printf_fd(2, "bash: exit: %s: numeric argument required\n", args[1]);
			exit(255);
		}
		else if (ft_arraylen(args) > 2)
		{
			ft_printf_fd(2, "minishell: exit: too many arguments\n");
			*exit_code = 1;
			return (1);
		}
		ft_printf_fd(2, "exit\n");
		exit(ft_atoi(args[1]));
	}
	ft_printf_fd(2, "exit\n");
	exit(*exit_code);
} */
