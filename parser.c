/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:56:37 by dchheang          #+#    #+#             */
/*   Updated: 2022/01/29 16:57:17 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	get_flag(char *s)
{
	int	len;

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
		cmd->cmd[i] = av[i];
		i++;
	}
	cmd->cmd[i] = 0;
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
		while (av[i] && !(get_flag(av[i])))
			i++;
		if (i != start)
			cmd = new_cmd(&av[start], i - start);

	}
}
