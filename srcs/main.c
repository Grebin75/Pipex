/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:36:40 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/11/29 15:51:25 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_prog	*this(void)
{
	static t_prog	prog;

	return (&prog);
}

void	printerror(char *s, int status)
{
	if (status == 1 && s)
		ft_printf("%s\n", s);
	if (this()->cmd)
		rmnode((t_list **)&this()->cmd);
	exit(status);
}

int	main(int argc, char **argv, char **env)
{
	/* int i = -1;
	t_cmd *temp; */
	int		pipe_fd[2];
	int		pid;

	(void)argv;
	if (argc != 5)
		printerror ("Wrong number of arguments", 1);
	parse(env, argv);
	if (pipe(pipe_fd) == -1)
		printerror("pipe", 1);
	pid = fork();
	if (pid == -1)
		printerror("fork 1", 1);
	if (pid == 0)
	{
		if (dup2(this()->infile, STDIN_FILENO) == -1)
			printerror("dup2 1", 1);
		close(this()->infile);
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], STDOUT_FILENO))
		printerror("dup2 2", 1);
		close(pipe_fd[1]);
		if (execve(this()->cmd->path, this()->cmd->cmd, env) == -1)
			printerror("execve 1", 1);
	}
	close(this()->infile);
	close(pipe_fd[1]);
	rmnode((t_list **)&this()->cmd);
	pid = fork();
	if (pid == -1)
		printerror("fork 2", 1);
	if (pid == 0)
	{
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			printerror("dup2 3", 1);
		close(pipe_fd[0]);
		if (dup2(this()->outfile, STDOUT_FILENO) == -1)
		printerror("dup2 4", 1);
		close(this()->outfile);
		if (execve(this()->cmd->path, this()->cmd->cmd, env) == -1)
			printerror("execve 2", 1);
	}
	/* temp = this()->cmd->next;
	while (temp->cmd[++i])
		printf("%s\n" , temp->cmd[i]); */
	printerror(NULL, 0);
}
