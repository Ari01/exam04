/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:41:41 by dchheang          #+#    #+#             */
/*   Updated: 2022/01/29 15:55:22 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "microshell.h"

int	main(int ac, char **av, char **envp)
{
	t_list	*cmd_list;

	if (ac < 2)
		return (0);
	cmd_list = NULL;
	cmd_list = get_cmds(av);
	if (cmd_list)
		return (run(cmd_list, envp));
	return (0);
}
