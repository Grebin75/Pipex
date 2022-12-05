/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:50:11 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/12/05 15:41:19 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "./lists.h"
# include "../printf/ft_printf.h"

typedef struct s_prog	t_prog;
typedef struct s_cmd	t_cmd;

struct s_prog{
	int		infile;
	int		outfile;
	t_cmd	*cmd;
};

struct	s_cmd{
	char	*path;
	char	**cmd;
	t_cmd	*next;
} ;

void	forks(char **env, int infile, int outfile);
int		len(char *str);
char	*strjoin(char *s1, char *s2);
char	**ft_split(char *s);
t_prog	*this(void);
void	parse(char **env, char **argv);
void	printerror(char *s, int status);
#endif
