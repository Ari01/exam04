/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:10:38 by user42            #+#    #+#             */
/*   Updated: 2022/01/31 18:39:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	ft_execve(char *path, char **argv, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		print_error(FATAL);
		return (-1);
	}
	
}

void	run_simple_cmd(t_cmd *cmd, char **envp)
{
	if (!strncmp(cmd->cmd[0], "cd"))
		ft_cd(cmd);
	else
		ft_execve(cmd->cmd[0], cmd->cmd, envp);
}

void	run(t_list *cmd_list, char **envp)
{
	t_cmd	*cmd;

	while (cmd_list)
	{
		cmd = (t_cmd *)cmd_list->content;
		if (cmd->flag == ';' || !cmd->flag)
			run_simple_cmd(cmd, envp);
		cmd_list = cmd_list->next;
	}
}
