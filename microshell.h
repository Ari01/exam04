/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:18:10 by dchheang          #+#    #+#             */
/*   Updated: 2022/01/29 16:30:07 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>

//	TYPES
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_cmd
{
	char	**cmd;
	int		flag;
}	t_cmd;

// FUNCS
int		ft_strlen(char *s);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **head, void *content);
void	ft_lstdelone(t_list *to_del, void (*del)(void *));
void	ft_lstclear(t_list **head, void (*del)(void *));

void	print_error(char *msg);
t_list	*get_cmds(char **av);
int		ft_cd(char *path);
int		ft_execve(char *path, char **argv, char **envp);
int		run_pipe(t_list *cmd_list_head, t_list *cmd_list_ite, char **envp);
int		run_simple_cmd(t_list *cmd_list, char **envp);
int		run(t_list *cmd_list, char **envp);

