/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:56:37 by dchheang          #+#    #+#             */
/*   Updated: 2022/01/29 18:28:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	is_flag(char *s)
{
	int	len;

	len = ft_strlen(s);
	return (!strncmp(s, "|", len) || !strncmp(s, ";", len));
}

int	get_flag(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (!strncmp(s, "|", len))
		return ('|');
	if (!strncmp(s, ";", len))
		return (';');
	return (0);
}

t_cmd	*new_cmd(char **av, int len)
{
	t_cmd	*cmd;
	int		i;

	cmd = malloc(sizeof(*cmd));
	cmd->cmd = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (i < len)
	{
		printf("av %d = %s\n", i, av[i]);
		cmd->cmd[i] = av[i];
		i++;
	}
	cmd->cmd[i] = 0;
	cmd->flag = get_flag(av[i]);
	return (cmd);
}

t_list	*get_cmds(char **av)
{
	t_list	*list;
	t_cmd	*cmd;
	int		i;
	int		start;

	list = NULL;
	i = 1;
	while (av[i])
	{
		start = i;
		while (av[i] && !(is_flag(av[i])))
			i++;
		if (i != start)
			cmd = new_cmd(&av[start], i - start);
		ft_lstadd_back(&list, ft_lstnew(cmd));
		if (av[i])
			i++;
	}
	return (list);
}
