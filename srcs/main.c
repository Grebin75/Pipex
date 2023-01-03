/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:36:40 by hcoutinh          #+#    #+#             */
/*   Updated: 2023/01/03 12:15:39 by hcoutinh         ###   ########.fr       */
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
		rmlist((t_list **)&this()->cmd);
	exit(status);
}

void	forks(char **env, int infile, int outfile)
{
	int			pid;

	pid = fork();
	if (pid == -1)
		printerror("Error creating second fork", 1);
	if (pid == 0)
	{
		if (dup2(infile, STDIN_FILENO) == -1)
			printerror("Error on first Dup2", 1);
		close(infile);
		if (dup2(outfile, STDOUT_FILENO) == -1)
			printerror("Error on second Dup2", 1);
		close(outfile);
		if (execve(this()->cmd->path, this()->cmd->cmd, env) == -1)
			printerror("Error executing command", 1);
	}
	close(outfile);
	close(infile);
	rmnode((t_list **)&this()->cmd);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];

	if (argc != 5)
		printerror ("Wrong number of arguments", 1);
	this()->cmd = NULL;
	parse(env, argv);
	if (pipe(pipe_fd) == -1)
		printerror("Error creating pipe", 1);
	forks(env, this()->infile, pipe_fd[1]);
	forks(env, pipe_fd[0], this()->outfile);
	wait(NULL);
	printerror(NULL, 0);
}
