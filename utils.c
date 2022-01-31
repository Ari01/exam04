/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:28:11 by dchheang          #+#    #+#             */
/*   Updated: 2022/01/29 23:40:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back(t_list **head, t_list *list)
{
	t_list	*ite;

	ite = *head;
	if (!ite)
		*head = list;
	else
	{
		while (ite->next)
			ite = ite->next;
		ite->next = list;
	}
}

void	ft_lstdelone(t_list *to_del, void (*del)(void *))
{
	if (to_del)
	{
		if (to_del->content)
			del(to_del->content);
		free(to_del);
	}
}

void	ft_lstclear(t_list **head, void (*del)(void *))
{
	t_list	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		del(tmp->content);
		free(tmp);
	}
}

void	free_cmd(void *content)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)content;
	free(cmd->cmd);
	free(cmd);
}

void	print_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}
