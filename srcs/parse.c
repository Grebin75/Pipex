/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:05 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/12/12 17:22:24 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	setcmd(char *argv, char *path)
{
	char	**cmd;
	char	*temp;
	t_list	*node;

	if (!argv[0])
		printerror("Empty cmd", 1);
	cmd = ft_split(argv);
	if (!cmd)
		printerror("Malloc error", 1);
	node = addtolast((t_list **)&this()->cmd, createnode(cmd));
	if (!node)
		printerror("Malloc error", 1);
	while (*path)
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
	if (!node->path)
		printerror("Command not found.", 1);
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

	i = -1;
	path = NULL;
	while (env[++i])
	{
		path = findpath(env[i], "PATH=");
		if (path)
			break ;
	}
	if (!path)
		printerror("Path not found", 1);
	setcmd(argv[2], path);
	(this())->infile = open(argv[1], O_RDONLY);
	if ((this())->infile == -1)
		printerror("Invalid infile", 1);
	setcmd(argv[3], path);
	(this())->outfile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if ((this())->outfile == -1)
		printerror("Invalid infile", 1);
}
