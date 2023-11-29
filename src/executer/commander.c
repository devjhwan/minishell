#include "executer.h"

/* void	exec_childs(t_fdp *fdp, t_minishell *shell, t_cmnd *cmnds)
{
	char	**path;

	path = init
} */

void	exec_childs(t_fdp *fdp, t_minishell *shell, t_cmnd *cmnds)
{
	char	*path;

	(void)path;
	if (fdp->i == 0)
	{
        //fprintf(stderr, "entro en first con cmnd: %s\n");
		first_cmnd(fdp, cmnds, shell);
	}
	else if (fdp->cmnd_cnt >= 3 && fdp->i + 1 != fdp->cmnd_cnt)
	{
        //fprintf(stderr, "entro en middle con cmnd: %s\n");
		middle_cmnd(fdp, cmnds, shell);
	}
	else if (fdp->i > 0 && fdp->i + 1 == fdp->cmnd_cnt)
	{
        //fprintf(stderr, "entro en final con cmnd: %s\n");
		final_cmnd(fdp, cmnds, shell);
	}
}



