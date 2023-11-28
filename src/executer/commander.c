#include "executer.h"

int		exec_childs(t_minishell *shell, t_fdp *fdp)
{
    fdp->pid[fdp->i] = fork();
	if (fdp->pid[fdp->i] == 0)
    {
        exec_cmnds(fdp, shell, fdp->paths, shell->cmnd_list);
    }
    close_fds(fdp);
    return (0);
}