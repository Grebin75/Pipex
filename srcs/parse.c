/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:05 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/11/09 17:32:23 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	setcmd(char *argv, char *path)
{
	char	**cmd;
	char	*temp;
	t_list	*node;

	cmd = ft_split(argv);
	node = addtolast((t_list **)&this()->cmd ,createnode(cmd[0], cmd));
	while (path)
	{
		temp = strjoin(path, node->cmd[0]);
		if (access(temp, F_OK) != -1)
		{
			node->path = temp;
			break ;
		}
		free(temp);
		path += len(path) + (path[len(path)] == ':');
	}
	/* if (!this()->cmd->path)
		printerror("Command not found", 1); */
}

char	*findpath(char *env, char *str)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (env[i] != str[i])
			break ;
		if (i == 4)
			return (env + i + 1);
	}
	return (NULL);
}

void	parse(char **env, char **argv)
{
	char	*path;
	int		i;

	path = NULL;
	while (!path)
		path = findpath(env[++i], "PATH=");
	printf("%s\n", path);
	i = -1;
	setcmd(argv[2], path);
	printf("%s\n", path);
	setcmd(argv[3], path);
	printf("1: %s\n", this()->cmd->path);
	printf("2: %s\n", this()->cmd->next->path);
}
