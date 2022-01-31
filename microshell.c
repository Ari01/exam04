/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:41:41 by dchheang          #+#    #+#             */
/*   Updated: 2022/01/29 19:01:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "microshell.h"

void	print_cmds(t_list *list)
{
	int		i;
	int		j;
	t_cmd	*cmd;

	j = 0;
	while (list)
	{
		i = 0;
		cmd = (t_cmd *)(list->content);
		printf("cmd[%d]\n", j);
		while (cmd->cmd[i])
		{
			printf("%s ", cmd->cmd[i]);
			i++;
		}
		printf("\nflag = %c\n", cmd->flag);
		list = list->next;
		j++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_list	*cmd_list;

	(void)envp;
	if (ac < 2)
		return (0);
	cmd_list = NULL;
	cmd_list = get_cmds(av);
	print_cmds(cmd_list);
	ft_lstclear(&cmd_list, &free_cmd);
	//if (cmd_list)
	//	return (run(cmd_list, envp));
	return (0);
}
